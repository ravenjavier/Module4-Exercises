// Exercise Q05 — GLint Vertex Data Type [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

// Step 1: Define vertex data using GLint
GLint triangle[] = {
     0,  100,   // Top
   -100, -100,  // Bottom-left
    100, -100   // Bottom-right
};

void displayTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, triangle);
    glPushMatrix();
    glScalef(0.008f, 0.008f, 1.0f);
    glColor3f(0.0f, 0.5f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q05 - GLint Vertex Data Type");
    glutDisplayFunc(displayTriangle);
    glutMainLoop();
    return 0;
}