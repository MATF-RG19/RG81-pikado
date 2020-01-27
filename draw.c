#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "image.h"
#include<unistd.h>
#define PI 3.1415926535


static GLuint names[1];


static void on_display();
static void on_timer(int value);
static void on_timer1(int value);
static void on_timer2(int value);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key,int x,int y);


static void initialize();


void show_text();
void draw_dart();
void draw_target();
void draw_strength();
void count_score();


static int timer_active=0,width=800,height=800,timer_active1=0,timer_active2=0,s=1,brojac=0,score=0;
static float animation_parametar=0,move_right=0,move_up=0,strenth_parametar=1;


int window_size=0,space=0,move_left=0,move_down=0;
double x,y,z;  


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
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    GLfloat light_position[] = { -30, 150, 220, 0 };
    GLfloat light_ambient[] = { 0, 0, 0, 1 };
    GLfloat light_diffuse[] = { 1, 1, 1, 1 };
    GLfloat light_specular[] = { 1, 1, 1, 1 };
    GLfloat model_ambient[] = { 0.4, 0.4, 0.4, 1 };


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
    glEnable(GL_COLOR_MATERIAL);
    
    
    x=0;
    y=0;
    z=-0.1;
    
    
    //initialize();
    
    glutMainLoop();

    return 0;
}

void count_score(){ //fja koja racuna skor na osnovu Pitagorine teoreme preko razdaljine koordinata (x,y) od centra i odredjivanja kojem krugu pripada poluprecnik r

    
    if(strenth_parametar>39.6 && strenth_parametar<43.06)
        y=0.045;
    
    else if(strenth_parametar>43.06 && strenth_parametar<46.52)
        y=0.09;
    
    else if(strenth_parametar>46.52 && strenth_parametar<50.6)
        y=0.135;
    
    else if(strenth_parametar>50.6 && strenth_parametar<55.0)
        y=0.18;
    
    else if(strenth_parametar>55.0 && strenth_parametar<60.5)
        y=0.21;
    
    else if(strenth_parametar>60.5 && strenth_parametar<65.8)
        y=0.275;
    
    else if(strenth_parametar>65.8 && strenth_parametar<71.6)
        y=0.325;
    
    else if(strenth_parametar>71.6 && strenth_parametar<77.5)
        y=0.385;
    
    else if(strenth_parametar>77.5 && strenth_parametar<84.5)
        y=0.445;
    
    else if(strenth_parametar>84.5 && strenth_parametar<93)
        y=0.495;
    
    else if(strenth_parametar>93)
        y=100;
    
    
    
    else if(strenth_parametar>35.93 && strenth_parametar<39.6)
        y=-0.045;
    
    else if(strenth_parametar>32.3 && strenth_parametar<35.93)
        y=-0.09;
    
    else if(strenth_parametar>28.65 && strenth_parametar<32.3)
        y=-0.135;
    
    else if(strenth_parametar>25.0 && strenth_parametar<28.65)
        y=-0.18;
    
    else if(strenth_parametar>21.33 && strenth_parametar<25.0)
        y=-0.21;
    
    else if(strenth_parametar>17.78 && strenth_parametar<21.33)
        y=-0.275;
    
    else if(strenth_parametar>14.28 && strenth_parametar<17.78)
        y=-0.335;
    
    else if(strenth_parametar>11.3 && strenth_parametar<14.28)
        y=-0.385;
    
    else if(strenth_parametar>7.85 && strenth_parametar<11.3)
        y=-0.445;
    
    else if(strenth_parametar>5 && strenth_parametar<7.85)
        y=-0.495;
    
    else if(strenth_parametar<5)
        y=-100;
    
    double r=sqrt(x*x+y*y);

    
    if(r>0 && r<0.05)
        score+=10;
    
    else 
        if(r>0.05 && r<0.1)
            score+=9;
    
    else  
        if(r>0.1 && r<0.15)
            score+=8;
    
    else
        if(r>0.15 && r<0.2)
            score+=7;
        
    else
        if(r>0.2 && r<0.25)
            score+=6;
    else
        if(r>0.25 && r<0.3)
            score+=5;
        
    else
        if(r>0.3 && r<0.35)
            score+=4;
        
    else
        if(r>0.35 && r<0.4)
            score+=3;
    else
        if(r>0.4 && r<0.45)
            score+=2;
        
    else
        if(r>0.45 && r<0.5)
            score+=1;
        
    else 
        score+=0;
    
}


static void initialize(void) //inicijalizator koji sam hteo da koristim za teksture
{
    
    
    Image * image;

    glClearColor(0, 0, 0, 0);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_TEXTURE_2D);


    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    
        
    image = image_init(0, 0);
    glGenTextures(1, names);

    
    image_read(image, "123.bmp");
    
    
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    
    glBindTexture(GL_TEXTURE_2D, 0);



    image_done(image);

}



void on_reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width/height, 1, 1000);
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
            glutPostRedisplay();
            space++;
        }
        break;
    case 'x':
    case 'X':
        if(s==3){
            timer_active=0;
            glutTimerFunc(10, on_timer1, 1);
            timer_active1=1;
        }
        break;
    case 's':
    case 'S':
        if(s==1 && space!=0){
            timer_active=0;
            timer_active1=0;
            glutTimerFunc(10, on_timer2, 2);
            s++;
            timer_active2=1;
        }
        else 
            if(s==2){
                s++;
                timer_active2=0;
        }
        break;
//     case 'F':
//     case 'f':
//         if(window_size==0){
//             glutFullScreen();
//             window_size++;
//         }
//         else{
//             glutReshapeWindow(width,height);
//             window_size--;
//         }

       case 'w': //resetuje se sve
       case 'W':
            animation_parametar=0;
            strenth_parametar=1;
            timer_active=0;
            timer_active1=0;
            timer_active2=0;
            space=0;
            s=1;
           
    }
}


static void on_timer2(int value){
    if(value!=2)
        return;
    
        if(strenth_parametar<=101 && move_down==0){ // pomeramo indikator jacine gore dole i time odredjujemo strenth_parametar koji je bitan za y
            strenth_parametar=strenth_parametar+2;
            glutTimerFunc(10, on_timer, 0);
            if(strenth_parametar==101)
                move_down=1;
        }
        
        else 
            if(strenth_parametar>=1 && move_down==1){
                strenth_parametar=strenth_parametar-2;
                glutTimerFunc(10, on_timer, 0);
                if(strenth_parametar==1)
                    move_down=0;
        } 
    glutPostRedisplay();
    
    if(timer_active2){
        glutTimerFunc(10, on_timer2, 2);
    }
    
}


static void on_timer(int value)
{
    if (value != 0)
        return;
    if(timer_active && space==1){ //ako smo jednom pritsli space sve se zaustavlja
           animation_parametar=0;
           strenth_parametar=1;
           timer_active=0;
           timer_active1=0;
           timer_active2=0;
        
    }
    if(timer_active && space==4){
        glutPostRedisplay();
    }
        
}

void on_timer1(int value){ //utice na promenu animation_parametar koji utice na kretanje od pocetka ka meti
    if(value!=1)
        return;
    if(timer_active1){
                        
        if(animation_parametar<33.1)
            animation_parametar=animation_parametar+1;
        else if(animation_parametar>33.1){
            count_score();
            brojac++;
            sleep(2);
            animation_parametar=0;
            strenth_parametar=1;
            timer_active=0;
            timer_active1=0;
            timer_active2=0;
            space=0;
            s=1;
        }
        glutPostRedisplay();
        glutTimerFunc(10, on_timer1, 1);
    }

}



void show_text() //fja za tekst koja prikazuje score:##
    {
        glDisable(GL_LIGHTING);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            glLoadIdentity();
            glMatrixMode(GL_PROJECTION);
            glPushMatrix();
                glLoadIdentity();
                gluOrtho2D(0, width, 0, height);
                    glColor3f(0,0,0);
                    glRasterPos2f(20, height-70);
                    int prva_cifra=score/10;
                    int druga_cifra=score%10;
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'C');
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,':');
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,prva_cifra+'0'); //konvertujemo prvu cifru i drugu u char preko '0'+cifra
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,druga_cifra+'0');
            glPopMatrix();
            glMatrixMode(GL_MODELVIEW);
        glPopMatrix();

        glEnable(GL_LIGHTING);
    }
    
    
    
    
    

void on_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,1,3,
              0, 0, 0,
              0, 1, 0);
    
    
    
    glPushMatrix();
        glTranslatef(0,0,1);
        glScalef(0.1,0.1,0.1);
        if(move_right<=20 && move_left==0 && space==0){ //pomeranje strelice desno levo
            move_right=move_right+1;
            glutPostRedisplay();
            glutTimerFunc(10, on_timer, 0);
            if(move_right==20)
                move_left=1;
        }
        else if(move_right>=-20 && move_left==1 && space==0){     //pomeranje strelice levo desno
            move_right=move_right-1;
            glutPostRedisplay();
            glutTimerFunc(10, on_timer, 0);
            if(move_right==-20)
                move_left=0;
        }    
        glRotatef(move_right,0,1,0);
        
        glTranslatef(0,7.5*sin(animation_parametar/(8.5+(strenth_parametar/100)*6)),1-animation_parametar);  // transliranje strelice po sinusoidi ka meti
        draw_dart();
    glPopMatrix();
    
    
    
    double clipping_plane[] = {0, -1, 0,-0.3+(strenth_parametar/100)*0.6}; //kliping ravan koja pokriva i otkriva indikator jacine
    glClipPlane(GL_CLIP_PLANE0, clipping_plane);
    glEnable(GL_CLIP_PLANE0);
    
    glPushMatrix();
        glRotatef(45,0,1,0);
        glNormal3f(0,0,-1);
        glScalef(0.1,0.6,0.1);
        glTranslatef(0,0,5);
        glutSolidCube(1);//indikator jacine
    glPopMatrix();
    glDisable(GL_CLIP_PLANE0);
    glPushMatrix();
        glTranslatef(0,0,-3);
        draw_target();
    glPopMatrix();
    
    
    
    show_text(); //fja prikazuje tekst na ekranu SCORE:##
    
    glPushMatrix();
    
    //glBindTexture(GL_TEXTURE_2D,names[0]);
    
//     glNormal3f(0,0,1);
//     
//     glBegin(GL_QUADS);
//         
//         //glTexCoord2f(0,0);
//         glVertex3f(-2,-2,-3.5);
//         
//         glTexCoord2f(1,0);
//         glVertex3f(1.5,-2,-3.5);
//     
//         
//         glTexCoord2f(1,1);
//         glVertex3f(1.5,2,-3.5);
//         
//         
//         glTexCoord2f(0,1);
//         glVertex3f(-1.5,2,-3.5);
//         
//     glEnd();
//     
//     glBindTexture(GL_TEXTURE_2D,0);
    
    glPopMatrix();
    glutSwapBuffers();
}
void draw_target(){ //fja za crtanje mete,crta se preko 10 diskova koji su postavljeni jedan ispred drugog
    glNormal3f(0,0,-1);  
    for(int i=1;i<=10;i++){
        glTranslatef(0,0,-0.001);
        if(i==1)
            glColor3f(1,0,0);
        else if(i%2==0)
            glColor3f(0,0,0);
        else if(i%2==1)
            glColor3f(1,1,1);
        GLUquadric* quad=gluNewQuadric();
        gluDisk(quad,0.0001,0.05*i,20,20);
    }
}

void draw_dart(){  //crtanje strelice 
    
    glColor3f(1,0,0.1); 
    glBegin(GL_POLYGON);  //krilo
        glVertex3f(0,0,-1);
        glVertex3f(0,1,-0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(0,0,1);
    glEnd();
     glBegin(GL_POLYGON); // krilo
        glVertex3f(0,0,-1);
        glVertex3f(0,-1,-0.5);
        glVertex3f(0,-1,0.5);
        glVertex3f(0,0,1);
    glEnd();
    
        glBegin(GL_POLYGON); //krilo
        glVertex3f(0,0,-1);
        glVertex3f(1,0,-0.5);
        glVertex3f(1,0,0.5);
        glVertex3f(0,0,1);
    glEnd();
     glBegin(GL_POLYGON); //krilo
        glVertex3f(0,0,-1);
        glVertex3f(-1,0,-0.5);
        glVertex3f(-1,0,0.5);
        glVertex3f(0,0,1);
    glEnd();
    // transliramo pa crtamo cilindar koji je ili u obliku kupe ili u obliku kupe bez vrha
    glColor3f(0.9,0.7,0); //crtanje vrata i spica strelice
    glTranslatef(0,0,-4.3);
    GLUquadric* quad=gluNewQuadric();
    gluCylinder(quad,0.1,0.1,4.2,50,50);
    glTranslatef(0,0,-0.2);
    gluCylinder(quad,0.2,0.1,0.2,50,50);
    glTranslatef(0,0,-0.2);
    gluCylinder(quad,0.2,0.2,1.5,50,50);
    glTranslatef(0,0,-0.2);
    gluCylinder(quad,0.1,0.2,0.2,50,50);
    glColor3f(0,1,0);
    glTranslatef(0,0,-2.0);
    gluCylinder(quad,0.05,0.1,2,50,50);//spic
    x=0;
    z=0.000001;
    if(space==1)
        x=tan(PI/180*(move_right+0.0))*3.31; //odredjivanje x preko tangesa jer max ugao koji moze da uzme x je 20 stepeni a min je -20,dato je rastojanje i preko toga se odredujje
    if(animation_parametar==33){//ako animation_parametar dodje do 33 tj do mete racuna se y
        y=7.5*sin(animation_parametar/(8.5+(strenth_parametar/100)*6));
    }
    glColor3f(1,0,0); // boja indikatora jacine
    

    



    glutPostRedisplay();
}
