#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "interpolate.cpp"
#include <cmath>
#include <vector>
#define PI 3.14159
void display();

struct Point {
    GLfloat x,y;
    Point(float a,float b){x=a; y=b;}
};
int SCREEN_W = 640,SCREEN_H = 640;
int numshapes = 6;
std::vector<Point> quads;
std::vector<std::vector<Point>> shapes;
void display(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    int numsides;
    float radius=1.0/numshapes;
    Point nextVertex(0,0);
    for (int i = 1; i <= numshapes; ++i)
    {
        numsides=4*i;
        quads.clear();
        for (int j = 0; j < numsides; j++) {
            //http://dimitroff.bg/generating-vertices-of-regular-n-sided-polygonspolyhedra-and-circlesspheres/
            float angle = j * 2 * PI / numsides;
            nextVertex.x = radius * cos(angle)-(1-radius)+2*radius*(i-1);
            nextVertex.y = radius * sin(angle)+(1-radius);
            quads.push_back(nextVertex);
        }
        shapes.push_back(quads);
    }
    glColor3f(1.0f,1.0f,1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    for (int i = 0; i < shapes.size(); ++i)
    {
        glVertexPointer(2, GL_FLOAT, 0, &shapes[i][0]);
        glDrawArrays(GL_POLYGON,0,shapes[i].size());
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(SCREEN_W,SCREEN_H);
    glutInitWindowPosition(50,50);
    glutCreateWindow("7: Smooth Circle");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
