#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat triangle[] = {
     0.0f,  0.6f,
    -0.6f, -0.5f,
     0.6f, -0.5f
};

GLfloat quad[] = {
    -0.5f,  0.5f,
     0.5f,  0.5f,
     0.5f, -0.5f,
    -0.5f, -0.5f
};

GLfloat pentagon[] = {
     0.0f,  0.65f,
     0.62f,  0.20f,
     0.38f, -0.55f,
    -0.38f, -0.55f,
    -0.62f,  0.20f
};

int currentShape = 1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    if (currentShape == 1)
    {
        glVertexPointer(2, GL_FLOAT, 0, triangle);
        glColor3f(1.0f, 0.0f, 0.0f);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    else if (currentShape == 2)
    {
        glVertexPointer(2, GL_FLOAT, 0, quad);
        glColor3f(0.0f, 0.7f, 0.2f);
        glDrawArrays(GL_QUADS, 0, 4);
    }
    else if (currentShape == 3)
    {
        glVertexPointer(2, GL_FLOAT, 0, pentagon);
        glColor3f(0.2f, 0.4f, 1.0f);
        glDrawArrays(GL_POLYGON, 0, 5);
    }
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == '1')
    {
        currentShape = 1;
    }
    else if (key == '2')
    {
        currentShape = 2;
    }
    else if (key == '3')
    {
        currentShape = 3;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Q18 - Keyboard Switched Vertex Arrays");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}