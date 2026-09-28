// Exercise Q02 — Filled Hexagon via Vertex Array [Easy]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat hexagon[] = {
     0.0f,  0.6f,
     0.52f,  0.3f,
     0.52f, -0.3f,
     0.0f, -0.6f,
    -0.52f, -0.3f,
    -0.52f,  0.3f
};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, hexagon);
    glColor3f(0.2f, 0.6f, 1.0f);
    glDrawArrays(GL_POLYGON, 0, 6);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q02 - Filled Hexagon via Vertex Array");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}