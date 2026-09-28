#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

GLfloat vertices[] = {
     0.0f,  0.0f,   // 0 - center

     0.0f,  0.7f,   // 1 - top
     0.67f,  0.22f, // 2 - top right
     0.42f, -0.57f, // 3 - bottom right
    -0.42f, -0.57f, // 4 - bottom left
    -0.67f,  0.22f  // 5 - top left
};

GLuint indices[] = {
    0,  // center
    1,  // top
    2,  // top right
    3,  // bottom right
    4,  // bottom left
    5,  // top left
    1   // back to first outer vertex
};

void pentagon()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColor3f(0.2f, 0.6f, 1.0f);
    glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q09 - Indexed Triangle Fan Pentagon");
    glutDisplayFunc(pentagon);
    glutMainLoop();
    return 0;
}