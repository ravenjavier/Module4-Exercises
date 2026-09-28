// Exercise Q11 — Procedural Shaded Circle [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

const int SEGMENTS = 60;

GLfloat vertices[(SEGMENTS + 2) * 2];
GLfloat colors[(SEGMENTS + 2) * 3];

void createCircle()
{
    const float PI = 3.14159265359f;
    const float radius = 0.7f;

    vertices[0] = 0.0f;
    vertices[1] = 0.0f;

    colors[0] = 1.0f;
    colors[1] = 0.0f;
    colors[2] = 0.0f;

    for (int i = 0; i <= SEGMENTS; i++)
    {
        float angle = 2.0f * PI * i / SEGMENTS;

        int vertexIndex = i + 1;
        int v = vertexIndex * 2;
        int c = vertexIndex * 3;

        vertices[v] = radius * cos(angle);
        vertices[v + 1] = radius * sin(angle);

        float t = (float)i / SEGMENTS;

        colors[c] = 1.0f - t;
        colors[c + 1] = t;
        colors[c + 2] = 1.0f;
    }
}

void circle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLE_FAN, 0, SEGMENTS + 2);
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
    glutCreateWindow("Exercise Q11 - Procedural Shaded Circle");
    createCircle();
    glutDisplayFunc(circle);
    glutMainLoop();
    return 0;
}