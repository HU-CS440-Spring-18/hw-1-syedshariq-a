#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void display();

int SCREEN_W = 500,SCREEN_H = 100;

void display(){
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    bool bw = true; // set to true for black and white bar. else rgb bar.
    if (bw==true)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f,1.0f);
        glVertex2f(-1.0f, -1.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f,1.0f);
        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f,1.0f);
        glVertex2f(-1.0f, -1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.0f, -1.0f);
        glVertex2f(0.0f,1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.0f, -1.0f);
        glVertex2f(0.0f,1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(1.0f,1.0f);
        glVertex2f(1.0f, -1.0f);
        glEnd();
    }


    glFlush();
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(SCREEN_W,SCREEN_H);
    glutInitWindowPosition(50,50);
    glutCreateWindow("6: Color bars");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
