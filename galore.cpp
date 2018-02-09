#include "MyGlIncludes.h"

void mousefunc(int button,int state,int x,int y);
void idlefunc();
void keyboardfunc(unsigned char key,int x,int y);

int sides = 3;
std::vector<Point> quads;
std::vector<Point> triangles;
std::vector<Point> points;
int SCREEN_W = 320,SCREEN_H = 320;

bool point = true;

void display(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    if (point)
    {
        glBegin(GL_POINTS);
        for (int i = 0; i < points.size(); ++i)
        {
            glVertex2f(points[i].x,points[i].y);
        }
        glEnd();
    }
    else
    {
        for (int i = 0; i < points.size(); ++i)
        {
            if (sides == 3)
                triangles.push_back(points.back());
            else
                quads.push_back(points.back());
            points.pop_back();
        }
    }
    //triangles
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < triangles.size(); ++i)
    {
        glVertex2f(triangles[i].x,triangles[i].y);
    }
    glEnd();
    glBegin(GL_QUADS);
    for (int i = 0; i < quads.size(); ++i)
    {
        glVertex2f(quads[i].x,quads[i].y);
    }
    glEnd();
    glutSwapBuffers();
}



void mousefunc(int button,int state,int x,int y)
{
    float x1,y1; map_point(0,0,SCREEN_W,SCREEN_H,-1,1,1,-1,x,y,x1,y1);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        point=true;
        points.push_back(Point(x1,y1));
        if (points.size()%sides==0 && points.size()>0)
        {
            point=false;
        }
        glutPostRedisplay();
    }
}

void keyboardfunc(unsigned char key,int x,int y)
{
    if (key == 'T' or key== 't')
    {
        if (points.size()==0)
        {
            sides = 7-sides;
            if (sides == 3)
                std::cout<<"Triangle mode entered.\n";
            else
                std::cout<<"Quad mode entered.\n";
        }
        else
            // causes problems otherwise if you have 3 points on a quad mode and toggle. Unexpected behavior.
            std::cout<<"Please finish the current shape before you can toggle.\n";
    }
    if (key == 'Q' or key=='q')
    {
        std::cout<<"Exiting the program.\n";
        exit(1);
    }
    if (key == 'R' or key=='r')
    {
        points.clear();
        quads.clear();
        triangles.clear();
        std::cout<<"Screen cleared.\n";
    }
}

void idlefunc()
{
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(SCREEN_W,SCREEN_H);
    glutInitWindowPosition(50,50);
    glutCreateWindow("2: Polygons Galore");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMouseFunc(mousefunc);
    glutKeyboardFunc(keyboardfunc);
    glutIdleFunc(idlefunc);
    glutMainLoop();
    return 0;
}
