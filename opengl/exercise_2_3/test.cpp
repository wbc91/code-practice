//
//  test.cpp
//  XcodeGlutDemo
//
//  Created by Beichen Wang on 17/9/16.
//  Copyright © 2016 Beichen Wang. All rights reserved.
//

#include "test.hpp"
#include "miniOpenglToolkit.hpp"
#include <GLUT/GLUT.h>
#include <math.h>
#include <iostream>

#define max(a, b) a>b?a:b
GLint mWidth = 640;
GLint mHeight = 640;

MiniOpenglToolkit* mot = new MiniOpenglToolkit();

inline void swap_int(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void drawLineWithEquation(int x0, int y0, int xEnd, int yEnd) {
    float m = (float)(yEnd-y0)/(xEnd-x0);
    float mr = 1/m;
    if (m <= 1) {
        for (int x = x0; x <= xEnd; ++x) {
            int y = lroundf((x-x0)*m+y0);
            mot->writePixel(x, y);
        }
    }
    else {
        for (int y = y0; y <= yEnd; ++y) {
            int x = lroundf((y-y0)*mr+x0);
            mot->writePixel(x, y);
        }
    }
}

void drawLineWithDDA(int x0, int y0, int xEnd, int yEnd) {
    int dx = xEnd-x0;
    int dy = yEnd-y0;
    float x = x0;
    float y = y0;
    int steps = max(std::abs(dx), std::abs(dy));
    
    float xIncrement = (float)(dx)/steps;
    float yIncrement = (float)(dy)/steps;
    
    mot->writePixel(x, y);
    
    for (int i = 0; i <= steps; ++i) {
        x += xIncrement;
        y += yIncrement;
        mot->writePixel(lroundf(x), lroundf(y));
    }
}

void drawLineWithBresenham(int x0, int y0, int xEnd, int yEnd) {
    int dx = abs(xEnd-x0),
        dy = abs(yEnd-y0),
        yy = 0;
    if (dx < dy) {
        yy = 1;
        swap_int(&x0, &y0);
        swap_int(&xEnd, &yEnd);
        swap_int(&dx, &dy);
    }
    
    int ix = (xEnd-x0)>0?1:-1,
        iy = (yEnd-y0)>0?1:-1,
        cx = x0,
        cy = y0,
        n2dy = dy*2,
        n2dydx = (dy-dx)*2,
        d = dy*2-dx;
    if (yy) { //直线与x轴夹角大于45度
        while(cx != xEnd) {
            if (d < 0) {
                d += n2dy;
            } else {
                cy+=iy;
                d += n2dydx;
            }
            mot->writePixel(cy, cx);
            cx += ix;
        }
    }else { //直线与x轴夹角小于45度
        while(cx != xEnd) {
            if (d < 0) {
                d += n2dy;
            } else {
                cy += iy;
                d += n2dydx;
            }
            mot->writePixel(cx, cy);
            cx += ix;
        }
    }
}
void _draw_circle_8(int xc, int yc, int x, int y) {
    mot->writePixel(xc+x, yc+y);
    mot->writePixel(xc-x, yc+y);
    mot->writePixel(xc+x, yc-y);
    mot->writePixel(xc-x, yc-y);
    mot->writePixel(xc+y, yc+x);
    mot->writePixel(xc-y, yc+x);
    mot->writePixel(xc+y, yc-x);
    mot->writePixel(xc-y, yc-x);
}
void drawCircleWithBresenham(int xc, int yc, int r, int fill) {
    //xc, yc 圆心
    //fill 是否填充
    if (xc + r < 0 || xc -r >= mWidth || yc + r < 0 || yc - r >= mHeight) return;
    
    int x = 0, y = r, yi, d;
    d = 3-2*r;
    
    if (fill) {
        while(x <= y) {
            for (yi = x; yi <= y; yi++) {
                _draw_circle_8(xc, yc, x, yi);
            }
            
            if (d < 0) {
                d = d+4*x+6;
            } else {
                d = d+4*(x-y)+10;
                y--;
            }
            x++;
        }
    } else {
        while(x <= y) {
            _draw_circle_8(xc, yc, x, y);
            if (d < 0) {
                d = d+4*x+6;
            } else {
                d = d+4*(x-y)+10;
                y--;
            }
            x++;
        }
    }
}

void display() {
    mot->clear();
//    drawLineWithEquation(0, 0, 300, 50);
//    drawLineWithEquation(0, 0, 300, 100);
//    drawLineWithEquation(0, 0, 300, 150);
//    drawLineWithEquation(0, 0, 300, 300);
//    drawLineWithEquation(0, 0, 150, 300);
//    drawLineWithEquation(0, 0, 100, 300);
//    drawLineWithEquation(0, 0, 50, 300);
//    drawLineWithEquation(300,0,300,50);
//    drawLineWithDDA(0,0,0,300);
    drawLineWithBresenham(0, 0, 0, 300);
    drawCircleWithBresenham(0, 0, 300, 0);
    
    
    mot->flush();
}

int main(int argc, char ** argv) {
    mot->init(argc, argv);
    mot->readPixel(mWidth,mHeight);
    mot->displayFunc(display);
    mot->mainLoop();
    return 0;
    
}

