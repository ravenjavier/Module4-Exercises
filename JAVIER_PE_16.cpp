// Exercise Q16 — glDrawArrays vs. glDrawElements, Side by Side [Hard]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat quadArrays[] = {
    // triangle 1
    -0.85f,  0.4f,
    -0.15f,  0.4f,
    -0.15f, -0.4f,

    // triangle 2
    -0.85f,  0.4f,
    -0.15f, -0.4f,
    -0.85f, -0.4f
};

GLfloat quadElements[] = {
    -0.05f,  0.4f,   // top-left
     0.65f,  0.4f,   // top-right
     0.65f, -0.4f,   // bottom-right
    -0.05f, -0.4f    // bottom-left
};

GLuint quadIndices[] = {
    0, 1, 2,
    0, 2, 3
};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);


    glVertexPointer( 2, GL_FLOAT, 0, quadArrays);
    glColor3f(0.2f, 0.6f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glVertexPointer(2, GL_FLOAT, 0, quadElements);
    glColor3f(1.0f, 0.4f, 0.2f);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, quadIndices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q16 - glDrawArrays vs. glDrawElements, Side by Side");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}