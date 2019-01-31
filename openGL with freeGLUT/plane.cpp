#if 0
#include<Windows.h>
#include<iostream>
#include <GL\glut.h>
 GLfloat xRotated, yRotated, zRotated;
void init(void)
{
glClearColor(0,0,0,0);

}

void DrawCube(void)
{

     glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-10.5f);
    glRotatef(xRotated,1.0,0.0,0.0);
     //rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
     //rotation about Z axis
   glRotatef(zRotated,0.0,0.0,1.0);
  glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);    // Color Green
    glVertex3f( 1.0f, -1.0f,-1.0f);
    glVertex3f(1.0f, 1.0f,-7.0f);
    glVertex3f(-1.0f, 1.0f, -3.0f);
    glVertex3f( -1.0f, -1.0f, 3.0f);
  glEnd();
  glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 1.0f, -1.0f,-1.0f);
    glVertex3f(1.0f, 1.0f,-3.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f( -1.0f, -1.0f, 2.0f);
  glEnd();
  glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f, -1.0f,-1.0f);
    glVertex3f(1.0f, 1.0f,-3.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( -1.0f, -1.0f, 1.0f);
  glEnd();
glFlush();
}


void animation(void)
{

     yRotated += 0.01;
     xRotated += 0.02;
    DrawCube();
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

int main(int argc, char** argv){

glutInit(&argc, argv);
//we initizlilze the glut. functions
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutCreateWindow(argv[0]);
init();
glutDisplayFunc(DrawCube);
glutReshapeFunc(reshape);
//Set the function for the animation.
glutIdleFunc(animation);
glutMainLoop();
return 0;
}
#endif
