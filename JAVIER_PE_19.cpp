// Exercise Q19 — Interleaved + Indexed Hexagon [Hard]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat hexagon[] = {
    // x,      y,     z,      r,    g,    b
     0.0f,   0.7f,   0.0f,   1.0f, 0.0f, 0.0f,  // red
     0.61f,  0.35f,  0.0f,   1.0f, 0.5f, 0.0f,  // orange
     0.61f, -0.35f,  0.0f,   1.0f, 1.0f, 0.0f,  // yellow
     0.0f,  -0.7f,  0.0f,   0.0f, 1.0f, 0.0f,  // green
    -0.61f, -0.35f, 0.0f,   0.0f, 0.5f, 1.0f,  // cyan
    -0.61f,  0.35f, 0.0f,   0.5f, 0.0f, 1.0f   // purple
};


GLuint indices[] = {
    0, 1, 2, 3, 4, 5
};

void displayHexagon()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    GLsizei stride = 6 * sizeof(GLfloat);

    glVertexPointer( 3, GL_FLOAT, stride, hexagon);
    glColorPointer(3, GL_FLOAT, stride, hexagon + 3);

    glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_INT, indices);
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
    glutCreateWindow("Exercise Q19 - Interleaved + Indexed Hexagon");
    glutDisplayFunc(displayHexagon);
    glutMainLoop();
    return 0;
}