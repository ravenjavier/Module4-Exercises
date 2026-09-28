// Exercise Q14 — Colored Quad Strip Staircase [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat vertices[] = {
    // x,     y
    -0.9f, -0.7f,
    -0.9f, -0.4f,

    -0.45f, -0.7f,
    -0.45f, -0.1f,

     0.0f, -0.7f,
     0.0f,  0.2f,

     0.45f, -0.7f,
     0.45f,  0.5f,

     0.9f, -0.7f,
     0.9f,  0.8f
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,

    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,

    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,

    1.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,

    1.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f
};

void quadStrip()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_QUAD_STRIP, 0, 10);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q14 - Colored Quad Strip Staircase");
    glutDisplayFunc(quadStrip);
    glutMainLoop();
    return 0;
}