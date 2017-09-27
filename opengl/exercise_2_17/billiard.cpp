#include <cstdio>
#include <GLUT/glut.h>  
#include <cstdlib>  
const GLfloat lightPosition[] = {10.0,10.0,10.0,0.0};  
const GLfloat whiteLight[] = {0.8,0.8,0.8,1.0};  
GLfloat matSpecular [] = {0.3,0.3,0.3,1.0};  
GLfloat matShininess [] = {20.0};  
GLfloat matEmission [] = {0.3,0.3,0.3,1.0};  
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
}  
void display()  
{     
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);  
      
    glMatrixMode(GL_MODELVIEW);  
    glPushMatrix(); 
 
    glTranslatef(0.0, 5.0, 0.0);
    glMaterialfv(GL_FRONT,GL_SPECULAR,matSpecular);  
    glMaterialfv(GL_FRONT,GL_SHININESS,matShininess);  
    glMaterialfv(GL_FRONT,GL_EMISSION,matEmission);  
    glutSolidSphere(1.0,16,16);  
    glTranslatef(0.0, -5.0, 0.0);

    glTranslatef(0.0, -5.0, 0.0);
    glMaterialfv(GL_FRONT,GL_SPECULAR,matSpecular);  
    glMaterialfv(GL_FRONT,GL_SHININESS,matShininess);  
    glMaterialfv(GL_FRONT,GL_EMISSION,matEmission);  
    glutSolidSphere(1.0,16,16);  
    glTranslatef(0.0, 5.0, 0.0);
    glPopMatrix();  

    glFlush();  
}
  
void checkCollision()
{

}

void reshape(int w,int h)  
{  
    glViewport(0.0,0.0,(GLsizei) w,(GLsizei) h);  
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
//    glutIdleFunc(renderScene);
    init();  
    glutMainLoop();  
    return EXIT_SUCCESS;  
}  
