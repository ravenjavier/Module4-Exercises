// Exercise Q03 — Two Lines, One Array [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat lines[] = {
    -0.8f,  0.5f,
    -0.2f,  0.1f,
     0.2f, -0.1f,
     0.8f, -0.5f
};

void drawLines()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, lines);
    glColor3f(0.0f, 0.0f, 0.0f);
    glDrawArrays(GL_LINES, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q03 - Two Lines, One Array");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLineWidth(5.0f);
    display();
    glutDisplayFunc(drawLines);
    glutMainLoop();
    return 0;
}