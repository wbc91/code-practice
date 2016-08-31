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
GLfloat v[3][2] = {{0.0,0.0},{25.0,50.0},{50.0, 0.0}};
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
//    glPointSize(10.0f);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    
}

void triangle(GLfloat *a, GLfloat*b, GLfloat*c)
{
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int k)
{
    GLfloat ab[2], ac[2], bc[2];
    int j;
    if (k > 0) {
        /*计算各边中点*/
        for(j = 0; j < 2; j++) ab[j] = (a[j]+b[j])/2;
        for(j = 0; j < 2; j++) ac[j] = (a[j]+c[j])/2;
        for(j = 0; j < 2; j++) bc[j] = (b[j]+c[j])/2;
        
        /*继续细分小三角形，除了中间那个小三角形*/
        divide_triangle(a, ab, ac, k-1);
        divide_triangle(c, ac, bc, k-1);
        divide_triangle(b, bc, ab, k-1);
    }
    else triangle(a,b,c); /*在递归结束时绘制三角形*/
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    divide_triangle(v[0], v[1], v[2], n);
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
