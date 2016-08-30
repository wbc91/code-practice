//
//  main.m
//  longitude-latitude circle
//
//  Created by Beichen Wang on 28/8/16.
//  Copyright © 2016 Beichen Wang. All rights reserved.
//

#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0,0.0,0.0);
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    double c = M_PI/180.0;
    for (double phi = -80.0; phi <= 80.0; phi += 20.0)
    {
        double phir = c*phi;
        double phir20 = c*(phi+20);
        glBegin(GL_QUAD_STRIP);
        
        for (double theta = -180.0;theta <= 180.0; theta+=20)
        {
            double thetar = c*theta;
            double x = sin(thetar)*cos(phir);
            double y = cos(thetar)*cos(phir);
            double z = sin(phir);
            glVertex3d(x,y,z);
            x = sin(thetar)*cos(phir20);
            y = cos(thetar)*cos(phir20);
            z = sin(phir20);
            glVertex3d(x,y,z);
        }
        glEnd();
    }
    glFlush();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}
