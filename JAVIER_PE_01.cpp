// Exercise Q01 — Vertex Array X-Pattern Points [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat points[] = {
    -0.5f,  0.5f,
     0.5f,  0.5f,
     0.0f,  0.0f,
    -0.5f, -0.5f,
     0.5f, -0.5f
};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, points);
    glPointSize(10.0f);
    glDrawArrays(GL_POINTS, 0, 5);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q01 - Vertex Array X-Pattern Points");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
