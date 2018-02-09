#include "MyGlIncludes.h"


void mousefunc(int button,int state,int x,int y);
bool checkInside(float x,float y);
bool checkBounds(float x,float y);
void moveShape();
void timerfunc(int timer);
void idlefunc();


std::vector<Point> quads={Point(-0.1f,0.1f),Point(-0.1f, -0.1f),Point(0.1f, -0.1f),Point(0.1f,0.1f)};
bool draw = false;
float z[] = {0.0,0.0};
int score = 0;
int SCREEN_W = 320,SCREEN_H = 320;

void display(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1.0,1.0,1.0);
    glVertexPointer(2, GL_FLOAT, 0, &quads[0]);
    glDrawArrays(GL_QUADS,0,quads.size());
    glColor3f(1.0,0.0,0.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    if (draw)
        glVertex2f(z[0],z[1]);
    glEnd();
    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}

bool checkInside(float x,float y)
{
    float x1 = quads[0].x;
    float x2 = quads[2].x;
    float y1 = quads[2].y;
    float y2 = quads[0].y;

    if (x<x1 or x>x2 or y<y1 or y>y2)
        return false;
    return true;
}


void mousefunc(int button,int state,int x,int y)
{
    float x1,y1; map_point(0,0,SCREEN_W,SCREEN_H,-1,1,1,-1,x,y,x1,y1);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        draw = true;
        z[0]=x1;
        z[1]=y1;
        if (checkInside(x1,y1))
            std::cout<<"Hit! Score: "<<++score<<std::endl;
        else
            std::cout<<"Miss! Score: "<<--score<<std::endl;
        if (score <=-3)
        {
            std::cout<<"Game over!"<<std::endl;
            exit(1);
        }
        glutPostRedisplay();
    }
}

bool checkBounds(float x,float y)
{
    for (int i=0;i<quads.size();i++)
    {
        float r=quads[i].x+x;
        float q=quads[i].y+y;
        if (r<=-1 or r>=1 or q<=-1 or q>=1)
            return false;
    }
    return true;
}

void moveShape()
{
    float x=0,y=0;
    do
    {
        x = (rand()%100-50)/100.0; //-50 to 50
        y = (rand()%100-50)/100.0; //-50 to 50
    } while (checkBounds(x,y) != true);
    for (int i = 0; i < quads.size(); ++i)
    {
        quads[i].x+=x;
        quads[i].y+=y;
    }
    draw = false;
    glutPostRedisplay();
}

void timerfunc(int timer)
{
    moveShape();
    float t=(rand()%35+5)*100; // 0.5 - 4.0 seconds delay.
    glutTimerFunc(t, timerfunc, 0);
}

void idlefunc()
{
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
    srand(time(NULL));
    glutInit(&argc,argv);
    glutInitWindowSize(SCREEN_W,SCREEN_H);
    glutInitWindowPosition(50,50);
    glutCreateWindow("4: Catch me if you can!");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMouseFunc(mousefunc);
    glutIdleFunc(idlefunc);
    glutTimerFunc(1,timerfunc,1);
    glutMainLoop();
    return 0;
}
