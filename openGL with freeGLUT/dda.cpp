#if 0
#include <Windows.h>
#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>
#define PI 3.14159265358979324
using namespace std;

double X1, Y1, X2, Y2;
float round_value(float v)
{
  return floor(v + 0.5);
}
// Drawing (display) routine.
void drawScene(void)
{
    double dx=(X2-X1);
    double dy=(Y2-Y1);
    double steps;
    float xInc,yInc,x=X1,y=Y1;
    /* Find out whether to increment x or y */
    steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
    xInc=dx/(float)steps;
    yInc=dy/(float)steps;

    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);
    /* Plot the points */
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    /* Plot the first point */
    glVertex2d(x,y);
    int k;
    /* For every step, find an intermediate vertex */
    for(k=0;k<steps;k++)
    {
        x+=xInc;
        y+=yInc;
        /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
        glVertex2d(x,y);
    }
    glEnd();

    // Flush created objects to the screen, i.e., force rendering.
    glFlush();
}

// Initialization routine.
void setup(void)
{
    // Set background (or clearing) color.
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    // Set viewport size to be entire OpenGL window.
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    // Set matrix mode to projection.
    glMatrixMode(GL_PROJECTION);

    // Clear current projection matrix to identity.
    glLoadIdentity();

    // Specify the orthographic (or perpendicular) projection,
    // i.e., define the viewing box.
    glOrtho(0.0, 400.0, 0.0, 400.0, -1.0, 1.0);

    // Set matrix mode to modelview.
    glMatrixMode(GL_MODELVIEW);

    // Clear current modelview matrix to identity.
    glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch(key)
    {
            // Press escape to exit.
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

// Main routine: defines window properties, creates window,
// registers callback routines and begins processing.
int main(int argc, char **argv)
{
    cout<<"Enter (X1,Y1):";
    cin>>X1>>Y1;
    cout<<"\nEnter (X2,Y2):";
    cin>>X2>>Y2;
    // Initialize GLUT.
    glutInit(&argc, argv);

    // Set display mode as single-buffered and RGB color.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set OpenGL window size.
    glutInitWindowSize(500, 500);

    // Set position of OpenGL window upper-left corner.
    glutInitWindowPosition(100, 100);

    // Create OpenGL window with title.
    glutCreateWindow("circle.cpp");

    // Initialize.
    setup();

    // Register display routine.
    glutDisplayFunc(drawScene);

    // Register reshape routine.
    glutReshapeFunc(resize);

    // Register keyboard routine.
    glutKeyboardFunc(keyInput);

    // Begin processing.
    glutMainLoop();

    return 0;
}

#endif
