#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>

int n = 5;
GLfloat v[3][2] = {{0.0,0.0},{25.0,50.0},{50.0, 0.0}};
bool canDraw = false;
void triangle(GLfloat *a, GLfloat*b, GLfloat*c)
{
    glBegin(GL_LINE_LOOP);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int k)
{
    GLfloat ab[2], ac[2], bc[2];
    int j;
    if (k > 0) {
        /*计算各边中点*/
        for(j = 0; j < 2; j++) ab[j] = (a[j]+b[j])/2;
        for(j = 0; j < 2; j++) ac[j] = (a[j]+c[j])/2;
        for(j = 0; j < 2; j++) bc[j] = (b[j]+c[j])/2;
        
        /*继续细分小三角形，除了中间那个小三角形*/
        divide_triangle(a, ab, ac, k-1);
        divide_triangle(c, ac, bc, k-1);
        divide_triangle(b, bc, ab, k-1);
    }
    else triangle(a,b,c); /*在递归结束时绘制三角形*/
}

void mouseCb(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP) {
			canDraw = true;
			glutPostRedisplay();
		}
	}

	if (button == GLUT_MIDDLE_BUTTON) {
		if (state == GLUT_UP) {
			exit(0);
		}
	}

	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_UP) {
			canDraw = false;
			glutPostRedisplay();
		}
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glFlush();
	if (!canDraw) return;
	glColor3f(0.0, 0.0, 0.0);
    divide_triangle(v[0], v[1], v[2], n);
    glFlush();
}

void myReshape(int w, int h)
{
	glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-50.0, 50.0, -50.0*(GLfloat)h/(GLfloat)w, 50.0*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-50.0*(GLfloat)w/(GLfloat)h, 50.0*(GLfloat)w/(GLfloat)h, -50.0, 50.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Interact Gasket");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouseCb);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}