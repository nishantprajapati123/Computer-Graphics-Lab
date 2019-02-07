//#if 0
#include <Windows.h>
#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>
#define PI 3.14159265358979324
using namespace std;

double X1, Y1, X2, Y2;
int ch;
void reflection(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1.0f,0.0f,1.0f);
	glVertex2d(-x,y);
	glVertex2d(-x,-y);
	glVertex2d(x,-y);
	glEnd();
}
void draw_pixel(int X, int Y) {
	glBegin(GL_POINTS);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2i(X, Y);
	glEnd();
}

void DDA()
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
	glPointSize(3.0);
    glBegin(GL_POINTS);
    /* Plot the first point */
    glVertex2d(x,y);
	reflection(x,y);
    int k;
    /* For every step, find an intermediate vertex */
    for(k=0;k<steps;k++)
    {
        x+=xInc;
        y+=yInc;
        /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
        glVertex2d(x,y);
		reflection(x,y);
    }
    glEnd();

    // Flush created objects to the screen, i.e., force rendering.
    glFlush();
}
void Bresenham(void)
{
	glPointSize(3.0);
    int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = X2-X1;
	dy = Y2-Y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (X2 < X1) incx = -1;
	incy = 1;
	if (Y2 < Y1) incy = -1;
	x = X1; y = Y1;
	if (dx > dy) {
		draw_pixel(x, y);
		reflection(x,y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
			reflection(x,y);
		}

	} else {
		draw_pixel(x, y);
		reflection(x,y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
			reflection(x,y);
		}
	}

    // Flush created objects to the screen, i.e., force rendering.
    glFlush();
}
void drawScene(void)
{
	/* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	//draw X coordinate
	glBegin(GL_POINTS);
	for(int i=-400;i<=400;i++)
	{
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2i(i,0);
	}
	//draw Y coordinate
	for(int j=-400;j<=400;j++)
	{
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2i(0,j);
	}
	glEnd();
    if(ch==0)
		DDA();
	else
		Bresenham();
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
    glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);

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
	cout<<"1.DDA\n2.Bresenham\n";
	cin>>ch;
    // Initialize GLUT.
    glutInit(&argc, argv);

    // Set display mode as single-buffered and RGB color.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set OpenGL window size.
    glutInitWindowSize(1000, 1000);

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
//#endif
