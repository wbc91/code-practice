#include <cstdio>
#include <GLUT/glut.h>  
#include <cstdlib>  
const GLfloat lightPosition[] = {10.0,10.0,10.0,0.0};  
const GLfloat whiteLight[] = {0.8,0.8,0.8,1.0};  
GLfloat matSpecular [] = {0.3,0.3,0.3,1.0};  
GLfloat matShininess [] = {20.0};  
GLfloat matEmission [] = {0.3,0.3,0.3,1.0};  
GLfloat v = 10.0;
GLfloat t = 0.0;
GLfloat dis = 0.0;
GLfloat maxT = 0.0;
GLfloat maxDis = 0.0;
bool upFlag = true;
void init()  
{  
    glClearColor(0.3,0.3,0.3,1.0);  
    glClearDepth(1.0);  
    glShadeModel(GL_SMOOTH);  
    glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);  
    glEnable(GL_DEPTH_TEST);  
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
    glLightfv(GL_LIGHT0,GL_POSITION,lightPosition);  
    glLightfv(GL_LIGHT0,GL_DIFFUSE,whiteLight);  
    glLightfv(GL_LIGHT0,GL_SPECULAR,whiteLight);  
    maxT = v/9.8;
    maxDis = v*maxT - 0.5*9.8*maxT*maxT;
}  
void display()  
{     
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);  
      
    glMatrixMode(GL_MODELVIEW);  
    glPushMatrix();  
    glTranslatef(0.0, dis, 0.0);
    glMaterialfv(GL_FRONT,GL_SPECULAR,matSpecular);  
    glMaterialfv(GL_FRONT,GL_SHININESS,matShininess);  
    glMaterialfv(GL_FRONT,GL_EMISSION,matEmission);  
    glutSolidSphere(3.0,16,16);  
    glTranslatef(0.0, -dis, 0.0);
    glPopMatrix();  
    glFlush();  
}  
void reshape(int w,int h)  
{  
    glViewport(0.0,0.0,(GLsizei) w,(GLsizei) h);  
}  

void renderScene()
{
    t = t+0.03;
    if (upFlag){
        dis = v*t-0.5*9.8*t*t;
    }
    else {
        dis = maxDis-0.5*9.8*t*t;
    }
    if (t >= maxT) {
    	t = 0;
	upFlag = !upFlag;
    }
    display();
}

int main(int argc,char *argv[])  
{     
    glutInit(&argc,argv);  
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);  
    glutInitWindowSize(450,450);  
    glutInitWindowPosition(150,150);  
    glutCreateWindow("ball");  
    glutDisplayFunc(display);  
    glutReshapeFunc(reshape);  
    glutIdleFunc(renderScene);
    init();  
    glutMainLoop();  
    return EXIT_SUCCESS;  
}  
