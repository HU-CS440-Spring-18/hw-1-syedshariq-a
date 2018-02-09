#include "MyGlIncludes.h"

int RecLevel = 5; //RecLevel 0 is a simple triangle. RecLevel 5 as given in the question.
void sierpinski(Point a,Point b,Point c,int n);
int SCREEN_W = 640,SCREEN_H = 640;
void display(){
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    Point a = Point(0.0f,1.0f);
    Point b = Point(-1.0f,-1.0f);
    Point c = Point(1.0f,-1.0f);
    sierpinski(a,b,c,RecLevel);
    glutSwapBuffers();
}

void draw_line(Point p1,Point p2)
{
    glBegin(GL_LINES);
    glVertex2f(p1.x,p1.y);
    glVertex2f(p2.x,p2.y);
    glEnd();
}

Point mid(Point a,Point b)
{
    float x1 = (a.x + b.x) / 2.0;
    float y1 = (a.y + b.y) / 2.0;
    return Point(x1,y1);
}
void sierpinski(Point a,Point b,Point c,int n)
{
    if (n==-1)
        return;
    draw_line(a,b);
	draw_line(b,c);
	draw_line(c,a);
	sierpinski(a,mid(a,b),mid(a,c),n-1);
	sierpinski(mid(a,b),b,mid(b,c),n-1);
	sierpinski(mid(a,c),mid(b,c),c,n-1);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(SCREEN_W,SCREEN_H);
    glutInitWindowPosition(50,50);
    glutCreateWindow("8: Sierpinski Triangle");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
