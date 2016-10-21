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
     @param width 像素宽
     @param height 像素高
     */
    void readPixel(GLint width, GLint height);
    
    /**
     @brief 写入像素
     @param x,y 像素位置
     */
    void writePixel(GLint x, GLint y);
    
    /**
     @brief 获得帧缓存。
     */
    GLvoid* getPixels();
    
    /**
     @brief 初始化
     */
    void init(int argc, char ** argv);
    
    /**
     @brief 主循环
     */
    void mainLoop();
    
    /**
     @brief display func
     */
    void displayFunc(void (*func)(void));
    
    /**
     @brief reshape func
     */
    void reshape();
    /**
     @brief flush
     */
    void flush();
    
    /**
     @brief clear
     */
    void clear();
private:
    GLsizei defaultWidth;
    GLsizei defaultHeight;
    GLenum defaultFormat;
    GLenum defaultType;
    GLvoid* defaultPixels;
};
#endif /* miniOpenglToolkit_hpp */
