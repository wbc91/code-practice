//
//  main.m
//  longitude-latitude circle
//
//  Created by Beichen Wang on 28/8/16.
//  Copyright © 2016 Beichen Wang. All rights reserved.
//

#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>

void myInit(void)
{
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glPointSize(10.0f);
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat c = M_PI/180.0;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0.0, 0.0, 1.0);
    GLfloat c80 = c*80.0;
    GLfloat z = sin(c80);
    for (GLfloat theta = -180.0; theta <= 180.0; theta += 20.0)
    {
        GLfloat thetar = c*theta;
        GLfloat x = sin(thetar)*cos(c80);
        GLfloat y = cos(thetar)*cos(c80);
        glVertex3d(x,y,z);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0.0, 0.0, -1.0);
    z = -sin(c80);
    for (GLfloat theta = -180.0; theta <= 180.0; theta += 20.0)
    {
        GLfloat thetar = c*theta;
        GLfloat x = sin(thetar)*cos(c80);
        GLfloat y = cos(thetar)*cos(c80);
        glVertex3d(x,y,z);
    }
    glEnd();
    glFlush();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500,500);
//    glutInitWindowPosition(0, 0);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}
