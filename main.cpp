#include "iostream"
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "Triangle.cpp"

int main(int argc, char *argv[])
{
    float x, y;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Triangle");
    glutDisplayFunc(Triangle::DrawTriangle);
    glutMainLoop();

    return EXIT_SUCCESS;
}
