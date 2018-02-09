#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void map_point(float px,float py, float qx, float qy, float ax, float ay, float bx, float by, float x, float y, float &_x, float &_y)
{
	/*
	x = a*px+(1-a)*qx
	x = a*px + qx - a*qx
	x = qx + a*px - a*qx
	x = qx + a(px - qx)
	a = (x - qx) / (px - qx)

	_x = a*ax+(1-a)*bx
	_y = b*ay+(1-b)*by */

    float a = (x - qx) / (px - qx);
    float b = (y - qy) / (py - qy);
    _x = a * ax + (1 - a) * bx;
    _y = b * ay + (1 - b) * by;

}
