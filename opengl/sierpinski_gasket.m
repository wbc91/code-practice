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
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0,0.0,0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat vertices[3][3] = {{0.0, 0.0, 0.0 },{25.0, 50.0, 0.0},{50.0, 0.0, 0.0}};
    GLfloat p[3] = {7.50, 5.0, 0.0};
    
    int j, k;
    int rand();
    glBegin(GL_POINTS);
    for (k = 0; k < 5000; k++)
    {
        j = rand() % 3;
        
        p[0] = (p[0] + vertices[j][0])/2.0;
        p[1] = (p[1] + vertices[j][1])/2.0;
        
        glVertex3fv(p);
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}