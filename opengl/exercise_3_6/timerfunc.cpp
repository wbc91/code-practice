#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GLUT/glut.h>

const int width = 600;
const int height = 600;

const GLfloat PI = 3.141592653f;

float h = 0.0f;
float m = 0.0f;
float s = 0.0f;

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

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.1f, 0.2f, 0.1f);

	int cx = width/2;
	int cy = height/2;
	int R = 100;
	int n = 100;
	int i;

	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(cx + (R + 2) * cos(2*PI/n*i), cy + (R + 2)*sin(2*PI/n*i));
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; i++)
	{
		glVertex2f(cx + (R + 5) * cos(2*PI/n*i), cy+(R + 5)*sin(2*PI/n*i));
	}
	glEnd();

	int lines = 60;
	float ship1 = 10;
	float ship2 = 5;
	for (i = 0; i < lines; i++)
	{
		if (i%5 == 0)
		{
			glLineWidth(5);
			glBegin(GL_LINES);
			glVertex2f(cx + (R - ship1)*sin(2*PI/lines*i), cy + (R - ship1)*cos(2*PI/lines*i));
			glVertex2f(cx + R*sin(2 * PI/lines*i), cy+R*cos(2*PI/lines*i));
			glEnd();
		}
		else
		{
			glLineWidth(2);
			glBegin(GL_LINES);
			glVertex2f(cx + (R - ship2)*sin(2*PI/lines*i),cy + (R - ship2)*cos(2*PI/lines*i));
			glVertex2f(cx + R*sin(2*PI/lines*i), cy+R*cos(2*PI/lines*i));
			glEnd();
		}
	}

	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++)
		glVertex2i(cx + 5*cos(2*PI/n*i), cy + 5 *sin(2*PI/n*i));
	glEnd();

	int h_len = R - 3 *ship1;
	int m_len = R - ship1;
	int s_len = R - ship1 + 2 * ship1;

	float s_Angle = s / 60.0;
	float m_Angle = (m*60+s)/3600.0;
	float h2 = h >= 12?(h - 12):h;
	float h_Angle = (h2 * 60 * 60 + m * 60 + s)/(12*60*60);

	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(cx - 2 * ship1 * sin(2*PI*s_Angle), cy - 2 * ship1*cos(2*PI*s_Angle));
	glVertex2f(cx + (R - ship2) * sin(2 * PI*s_Angle), cy + (R-ship2)*cos(2*PI*s_Angle));
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(cx, cy);
	glVertex2f(cx + h_len*sin(2 * PI*h_Angle), cy + h_len*cos(2*PI*h_Angle));
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(cx, cy);
	glVertex2f(cx + m_len*sin(2*PI*m_Angle), cy+m_len*cos(2*PI*m_Angle));
	glEnd();

	glFlush();
}

void timerFunc(int value)
{
	s += 1;
	int carry1 = 0;
	if (s >= 60)
	{
		s = 0;
		carry1 = 1;
	}
	m += carry1;
	int carry2 = 0;
	if (m > 60)
	{
		m = 0;
		carry2 = 1;
	}
	h += carry2;
	if (h>=24)
		h = 0;

	glutPostRedisplay();
	glutTimerFunc(1000, timerFunc, 1);
}

void SetupRC(void)
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	time_t now;
	struct tm *timenow;
	time(&now);

	timenow = localtime(&now);
	h = timenow->tm_hour;
	m = timenow->tm_min;
	s = timenow->tm_sec;

}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width,height);
	glutCreateWindow("Timer");
	// glutReshapeFunc(myReshape);
	gluOrtho2D(0.0, width, 0.0, height);

	SetupRC();
	glutDisplayFunc(&myDisplay);
	glutTimerFunc(1000, timerFunc, 1);

	glutMainLoop();
	return 0;

}