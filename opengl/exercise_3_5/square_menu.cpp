#include <GLUT/glut.h>
#include <stdlib.h>

int ww = 500;
int wh = 500;
GLfloat size = 3.0;

void myInit()
{
	glViewport(0,0,ww,wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,0.0,0.0);
}

void myReshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glViewport(0,0,w,h);

	ww = w;
	wh = h;
}

void drawSquare(int x, int y)
{
	y = wh - y;
	glBegin(GL_POLYGON);
	glVertex2f(x+size, y+size);
	glVertex2f(x-size, y+size);
	glVertex2f(x-size, y-size);
	glVertex2f(x+size, y-size);
	glEnd();
	glFlush();
}

void myMouse(int button, int state, int x, int y)
{

}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void demo_menu(int id)
{
	switch(id)
	{
		case 1: exit(0);
		break;
		case 2: size = 2*size;
		break;
		case 3: if(size > 1) size = size/2;
		break;
	}
	// glutPostRedisplay();
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(ww, wh);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("square");
	myInit();
	glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	glutMotionFunc(drawSquare);
	glutDisplayFunc(myDisplay);
	glutCreateMenu(demo_menu);
	glutAddMenuEntry("quit", 1);
	glutAddMenuEntry("increase square size", 2);
	glutAddMenuEntry("decrease square size", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}