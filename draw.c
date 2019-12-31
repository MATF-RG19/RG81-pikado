#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
static void on_display();
static void on_reshape(int width, int height);
void draw_dart();
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);

    glEnable(GL_DEPTH_TEST);

    glClearColor(0.75,0.75,0.75,1);
    
    glutMainLoop();

    return 0;
}
void on_reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width/height, 1, 1000);
}
void draw_dart(){
    glShadeModel(GL_SMOOTH);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,0,-1);
        glVertex3f(0,1,-0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(0,0,1);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex3f(0,0,-1);
        glVertex3f(0,-1,-0.5);
        glVertex3f(0,-1,0.5);
        glVertex3f(0,0,1);
    glEnd();
        glColor3f(0,1,0);
        glBegin(GL_POLYGON);
        glVertex3f(0,0,-1);
        glVertex3f(1,0,-0.5);
        glVertex3f(1,0,0.5);
        glVertex3f(0,0,1);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex3f(0,0,-1);
        glVertex3f(-1,0,-0.5);
        glVertex3f(-1,0,0.5);
        glVertex3f(0,0,1);
    glEnd();
    glTranslatef(0,0,-4.3);
    GLUquadric* quad=gluNewQuadric();
    gluCylinder(quad,0.1,0.1,4.2,50,50);
    glTranslatef(0,0,-0.2);
    gluCylinder(quad,0.2,0.1,0.2,50,50);
    glTranslatef(0,0,-0.2);
    gluCylinder(quad,0.2,0.2,1.5,50,50);
    glTranslatef(0,0,-0.2);
    gluCylinder(quad,0.1,0.2,0.2,50,50);
    glTranslatef(0,0,-2.0);
    gluCylinder(quad,0.05,0.1,2,50,50);
    
    
    
}
void on_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(2,3, 5,
              0, 0, 0,
              0, 1, 0);

    glScalef(0.5,0.5,0.5);
    glRotatef(45,0,0,1);
    
    draw_dart();
    glutSwapBuffers();
}
