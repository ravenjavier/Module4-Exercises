// Exercise Q10 — Checkerboard Row via glDrawElements [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat vertices[] = {
    -0.8f,  0.4f,   // 0 - top left
    -0.4f,  0.4f,   // 1
     0.0f,  0.4f,   // 2
     0.4f,  0.4f,   // 3
     0.8f,  0.4f,   // 4 - top right

    -0.8f, -0.4f,   // 5 - bottom left
    -0.4f, -0.4f,   // 6
     0.0f, -0.4f,   // 7
     0.4f, -0.4f,   // 8
     0.8f, -0.4f    // 9 - bottom right
};

GLuint quad1[] = {0, 1, 6, 5};
GLuint quad2[] = {1, 2, 7, 6};
GLuint quad3[] = {2, 3, 8, 7};
GLuint quad4[] = {3, 4, 9, 8};

void drawQuad(GLuint indices[])
{
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, indices);
}

void quad()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawQuad(quad1);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawQuad(quad2);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawQuad(quad3);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawQuad(quad4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

void display()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // gray background
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q10 - Checkerboard Row via glDrawElements");
    display();
    glutDisplayFunc(quad);
    glutMainLoop();
    return 0;
}