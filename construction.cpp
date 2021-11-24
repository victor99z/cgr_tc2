#include "GL/freeglut.h"
#include "GL/gl.h"

static GLfloat yRot = 0.0f;

void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w / (GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// This function does any needed initialization on the rendering context.  Here it sets up and initializes the lighting for the scene.
void SetupRC()
{

    // Light values and coordinates
    GLfloat whiteLight[] = {0.05f, 0.05f, 0.05f, 1.0f};
    GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
    GLfloat lightPos[] = {-10.f, 5.0f, 5.0f, 1.0f};

    glEnable(GL_DEPTH_TEST); // Hidden surface removal
    glFrontFace(GL_CCW);     // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);  // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sourceLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.4f, 0.25f, 0.50f, 1.0f);
}

void createTorre(float x, float y, float z)
{
    // Torres
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glPushMatrix();
    //glTranslatef(-0.6f, 0.8f, -0.9f);
    glTranslatef(x, y, z);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCylinder(0.4f, 1.2f, 20.0f, 10.0f);
    glPopMatrix();

    // cone da parte de cima da torre
    glColor4f(1.0f, 0.4f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.4f, 0.6f, 20.0f, 20.0f);
    glPopMatrix();
}

// Called to draw scene
void Render(void)
{

    GLUquadricObj *pObj; // Quadric Object

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix state and do the rotations
    glPushMatrix();

    // Move object back and do in place rotation
    glTranslatef(0.0f, -1.0f, -5.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    // Draw something
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    // white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Cria as torres usando as funcoes.
    createTorre(-3.5f, 0.8f, -9.0f);
    createTorre(-1.2f, 0.8f, -6.0f);
    createTorre(3.0f, 0.8f, -6.0f);

    // Parede Frontal
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-0.8f, -0.4f, 0);
    glBegin(GL_QUADS);
    glVertex3f(4.0, 1.0, -6);
    glVertex3f(0.0, 1.0, -6);
    glVertex3f(0.0, 0.0, -6);
    glVertex3f(4.0, 0.0, -6);
    glEnd();
    glPopMatrix();

    //Outra parede porem lateral
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-0.8f, -0.4f, 0);
    glBegin(GL_QUADS);
    glVertex3f(-0.6f, 0.10f, -5); // blue
    glVertex3f(-0.6f, 1.0f, -5);  // red
    glVertex3f(-1.8f, 0.8f, -6);  // marrom
    glVertex3f(-1.8f, 0.3f, -6);  // green
    glEnd();
    glPopMatrix();

    // Casinha do meio

    glColor4f(1.0f, 146 / 255.0, 56 / 255.0f, 0.0f);
    glPushMatrix();
    glTranslatef(1.0f, 0.2f, -6.0f);
    glRotatef(15.0, 0.0, 1.0, 0.0);
    glutSolidCube(1.2);
    glPopMatrix();

    // Telhado da casa
    glColor4f(0.65f, 146 / 255.0, 56 / 255.0f, 0.0f);

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.65f, 1.3f, -2); // blue
    glVertex3f(0.1f, 0.85f, -2); // red
    glVertex3f(1.2f, 0.85f, -2); // marrom
    glEnd();
    glPopMatrix();

    // "Sombra do telhado"
    glColor4f(0.8f, 146 / 255.0, 56 / 255.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.1f, 0.0, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.45f, 1.25f, -2); // blue
    glVertex3f(0.25f, 0.87f, -2); // red
    glVertex3f(1.0f, 0.87f, -2);  // marrom
    glEnd();
    glPopMatrix();

    // Predio atrás
    glColor4f(0.81f, 143 / 255.0, 95 / 255.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-0.5, 0.4, -1);
    glBegin(GL_QUADS);
    glVertex3f(1.2f, 1.4f, -6);  // marrom
    glVertex3f(0.40f, 1.4f, -6); // blue
    glVertex3f(0.40f, 0.1f, -6); // red
    glVertex3f(1.2f, 0.1f, -6);  // marrom
    glEnd();
    glPopMatrix();

    // Telhado do prédio
    glColor4f(0.6f, 92 / 255.0, 56 / 255.0f, 0.0f);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(1.2f - 0.5f, 1.4f + 0.4f, -7);                       // marrom
    glVertex3f((0.4f + 1.2f) / 2 - 0.5f, (1.4f + 0.3f) + 0.6f, -7); // blue
    glVertex3f(0.4f - 0.5f, 1.4f + 0.4f, -7);                       // red
    glEnd();
    glPopMatrix();

    /**
     * Pontos para desenhar DEBUG
     */

    // glColor4f(0, 1.0f, 0.0f, 0.0f);
    // glPushMatrix();
    // glPointSize(10.0f);
    // glBegin(GL_POINTS);
    // glColor4f(0, 1.0f, 0.0f, 0.0f);
    // glVertex3f(1.2f - 0.5f, 1.4f + 0.4f, -7); // green
    // // glColor4f(0.6, 0.3f, 0.0f, 3.0f);
    // // glVertex3f(-2.0f, 0.8f, -6); // marrom
    // glColor4f(1.0, 0.0f, 0.0f, 0.0f);
    // glVertex3f((0.4f + 1.2f) / 2 - 0.5f, (1.4f + 0.3f) + 0.6f, -7); // red
    // glColor4f(0.0, 0.0f, 1.0f, 0.0f);
    // glVertex3f(0.4f - 0.5f, 1.4f + 0.4f, -7); // blue
    // glEnd();
    // glPopMatrix();

    // Restore the matrix state
    glPopMatrix();

    // Buffer swap
    glutSwapBuffers();

    gluDeleteQuadric(pObj);
}

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

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Castelo");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(Render);
    glutKeyboardFunc(SpecialKeys);
    SetupRC();
    glutMainLoop();

    return 0;
}
