#include <GLUT/glut.h>


void mouse(int button, int state, int x, int y)
{
	
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Glide Bar");
	glClearColor(1.0,1.0,1.0,1.0);
	glutMouseFunc(mouse);
	glutMainLoop();
}