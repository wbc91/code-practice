//
//  turtle.cpp
//  XcodeGlutDemo
//
//  Created by Beichen Wang on 17/12/16.
//  Copyright © 2016 Beichen Wang. All rights reserved.
//

#include "turtle.hpp"
#include <math.h>

GLfloat c = M_PI/180.0;
void Turtle::init(double x, double y, double theta) {
    m_startx = x;
    m_starty = y;
    m_theta = theta;
}

void Turtle::forward(double distance) {
    if (m_drawing) {
//        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
        glVertex2f(m_startx, m_starty);
        glVertex2f(m_startx+distance*cos(m_theta), m_starty+distance*sin(m_theta));
        glEnd();
        glFlush();
    }
    
    m_startx+= distance*cos(m_theta);
    m_starty+= distance*sin(m_theta);
}

void Turtle::right(double angle) {
    m_theta-=angle;
    if (m_theta < 0.0) {
        m_theta+=360.0;
    }
}

void Turtle::left(double angle) {
    m_theta+=angle;
    if (m_theta > 360.0) {
        m_theta-=360.0;
    }
}

void Turtle::pen(bool up_down) {
    if (up_down) {
        m_drawing = true;
    }
    else m_drawing = false;
}

Turtle* tur = new Turtle();
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    tur->init(0.0, 0.0, 0);
    tur->pen(true);
    tur->forward(50);
    tur->pen(false);
    tur->left(90*c);
    tur->forward(50);
    tur->pen(true);
    tur->right(75*c);
    tur->forward(50);
}

void myReshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-200.0, 200.0, -200.0*(GLfloat)h/(GLfloat)w, 200.0*(GLfloat)h/(GLfloat)w,-10.0, 10.0);
    else
        glOrtho(-200.0*(GLfloat)h/(GLfloat)w, 200.0*(GLfloat)h/(GLfloat)w, -200.0, 200.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Xcode Glut Demo");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
//    glMatrixMode(GL_MODELVIEW);

    return 0;
    
}

