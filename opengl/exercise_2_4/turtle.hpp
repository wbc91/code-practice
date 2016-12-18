//
//  turtle.hpp
//  XcodeGlutDemo
//
//  Created by Beichen Wang on 17/12/16.
//  Copyright © 2016 Beichen Wang. All rights reserved.
//

#ifndef turtle_hpp
#define turtle_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>

class Turtle {
public:
    Turtle(){};
    ~Turtle(){};
    
    void init(double x, double y, double theta);
    void forward(double distance);
    void right(double angle);
    void left(double angle);
    void pen(bool up_down);
private:
    double m_startx = 0.0;
    double m_starty = 0.0;
    double m_theta = 0.0;
    bool m_drawing = false;
};
#endif /* turtle_hpp */
