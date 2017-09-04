#include <stdio.h>
#include <GLUT/GLUT.h>

void display()
{

}
int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("maze");
	glutDisplayFunc(display);
	glClearColor(1.0,1.0,1.0,1.0);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
	glutMainLoop();
	return 0;
}