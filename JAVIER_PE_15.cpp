// Exercise Q15 — Fully Array-Based Scene [Hard]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat sunVertices[] = {

    // center
     0.0f,  0.55f,

    // outer vertices
     0.0f,  0.75f,
     0.14f, 0.64f,
     0.25f, 0.55f,
     0.14f, 0.46f,
     0.0f,  0.35f,
    -0.14f, 0.46f,
    -0.25f, 0.55f,
    -0.14f, 0.64f
};

GLuint sunIndices[] = {
    0, 1, 2,
    0, 2, 3,
    0, 3, 4,
    0, 4, 5,
    0, 5, 6,
    0, 6, 7,
    0, 7, 8,
    0, 8, 1
};

GLfloat mountain[] = {
    -0.95f, -0.45f,
    -0.55f,  0.20f,
    -0.15f, -0.45f,

    -0.25f, -0.45f,
     0.30f,  0.30f,
     0.85f, -0.45f
};


GLfloat ground[] = {
    -1.0f, -0.45f,
     1.0f, -0.45f,
     1.0f, -1.0f,
    -1.0f, -1.0f
};

void scenery()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    // ground
    glVertexPointer(2, GL_FLOAT, 0, ground);

    glColor3f(0.2f, 0.7f, 0.2f);
    glDrawArrays( GL_QUADS, 0, 4);

    // mountain
    glVertexPointer(2, GL_FLOAT, 0, mountain);
    glColor3f(0.35f, 0.35f, 0.35f);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // sun
    glVertexPointer(2, GL_FLOAT, 0, sunVertices);
    glColor3f(1.0f, 0.75f, 0.0f);
    glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, sunIndices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

void display()
{
    // Sky background
    glClearColor(0.4f , 0.7f, 1.0f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q15 - Fully Array-Based Scene");
    display();
    glutDisplayFunc(scenery);
    glutMainLoop();
    return 0;
}