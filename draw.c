#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
static void on_display();
static void on_timer(int value);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key,int x,int y);
void draw_dart();
static int timer_active=0,width=800,height=800;
static float animation_parametar=0,animation_parametar1=0;
int drawer=0;
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);
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
    glColor3f(0,0,1);
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
void draw_dart1(){
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
    glColor3f(0,0,1);
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
static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    case 32:
        if (!timer_active) {
            glutTimerFunc(20, on_timer, 0);
            timer_active = 1;
        }
        break;
    case 'Q':
    case 'q':
        timer_active = 0;
        draw_dart1();
        drawer=1;
        glutPostRedisplay();
        break;
    case 'F':
    case 'f':
        glutFullScreen();
    }
}
static void on_timer(int value)
{
    if (value != 0)
        return;
    if(timer_active && drawer==0){
        if(animation_parametar<=45)
            animation_parametar=animation_parametar+0.5;
            glutPostRedisplay();
            glutTimerFunc(10, on_timer, 0);
    }
    if(timer_active && drawer==1){
        if(animation_parametar1<=45)
            animation_parametar1=animation_parametar1+0.5;
            glutPostRedisplay();
            glutTimerFunc(10, on_timer, 0);
    }
}
void on_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,1, 3,
              0, 0, 0,
              0, 1, 0);
    glPushMatrix();
        glScalef(0.05,0.05,0.05);
        glRotatef(10,1,0,0);
        if(drawer==0){
        glRotatef(45+animation_parametar*6,0,0,1);
        glTranslatef(0,0,21-animation_parametar);
            draw_dart();
        }
        else if(drawer==1){
        glRotatef(45+animation_parametar1*6,0,0,1);
        glTranslatef(0,0,21-animation_parametar1);
            draw_dart1();
        }
        
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-0.3,-6);
        glColor3f(0,0,0);
        GLUquadric* quad=gluNewQuadric();
        gluDisk(quad,0.00001,0.3,40,40);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-2.2,-6.01);
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
            glVertex3f(0.7,0,0);
            glVertex3f(0.7,2.5,0);
            glVertex3f(-0.7,2.5,0);
            glVertex3f(-0.7,0,0);
        glEnd();
        glTranslatef(0,0,0);
        glColor3f(0,0,0);
        glBegin(GL_LINE_LOOP);
            glVertex3f(0,2.45,0);
            glVertex3f(.3,2,0);
            glVertex3f(-.3,2,0);
        glEnd();
        glTranslatef(-0.2,0,0.1);
        glColor3f(0.5,0.5,0.5);
        
        glBegin(GL_QUADS);
            glVertex3f(0.5,1.3,0);
            glVertex3f(0.5,1.35,0);
            glVertex3f(0.8,1.35,0);
            glVertex3f(.8,1.3,0);
        glEnd();
    glPopMatrix();
    
    
    glutSwapBuffers();
}
