#if 0
#include <Windows.h>
#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>
#define PI 3.14159265358979324
using namespace std;
int X,Y,R;
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+X,y+Y);
    glEnd();
}
void drawScene(void)
{
    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);
    /* Plot the points */
    glColor3f(1.0,0.0,0.0);
    glPointSize(5.0);
    int x=0,y=R;
    //Initial decision parameter
    int p = 1-R;
    plot(x,y);
    while(y>x)
    {
        if(p<0)
        {
            x++;
            p = p+(2*x)+3;
        }
        else
        {
            x++,y--;
            p = p+(2*x)-(2*y)+5;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }


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
    glOrtho(-250.0, 250.0, -250.0, 250.0, -1.0, 1.0);

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
    cout<<"Enter (X,Y):";
    cin>>X>>Y;
    cout<<"\nEnter R:";
    cin>>R;
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
