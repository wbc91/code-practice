//
//  miniOpenglToolkit.hpp
//  opengl_practice
//
//  Created by Beichen Wang on 16/9/12.
//  Copyright © 2016年 Beichen Wang. All rights reserved.
//

#ifndef miniOpenglToolkit_hpp
#define miniOpenglToolkit_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>

class MiniOpenglToolkit
{
public:
    
    MiniOpenglToolkit();
    ~MiniOpenglToolkit(){};
    /**
     @brief 读取像素
     @param x,y 像素位置
     @param width 像素宽
     @param height 像素高
     @param format 确定像素数据的形式:GL_COLOR_INDEX, GL_STENCIL_INDEX, GL_DEPTH_COMPONENT, GL_RGB, GL_BGR, GL_RGBA, GL_BGRA, GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA, GL_LUMINANCE, and GL_LUMINANCE_ALPHA
     @param type 确定像素数据的类型:GL_UNSIGNED_BYTE, GL_BYTE, GL_BITMAP, GL_UNSIGNED_SHORT, GL_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, and GL_UNSIGNED_INT_2_10_10_10_REV
     @param pixels 指向像素数据的指针
     
     */
    void readPixel(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
    
    /**
     @brief 写入像素
     @param width 像素宽
     @param height 像素高
     @param format 确定像素数据的形式:GL_COLOR_INDEX, GL_STENCIL_INDEX, GL_DEPTH_COMPONENT, GL_RGB, GL_BGR, GL_RGBA, GL_BGRA, GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA, GL_LUMINANCE, and GL_LUMINANCE_ALPHA
     @param type 确定像素数据的类型:GL_UNSIGNED_BYTE, GL_BYTE, GL_BITMAP, GL_UNSIGNED_SHORT, GL_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, and GL_UNSIGNED_INT_2_10_10_10_REV
     @param pixels 指向像素数据的指针
     */
    void writePixel(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
    
    
    /**
     @brief 在(x,y)处画点。
     */
    void setPixel(GLint x, GLint y);
    
    /**
     @brief 获得帧缓存。
     */
    GLvoid* getPixels();
    
private:
    GLsizei defaultWidth;
    GLsizei defaultHeight;
    GLenum defaultFormat;
    GLenum defaultType;
    GLvoid* defaultPixels;
};
#endif /* miniOpenglToolkit_hpp */
