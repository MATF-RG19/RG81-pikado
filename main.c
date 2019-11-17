#include <GL/glut.h>

static void on_display(void);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(on_display);
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(30, (float) 300 / 300, 0, 20);
    gluLookAt(0, 0, 15, 0, 0, 0, 0, 1, 0);
    glBegin(GL_QUADS);
    /*plafon i pod*/
    glColor3f(0,0,1);
    glVertex3f(-3.2,-3.2,3.2);
    glVertex3f(3.2,-3.2,3.2);
    glVertex3f(3.2,3.2,3.2);
    glVertex3f(-3.2,3.2,3.2);
    /*glVertex3f(-3.5,3.5,-3.5);
    glVertex3f(3.2,3.2,-3.2);
    glVertex3f(3.2,3.2,3.2);
    glVertex3f(-3.2,3.2,3.2);*/
    /*centralni zid*/
    glColor3f(0,1,1);
    glVertex3f(-3.2,-3.2,-3.2);
    glVertex3f(3.2,-3.2,-3.2);
    glVertex3f(3.2,3.2,-3.2);
    glVertex3f(-3.2,3.2,-3.2);
    /*desni zid*/
    glColor3f(0,0.6,0.8);
    glVertex3f(3.2,3.2,3.2);
    glVertex3f(3.2,-3.2,3.2);
    glVertex3f(3.2,-3.2,-3.2);
    glVertex3f(3.2,3.2,-3.2);
    /*levi zid*/
    glColor3f(0,0.6,0.8);
    glVertex3f(-3.2,3.2,3.2);
    glVertex3f(-3.2,-3.2,3.2);
    glVertex3f(-3.2,-3.2,-3.2);
    glVertex3f(-3.2,3.2,-3.2);
    glEnd();  
    glutSwapBuffers();
}
