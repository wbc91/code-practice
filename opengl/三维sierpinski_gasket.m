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

int n = 5;
GLfloat v[4][3] = {{0.0,0.0,0.0},{25.0,50.0,10.0},{50.0,25.0,25.0},{25.0,10.0,25.0}};
GLfloat p[3] = {25.0,10.0,25.0};
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glColor3f(1.0, 0.0, 0.0);
//    glPointSize(10.0f);
    
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
//    glMatrixMode(GL_MODELVIEW);
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    int rand();
    int j;

    glBegin(GL_POINTS);
    for (int k = 0; k < 5000; k++) {
        j = rand()%4;
        
        p[0] = (p[0]+v[j][0])/2.0;
        p[1] = (p[1]+v[j][1])/2.0;
        p[2] = (p[2]+v[j][2])/2.0;

        glColor3f(p[0]/250.0, p[1]/250.0, p[2]/250.0);
        glVertex3fv(p);
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
