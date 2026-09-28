// Exercise Q08 — Three Triangles, One Array [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat triangles[] = {

    // triangle 1 - left
    -0.9f, -0.5f,
    -0.6f,  0.5f,
    -0.3f, -0.5f,

    // triangle 2 - center
    -0.3f, -0.5f,
     0.0f,  0.5f,
     0.3f, -0.5f,

    // triangle 3 - right
     0.3f, -0.5f,
     0.6f,  0.5f,
     0.9f, -0.5f
};

void drawTriangles()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, triangles);
    glColor3f(0.2f, 0.6f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 9);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q08 - Three Triangles, One Array");
    glutDisplayFunc(drawTriangles);
    glutMainLoop();
    return 0;
}