//
//  koch_curve.cpp
//  XcodeGlutDemo
//
//  Created by Beichen Wang on 20/12/16.
//  Copyright © 2016 Beichen Wang. All rights reserved.
//

#include "koch_curve.hpp"
#include <GLUT/GLUT.h>
#include <stdio.h>
#include <math.h>


GLdouble v[3][2] = {{-50.0,0.0}, {0.0,50*sqrt(3)}, {50.0,0.0}};
int n=5;

void divide(GLdouble*v1, GLdouble*v2, int depth) {
    if (depth == n) {
        glBegin(GL_LINES);
        glVertex2dv(v1);
        glVertex2dv(v2);
        glEnd();
    } else {
        double midx = (v1[0]+v2[0])/2;
        double midy = (v1[1]+v2[1])/2;
        
        GLdouble v3[2] = {v1[0]+(v2[0]-v1[0])/3, v1[1]+(v2[1]-v1[1])/3};
        GLdouble v4[2] = {v1[0]+(v2[0]-v1[0])*2/3, v1[1]+(v2[1]-v1[1])*2/3};
        
        //计算突起的点，首先在线段延长线上找到一点，使其到点mid的距离为sqrt(3)/6倍的线段长度。
        double tx = sqrt(3)/6*(v2[0]-v1[0]);
        double ty = sqrt(3)/6*(v2[1]-v1[1]);
        
        //绕mid点逆时针旋转90度
        //(x*cosθ- y * sinθ, y*cosθ + x * sinθ)
        double endx = -ty+midx;
        double endy = tx+midy;
        
        GLdouble v5[2] = {endx, endy};
        
        divide(v1, v3, depth+1);
        divide(v3, v5, depth+1);
        divide(v5, v4, depth+1);
        divide(v4, v2, depth+1);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    divide(v[0],v[1],1);
    divide(v[1],v[2],1);
    divide(v[2],v[0],1);
    glFlush();
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Koch Curve");
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
    
    glutMainLoop();
    
    return 0;
}