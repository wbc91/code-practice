#include <stdio.h>
#include <GLUT/glut.h>
float origin = 0.0;
float width = 50.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	float vctPnt[][2] = {
		{origin, origin},
		{origin+width, origin},
		{origin+2*width, origin},
		{origin+3*width, origin},
		{origin, origin+width},
		{origin+width, origin+width},
		{origin+2*width, origin+width},
		{origin+3*width, origin+width},
		{origin, origin+2*width},
		{origin+width, origin+2*width},
		{origin+2*width, origin+2*width},
		{origin+3*width, origin+2*width},
		{origin, origin+3*width},
		{origin+width, origin+3*width},
		{origin+2*width, origin+3*width},
		{origin+3*width, origin+3*width}
	};
	int connected[20][20];
	for (int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			connected[i][j] = 0;

	connected[0][1] = 1;
	connected[0][4] = 1;
	connected[1][2] = 1;
	connected[2][6] = 1;
	connected[3][7] = 1;
	connected[5][9] = 1;
	connected[6][10] = 1;
	connected[7][11] = 1;
	connected[8][9] = 1;
	connected[8][12] = 1;
	connected[11][15] = 1;
	connected[12][13] = 1;
	connected[13][14] = 1;
	connected[14][15] = 1;

	for (int i = 0; i < 20; i++)
		for (int j = i+1; j < 20; j++) 
		{
			if (connected[i][j])
			{
				glBegin(GL_LINES);
				glVertex2f(vctPnt[i][0],vctPnt[i][1]);
				glVertex2f(vctPnt[j][0],vctPnt[j][1]);
				glEnd();	
			}
			
		}

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
        glOrtho(-200.0, 200.0, -200.0*(GLfloat)h/(GLfloat)w, 200.0*(GLfloat)h/(GLfloat)w,-10.0, 10.0);
    else
        glOrtho(-200.0*(GLfloat)h/(GLfloat)w, 200.0*(GLfloat)h/(GLfloat)w, -200.0, 200.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("maze");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,50.0,0.0,50.0);
    glMatrixMode(GL_MODELVIEW);
	return 0;
}

