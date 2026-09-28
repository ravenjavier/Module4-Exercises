// Exercise Q06 — glDrawElements Index Order [Easy]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat vertices[] = {
     0.0f,  0.6f,
    -0.6f, -0.5f,
     0.6f, -0.5f
};

GLuint indices[] = {
    2, 0, 1
};

void index()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColor3f(1.0f, 1.0f, 0.0f);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q06 - glDrawElements Index Order");
    glutDisplayFunc(index);
    glutMainLoop();
    return 0;
}