// gcc includes teh right files for the detected OS.
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include "interpolate.cpp"
#include <cstdlib>
#include <ctime>
#include <vector>


void display();

struct Point {
    GLfloat x,y;
    Point(float a,float b){x=a; y=b;}
};
