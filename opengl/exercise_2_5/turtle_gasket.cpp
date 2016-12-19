//
//  turtle_gasket.cpp
//  XcodeGlutDemo
//
//  Created by Beichen Wang on 19/12/16.
//  Copyright © 2016 Beichen Wang. All rights reserved.
//

#include "turtle_gasket.hpp"
#include "turtle.hpp"

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
Turtle* turtle = new Turtle();

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
    double theta = 0.0;
    double distance = 0.0;
    turtle->init(a[0], a[1], 0);
    {
//        printf("(%f, %f)\n",a[0],a[1]);
//        printf("(%f, %f)\n",b[0],b[1]);
//        printf("(%f, %f)\n",c[0],c[1]);
        if (a[0] == b[0]) {
            theta = M_PI/2;
        } else {
            theta = std::abs(atan((b[1]-a[1])/(b[0]-a[0])));
        }
        distance = sqrt((b[1]-a[1])*(b[1]-a[1])+(b[0]-a[0])*(b[0]-a[0]));
        if (a[0] > b[0]) {
            theta = M_PI-theta;
        }
        theta = theta/M_PI*180;
        if (a[1] > b[1]) {
            turtle->right(theta);
        }
        else {
            turtle->left(theta);
        }
        
        turtle->pen(true);
        turtle->forward(distance);
        turtle->pen(false);
//        printf("%f\n", theta/M_PI*180);
    }
    turtle->init(b[0], b[1], 0);
    {
        if (b[0] == c[0]) {
            theta = M_PI/2;
        } else {
            theta = std::abs(atan((c[1]-b[1])/(c[0]-b[0])));
        }
        distance = sqrt((c[1]-b[1])*(c[1]-b[1])+(c[0]-b[0])*(c[0]-b[0]));
        if (b[0] > c[0]) {
            theta = M_PI-theta;
        }
        theta = theta/M_PI*180;
        if (b[1] > c[1]) {
            turtle->right(theta);
        }
        else {
            turtle->left(theta);
        }
        turtle->pen(true);
        turtle->forward(distance);
        turtle->pen(false);
//        printf("%f\n", theta/M_PI*180);
    }
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
//    triangle(v[0],v[1],v[2]);
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
