// Exercise Q17 — Procedural Gear Shape [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

const int TEETH = 12;
const int VERTEX_COUNT = TEETH * 2;

GLfloat vertices[VERTEX_COUNT * 2];

GLuint evenIndices[TEETH * 3 / 2];
GLuint oddIndices[TEETH * 3 / 2];

void createGear()
{
    const float PI = 3.14159265359f;

    float outerRadius = 0.75f;
    float innerRadius = 0.55f;

    for (int i = 0; i < VERTEX_COUNT; i++)
    {
        float angle = 2.0f * PI * i / VERTEX_COUNT;
        float radius;
        if (i % 2 == 0)
            radius = outerRadius;
        else
            radius = innerRadius;

        vertices[i * 2] =
            radius * cos(angle);

        vertices[i * 2 + 1] =
            radius * sin(angle);
    }

    int evenPos = 0;
    int oddPos = 0;

    for (int i = 0; i < TEETH; i++)
    {
        int center = 0;
        int current = i * 2 + 1;
        int next = (i * 2 + 2) % VERTEX_COUNT;

        if (i % 2 == 0)
        {
            evenIndices[evenPos++] = center;
            evenIndices[evenPos++] = current;
            evenIndices[evenPos++] = next;
        }
        else
        {
            oddIndices[oddPos++] = center;
            oddIndices[oddPos++] = current;
            oddIndices[oddPos++] = next;
        }
    }
}

void gearShape()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);

    // even teeth
    glColor3f(1.0f, 0.5f, 0.0f);
    glDrawElements(GL_TRIANGLES, TEETH / 2 * 3, GL_UNSIGNED_INT, evenIndices);

    // odd teeth
    glColor3f(0.2f, 0.5f, 1.0f);
    glDrawElements(GL_TRIANGLES, TEETH / 2 * 3, GL_UNSIGNED_INT, oddIndices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    createGear();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q17 - Procedural Gear Shape");
    display();
    glutDisplayFunc(gearShape);
    glutMainLoop();
    return 0;
}