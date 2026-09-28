// Exercise Q13 — Pinwheel via glDrawElements [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat vertices[] = {
    
    // center
     0.0f,  0.0f,  0.0f,

    // outer vertices
     0.0f,  0.8f,  0.0f,   // top
     0.8f,  0.0f,  0.0f,   // right
     0.0f, -0.8f,  0.0f,   // bottom
    -0.8f,  0.0f,  0.0f    // left
};

GLuint indices[] = {
    0, 1, 2,   // triangle 1
    0, 2, 3,   // triangle 2
    0, 3, 4,   // triangle 3
    0, 4, 1    // triangle 4
};

void pinwheel()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColor3f(0.2f, 0.6f, 1.0f);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q13 - Pinwheel via glDrawElements");
    glutDisplayFunc(pinwheel);
    glutMainLoop();
    return 0;
}