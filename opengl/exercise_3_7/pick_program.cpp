#include <stdlib.h>
#include <stdio.h>
#include <GLUT/glut.h>
#include <png.h>
#include <pngconf.h>
#include <zlib.h>
#include <zconf.h>
#pragma comment(lib, "png.lib")
#pragma comment(lib, "zlib.lib")

float width = 200.0f;
float height = 200.0f;

GLuint redTexId = 0;
GLuint whiteTexId = 0;

typedef struct {
	GLsizei width;
	GLsizei height;
	GLenum format;
	GLint internalFormat;
	GLuint id;
	GLubyte *texels;
}gl_texture_t;

void GetPNGtextureInfo(int color_type, gl_texture_t *texinfo)
{
	switch(color_type)
	{
		case PNG_COLOR_TYPE_GRAY: {
			texinfo->format = GL_LUMINANCE;
			texinfo->internalFormat = 1;
			break;
		}

		case PNG_COLOR_TYPE_GRAY_ALPHA: {
			texinfo->format = GL_LUMINANCE_ALPHA;
			texinfo->internalFormat = 2;
			break;
		}

		case PNG_COLOR_TYPE_RGB: {
			texinfo->format = GL_RGB;
			texinfo->internalFormat = 3;
			break;
		}

		case PNG_COLOR_TYPE_RGB_ALPHA: {
			texinfo->format = GL_RGBA;
			texinfo->internalFormat = 4;
		}

		default:
			break;
	}
}

static gl_texture_t *ReadPNGFromFile(const char*filename)
{
	gl_texture_t *texinfo;
	png_byte magic[8];
	png_structp png_ptr;
	png_infop info_ptr;
	int bit_depth, color_type;
	FILE *fp = NULL;
	png_bytep *row_pointers = NULL;
	png_uint_32 w, h;
	int i;

	fp = fopen(filename, "rb");
	if (!fp) {
		fprintf(stderr, "error:couldn't open \" %s \"!\n", filename);
		return NULL;
	}

	fread(magic, 1, sizeof(magic), fp);
	if (!png_check_sig(magic, sizeof(magic))) 
	{
		fprintf(stderr, "error: \"%s\" is not a valid PNG image!\n", filename);
		fclose(fp);
		return NULL;
	}
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		fclose(fp);
		return NULL;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		fclose(fp);
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return NULL;
	}

	texinfo = (gl_texture_t *)malloc(sizeof(gl_texture_t));

	if (setjmp(png_jmpbuf(png_ptr)))
	{
		fclose(fp);
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		if (row_pointers) free(row_pointers);
		if (texinfo){
			if (texinfo->texels)
				free(texinfo->texels);
			free(texinfo);
		}
		return NULL;
	}

	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, sizeof(magic));
	png_read_info(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	if (color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png_ptr);
	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png_ptr);
	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png_ptr);
	if (bit_depth == 16) png_set_strip_16(png_ptr);
	else if (bit_depth < 8) png_set_packing(png_ptr);

	png_read_update_info(png_ptr, info_ptr);

	png_get_IHDR(png_ptr, info_ptr, &w, &h, &bit_depth, &color_type, NULL, NULL, NULL);
	texinfo->width = w;
	texinfo->height = h;
	GetPNGtextureInfo(color_type, texinfo);

	texinfo->texels = (GLubyte *)malloc(sizeof(GLubyte)*texinfo->width*texinfo->height*texinfo->internalFormat);

	row_pointers = (png_bytep *)malloc(sizeof(png_bytep)*texinfo->height);

	for (i = 0; i < texinfo->height; ++i)
	{
		row_pointers[i] = (png_bytep)(texinfo->texels + ((texinfo->height-(i+1))*texinfo->width*texinfo->internalFormat));
	}

	png_read_image(png_ptr, row_pointers);
	png_read_end(png_ptr, NULL);
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	free(row_pointers);
	fclose(fp);

	return texinfo;
}

GLuint loadPNGTexture(const char *filename)
{
	gl_texture_t *png_tex = NULL;
	GLuint tex_id = 0;

	png_tex = ReadPNGFromFile(filename);

	if (png_tex && png_tex->texels) {
		glGenTextures(1, &png_tex->id);
		glBindTexture(GL_TEXTURE_2D, png_tex->id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, png_tex->internalFormat, png_tex->width, png_tex->height, 0, png_tex->format, GL_UNSIGNED_BYTE, png_tex->texels);

		tex_id = png_tex->id;

		free(png_tex->texels);
		free(png_tex);
	}

	return tex_id;
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);

	if (redTexId == 0)
	{
		redTexId = loadPNGTexture("res/red.png");
	}
	printf("texId %d\n", redTexId);
}

void drawChess()
{

}

void drawChessBoard()
{
	bool flag = false;
	for (int i = 0; i < 8; i++) {
		flag = !flag;
		for (int j = 0; j < 8; j++) {
			if (flag) {
				glColor3f(1.0,1.0,1.0);
				flag = false;
			}
			else {
				glColor3f(0.0,0.0,0.0);
				flag = true;
			}
			glRectf(-width/2+j*width/8, height/2 - (i+1)*height/8, -width/2 + (j+1)*width/8, height/2 - i*height/8);
		}
	}
}

void drawObjects(GLenum mode)
{
	if (mode == GL_SELECT) glLoadName(1);
	glColor3f(1.0,0.0,0.0);
	glRectf(-0.5, -0.5, 1.0, 1.0);
	if (mode == GL_SELECT) glLoadName(2);
	glColor3f(0.0,0.0,1.0);
	glRectf(-1.0,-1.0,0.5,0.5);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// drawObjects(GL_RENDER);
	drawChessBoard();
	drawChess();
	glFlush();
}

void processHits(GLint hits, GLuint buffer[])
{
	unsigned int i, j;
	GLuint ii, jj, names, *ptr;

	printf("hits = %d\n", hits);
	ptr = (GLuint *) buffer;
	for (i = 0; i < hits; i++) {
		names = *ptr;
		ptr += 3;
		for (j = 0; j < names; j++)
		{
			if (*ptr == 1) printf("red rectangle\n");
			else printf("blue rectangle\n");
			ptr++;
		}
		printf("\n");
	}
}

#define SIZE 512

void mouse(int button, int state, int x, int y)
{
	GLuint selectBuf[SIZE];
	GLint hits;
	GLint viewport[4];

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glGetIntegerv(GL_VIEWPORT, viewport);
		glSelectBuffer(SIZE, selectBuf);
		glRenderMode(GL_SELECT);
		glInitNames();
		glPushName(0);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3]-y),5.0,5.0,viewport);
		gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
		drawObjects(GL_SELECT);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glFlush();

		hits = glRenderMode(GL_RENDER);
		processHits(hits, selectBuf);

		glutPostRedisplay();
	}
}

void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width/2, width/2, -height/2, height/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}