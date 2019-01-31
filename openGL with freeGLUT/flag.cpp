#if 0
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

// function to initialize

void myInit (void)
{
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(1.0f,1.0f, 1.0f);

    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float x, y, i,x1,y1,x3,y3,j;

    // iterate y up to 2*pi, i.e., 360 degree
    // with small increment in angle as
    // glVertex2i just draws a point on specified co-ordinate
    /*for ( i = 0; i < (2 * pi); i += 0.001)
    {
        // let 200 is radius of circle and as,
        // circle is defined as x=r*cos(i) and y=r*sin(i)
        x = 200 * cos(i);
        y = 200 * sin(i);
        x1 = 100 * cos(i);
                y1 = 100 * sin(i);
        glVertex2i(x, y);
                glVertex2i(x1, y1);
    }*/
                /*for(i=-300;i<=80;i++)
        {
                        //glColor3d(1,1,0);
                        glVertex2i(i, 50*sin(i/100));

                        glColor3d(1,1,1);
                        glVertex2i(i, 120*sin(i/100));

                        glColor3d(1,1,1);
                        glVertex2i(i,40*sin(i/100));

                        glColor3d(0,1,0);
                        glVertex2i(i,-40*sin(i/100));
        }*/

                for(i=120;i<=200;i++)
                {
                        /*glColor3d(1,0,0);*/
                        for(j=-300;j<=80;j++)
                        {
                               // glColor3ub(255,140,0);
                                glVertex2i(j,i+18*sin(j/54));
                        }
                }

                for(i=40;i<120;i++)
                {
                        /*glColor3d(1,0,0);*/
                        for(j=-300;j<=80;j++)
                        {
                                glColor3ub(255,250,250);
                                glVertex2i(j,i+18*sin(j/54));
                        }
                }
                for(i=-40;i<40;i++)
                {
                        /*glColor3d(1,0,0);*/
                        for(j=-300;j<=80;j++)
                        {
                                glColor3ub(0,139,0);
                                glVertex2i(j,i+18*sin(j/54));
                        }
                }

        /*for(i=-40;i<=200;i++)
        {
                glColor3d(1,1,1);
                glVertex2i(-300,i);
                glColor3d(1,1,1);
                glVertex2i(80,i);

        }*/
        /*for(i=-40;i<=-100;i++)
        {

                glVertex2i(0,i+100);
                //glVertex2i(80,i);

        }*/
        for(i=0;i<(2*pi);i+=0.01)
        {
                x = -110 + 40 * cos(i);
                y = 64 + 40 * sin(i);
                glColor3ub(0,0,255);
                glVertex2i(x,y);
        }
        for(i=1;i<=26;i++)
        {
                for(j=0;j<40;j+=0.0001)
                {
                        x = -110 + j * cos(pi*i/12);
                        y = 64 + j* sin(pi*i/12);
                        glColor3ub(0,0,254);
                        glVertex2i(x,y);
                }
        }

        /*for(i=-300;j<=80;i++)
        {
                        glColor3d(0,1,1);
                        glVertex2i(i,-42);
        }*/

    glEnd();
    glFlush();
}

void myInit2 (void)
{
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0f,1.0f, 0.0f);

    // breadth of picture boundary is 1 pixel
    glPointSize(50.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}


int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0,0);

    // Giving name to window
    glutCreateWindow("Flag Drawing");
    myInit();

    glutDisplayFunc(display);
         /*glutCreateWindow("Circle Drawing");
        myInit2();
         glutDisplayFunc(display2);*/
    glutMainLoop();
        return 0;
}
#endif
