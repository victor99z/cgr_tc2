#include "GL/freeglut.h";

// Respond to arrow keys (rotate snowman)
void SpecialKeys(unsigned char key, int x, int y)
{

    if (key == GLUT_KEY_LEFT)
        yRot -= 10.0f;

    if (key == GLUT_KEY_RIGHT)
        yRot += 10.0f;

    yRot = (GLfloat)((const int)yRot % 360);

    // Refresh the Window
    glutPostRedisplay();
}
