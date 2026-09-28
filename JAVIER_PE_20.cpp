// Exercise Q20 — Capstone: Procedural Flower Scene [Hard]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

const int PETALS = 10;

GLfloat petalVertices[PETALS * 3 * 2];
GLfloat petalColors[PETALS * 3 * 3];

GLfloat discVertices[42 * 2];
GLuint discIndices[42];

GLfloat ground[] = {
    -1.0f, -0.8f,
     1.0f, -0.8f,
     1.0f, -1.0f,
    -1.0f, -1.0f
};

// flower petals
void createPetals()
{
    const float PI = 3.14159265359f;

    float centerX = 0.0f;
    float centerY = 0.0f;

    float innerRadius = 0.12f;
    float outerRadius = 0.65f;

    for (int i = 0; i < PETALS; i++)
    {
        float angle = 2.0f * PI * i / PETALS;

        float angle1 = angle - 0.20f;
        float angle2 = angle + 0.20f;

        int v = i * 6;
        int c = i * 9;

        petalVertices[v] = centerX + innerRadius * cos(angle);
        petalVertices[v + 1] = centerY + innerRadius * sin(angle);

        petalVertices[v + 2] = centerX + outerRadius * cos(angle1);
        petalVertices[v + 3] = centerY + outerRadius * sin(angle1);

        petalVertices[v + 4] = centerX + outerRadius * cos(angle2);
        petalVertices[v + 5] = centerY + outerRadius * sin(angle2);

        float r = 0.8f + 0.2f * cos(angle);
        float g = 0.3f + 0.3f * sin(angle);
        float b = 0.5f + 0.4f * cos(angle);

        for (int j = 0; j < 3; j++)
        {
            petalColors[c + j * 3] = r;
            petalColors[c + j * 3 + 1] = g;
            petalColors[c + j * 3 + 2] = b;
        }
    }
}

void createDisc()
{
    const float PI = 3.14159265359f;
    const int SEGMENTS = 40;

    float centerX = 0.0f;
    float centerY = 0.0f;
    float radius = 0.18f;

    discVertices[0] = centerX;
    discVertices[1] = centerY;

    for (int i = 0; i <= SEGMENTS; i++)
    {
        float angle = 2.0f * PI * i / SEGMENTS;
        int v = (i + 1) * 2;
        discVertices[v] = centerX + radius * cos(angle);
        discVertices[v + 1] = centerY + radius * sin(angle);
    }

    discIndices[0] = 0;
    for (int i = 0; i <= SEGMENTS; i++)
    {
        discIndices[i + 1] = i + 1;
    }
}

void scenery()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    // ground
    glVertexPointer(2, GL_FLOAT, 0, ground);
    glColor3f(0.2f, 0.7f, 0.2f);
    glDrawArrays(GL_QUADS, 0, 4);


    // flower petals
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, petalVertices);
    glColorPointer(3, GL_FLOAT, 0, petalColors);
    glDrawArrays(GL_TRIANGLES, 0, PETALS * 3);

    // center disc
    glDisableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, discVertices);
    glColor3f(1.0f, 0.7f, 0.0f);
    glDrawElements(GL_TRIANGLE_FAN, 42, GL_UNSIGNED_INT, discIndices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

void display()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    createPetals();
    createDisc();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q20 - Procedural Flower Scene");
    display();
    glutDisplayFunc(scenery);
    glutMainLoop();
    return 0;
}