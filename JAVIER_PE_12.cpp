// Exercise Q12 — Interleaved Array Quad [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat quad[] = {
    // x,    y,    z,    r,    g,    b
    -0.5f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // top left
     0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f,  // top right
     0.5f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 0.0f   // bottom left
};

void arrayQuad()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    GLsizei stride = 6 * sizeof(GLfloat);
    glVertexPointer(3, GL_FLOAT, stride, quad);
    glColorPointer(3, GL_FLOAT, stride, quad + 3);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q12 - Interleaved Array Quad");
    glutDisplayFunc(arrayQuad);
    glutMainLoop();
    return 0;
}