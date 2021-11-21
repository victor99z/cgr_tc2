#include <GL/gl.h>

class Triangle
{
private:
    /* data */
public:
    static void DrawTriangle();

    Triangle(/* args */);

    ~Triangle();
};

Triangle::Triangle(/* args */)
{
}

void Triangle::DrawTriangle()
{
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 1.3);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.7, 0.7, 0);
    glVertex3f(0.7, 0.7, 0);
    glVertex3f(0, -1, 0);
    glEnd();

    glFlush();
}