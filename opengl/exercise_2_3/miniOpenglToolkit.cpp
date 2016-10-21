//
//  miniOpenglToolkit.cpp
//  opengl_practice
//
//  Created by Beichen Wang on 16/9/12.
//  Copyright © 2016年 Beichen Wang. All rights reserved.
//

#include "miniOpenglToolkit.hpp"

void MiniOpenglToolkit::init(int argc, char ** argv) {
    glutInit(&argc, argv);
}

MiniOpenglToolkit::MiniOpenglToolkit():defaultWidth(1),defaultHeight(1),defaultFormat(GL_BLUE),defaultType(GL_UNSIGNED_BYTE),defaultPixels(nullptr){}

void MiniOpenglToolkit::readPixel(GLint width, GLint height) {
    glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Draw Line");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0, 0.0,0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width/2, width/2, -height/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glEnableClientState(GL_VERTEX_ARRAY);
}

void MiniOpenglToolkit::writePixel(GLint x, GLint y) {
    glBegin(GL_POINTS);
    GLint vertices[] = {x,y};
    glVertex2iv(vertices);
    glEnd();
}

GLvoid* MiniOpenglToolkit::getPixels() {
    return this->defaultPixels;
}

void MiniOpenglToolkit::mainLoop() {
    glutMainLoop();
}

void MiniOpenglToolkit::displayFunc(void (*func)()) {
    glutDisplayFunc(func);
}

void MiniOpenglToolkit::reshape() {
    glutReshapeFunc([](int width, int height) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-width/2, width/2, 0, height);
        glMatrixMode(GL_MODELVIEW);
    });
}

void MiniOpenglToolkit::flush() {
    glFlush();
}

void MiniOpenglToolkit::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}