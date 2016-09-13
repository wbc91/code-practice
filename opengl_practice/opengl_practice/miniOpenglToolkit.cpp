//
//  miniOpenglToolkit.cpp
//  opengl_practice
//
//  Created by Beichen Wang on 16/9/12.
//  Copyright © 2016年 Beichen Wang. All rights reserved.
//

#include "miniOpenglToolkit.hpp"

MiniOpenglToolkit::MiniOpenglToolkit():defaultWidth(1),defaultHeight(1),defaultFormat(GL_BLUE),defaultType(GL_UNSIGNED_BYTE),defaultPixels(nullptr){}

void MiniOpenglToolkit::readPixel(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels) {
    glReadPixels(x, y, width, height, format, type, pixels);
}

void MiniOpenglToolkit::writePixel(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) {
    glDrawPixels(width, height, format, type, pixels);
}

void MiniOpenglToolkit::setPixel(GLint x, GLint y) {
    readPixel(x, y, defaultWidth, defaultHeight, defaultFormat, defaultType, defaultPixels);
    writePixel(defaultWidth, defaultHeight, defaultFormat, defaultType, defaultPixels);
}

GLvoid* MiniOpenglToolkit::getPixels() {
    return this->defaultPixels;
}