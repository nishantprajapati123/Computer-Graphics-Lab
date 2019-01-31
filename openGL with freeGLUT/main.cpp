#if 0//circle

#include <Windows.h>
#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>


#define PI 3.14159265358979324


using namespace std;


// Drawing (display) routine.
void drawScene(void)
{
    float R = 60.0;// Radius of circle.
    float X = 200.0; // X-coordinate of center of circle.
    float Y = 200.0; // Y-coordinate of center of circle.
    int numVertices = 30; // Number of vertices on circle.
    float t = 0; // Angle parameter.
    int i;

    // Clear screen to background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Set foreground (or drawing) color.
    glColor3f(1.0, 0.0, 0.0);

#if 0
    // Draw a square with specified vertices.
    glBegin(GL_POLYGON);
    glVertex3f(20.0, 20.0, 0.0);
    glVertex3f(80.0, 20.0, 0.0);
    glVertex3f(80.0, 80.0, 0.0);
    glVertex3f(20.0, 80.0, 0.0);
    glEnd();

    // Draw a rectangle with specified vertices.
    glBegin(GL_POLYGON);
    glVertex3f(120.0, 120.0, 0.0);
    glVertex3f(200.0, 120.0, 0.0);
    glVertex3f(200.0, 180.0, 0.0);
    glVertex3f(120.0, 180.0, 0.0);
    glEnd();
#endif
    // Draw a line loop with vertices at equal angles apart on a circle
    // with center at (X, Y) and radius R, The vertices are colored randomly.
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < numVertices; ++i)
    {
        glColor3ub(255,0,0);
        glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
        t += 2 * PI / numVertices;
    }
    glEnd();

    // Flush created objects to the screen, i.e., force rendering.
    glFlush();
}

// Initialization routine.
void setup(void)
{
    // Set background (or clearing) color.
    glClearColor(1.0, 1.0, 1.0, 0.0);
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
 // 0
#endif
