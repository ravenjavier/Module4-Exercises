// Exercise Q04 — Square Plus Outline, Same Array
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat square[] = {
    -0.5f,  0.5f,
     0.5f,  0.5f,
     0.5f, -0.5f,
    -0.5f, -0.5f
};

void drawSquare()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, square);
    glColor3f(0.2f, 0.6f, 1.0f);
    glDrawArrays(GL_QUADS, 0, 4);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q04 - Square Plus Outline, Same Array");
    glutDisplayFunc(drawSquare);
    glutMainLoop();
    return 0;
}