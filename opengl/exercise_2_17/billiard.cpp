#include <cstdio>
#include <GLUT/glut.h>  
#include <cstdlib>  
const GLfloat lightPosition[] = {10.0,10.0,10.0,0.0};  
const GLfloat whiteLight[] = {0.8,0.8,0.8,1.0};  
GLfloat matSpecular [] = {0.3,0.3,0.3,1.0};  
GLfloat matShininess [] = {20.0};  
GLfloat matEmission [] = {0.3,0.3,0.3,1.0};  

GLfloat v1[] = {0.5,0.5};
GLfloat v2[] = {0.0,0.0};

GLfloat p1[] = {0.0,5.0};
GLfloat p2[] = {0.0,-5.0};

GLfloat r = 1.0;

GLfloat dt = 0.01;
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
 
    glTranslatef(p1[0], p1[1], 0.0);
    glMaterialfv(GL_FRONT,GL_SPECULAR,matSpecular);  
    glMaterialfv(GL_FRONT,GL_SHININESS,matShininess);  
    glMaterialfv(GL_FRONT,GL_EMISSION,matEmission);  
    glutSolidSphere(r,16,16);  
    glTranslatef(-p1[0], -p1[1], 0.0);

    glTranslatef(p2[0], p2[1], 0.0);
    glMaterialfv(GL_FRONT,GL_SPECULAR,matSpecular);  
    glMaterialfv(GL_FRONT,GL_SHININESS,matShininess);  
    glMaterialfv(GL_FRONT,GL_EMISSION,matEmission);  
    glutSolidSphere(r,16,16);  
    glTranslatef(-p2[0], -p2[1], 0.0);
    glPopMatrix();  

    glFlush();  
}

void move()
{
    p1[0] = p1[0] + v1[0]*dt;
    p1[1] = p1[1] + v1[1]*dt;

    p2[0] = p2[0] + v2[0]*dt;
    p2[1] = p2[1] + v2[1]*dt;    
}
  
void checkCollision()
{
    //collide with ball
    GLfloat centerDis = sqrt((p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]));
    if (centerDis < 2*r){
        
    }
    //collide with wall 
}

void renderScene()
{
   move();
   checkCollision();
   display();
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
    glutIdleFunc(renderScene);
    init();  
    glutMainLoop();  
    return EXIT_SUCCESS;  
}  
