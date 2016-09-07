//
//  test.cpp
//  opengl_practice
//
//  Created by Beichen Wang on 16/9/7.
//  Copyright © 2016年 Beichen Wang. All rights reserved.
//

#include "test.hpp"
#include <random>
#include <functional>
#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>



int n = 5;
GLfloat v[3][2] = {{0.0,0.0},{25.0,50.0},{50.0, 0.0}};

std::uniform_int_distribution<int> uniform_dist(0,25);
std::normal_distribution<double> normal_dist(2.0, 0.05);

std::default_random_engine engine;
auto uniform_rand = std::bind(uniform_dist, engine);
auto normal_rand = std::bind(normal_dist, engine);

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    //    glPointSize(10.0f);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    
}

void triangle(GLfloat *a, GLfloat*b, GLfloat*c)
{
    glBegin(GL_LINE_LOOP);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int k)
{
    GLfloat ab[2], ac[2], bc[2];
    int j;
    if (k > 0) {
        /*计算各边中点*/
        for(j = 0; j < 2; j++) ab[j] = (a[j]+b[j])/normal_rand();
        for(j = 0; j < 2; j++) ac[j] = (a[j]+c[j])/normal_rand();
        for(j = 0; j < 2; j++) bc[j] = (b[j]+c[j])/normal_rand();
        
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
    divide_triangle(v[0], v[1], v[2], n);
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
