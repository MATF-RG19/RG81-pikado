#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
static float value_translation_y,value_translation_z,value_self_rotation;
static int timer_active;
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_display(void);
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 840);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    value_translation_y=0;
    value_translation_z=300;
    value_self_rotation=-10;
    timer_active = 0;
    glClearColor(1,1,1, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
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
        break;
    }
}
static void on_timer(int value)
{
    if (value != 0)
        return;
    value_translation_z-=19;
    if(value_translation_z>=50){
        value_translation_y += 2;
        value_self_rotation+=.5;
    }
    else if (value_translation_z<0){
        value_translation_y-=1.5;
        value_self_rotation+=.5;
    }
    if(value_translation_z>=-250){
        glutPostRedisplay();
        if (timer_active)
            glutTimerFunc(50, on_timer, 0);
    }
}
static void on_reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) width / height, 1, 1500);
}
static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 400, 0, 0, 0, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0, value_translation_y, value_translation_z);
    glRotatef(value_self_rotation, 1, 0, 0);
    glColor3f(1,0 , 0);
    glutWireCone(10, 50, 20, 2);
    glPopMatrix();
    glTranslatef(0,0,-250);
    glColor3f(0, 0, 0);
    float x,y;
    float i=0;
    while(i <= 360){
        glBegin(GL_TRIANGLES);
        x=30*cos(i);
        y=30*sin(i);
        glVertex2f(x, y);
        i=i+0.5;
        x=20*cos(i);
        y=20*sin(i);
        glVertex2f(x, y);
        glVertex2f(0, 0);
        glEnd();
        i=i+0.5;
    }
    glEnd();
        glutSwapBuffers();
}
