
#define GL_SILENCE_DEPRECATION
#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O
#include <stdlib.h> // standard definitions

// include files are in a slightly different location for MacOS
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// escape key (for exit)
#define ESC 27

// Current camera position
float x = 0.0, y = -35.0, z = 0.0;
float deltaMove = 0.0; // initially camera doesn't move

// they point in the direction the camera is looking.
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

void changeSize(int w, int h)
{
    float ratio =  ((float) w) / ((float) h); // window aspect ratio
    glMatrixMode(GL_PROJECTION); // projection matrix is active
    glLoadIdentity(); // reset the projection
    gluPerspective(45.0, ratio, 0.1, 1000.0); // perspective transformation
    glMatrixMode(GL_MODELVIEW); // return to modelview mode
    glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}
//----------------------------------------------------------------------
// Update with each idle event
//
// This incrementally moves the camera and requests that the scene be
// redrawn.
//----------------------------------------------------------------------
void update(void)
{
    if (deltaMove) { // update camera position
        x += deltaMove * lx * 0.1;
        y += deltaMove * ly * 0.1;
    }
    glutPostRedisplay(); // redisplay everything
}

void crtajZid()
{
     glPushMatrix();
         glColor3ub(224,172,105);
         glScalef(4, 0.5, 8);
         glutSolidCube(1);
     glPopMatrix();
}

void crtajPrvuSliku() {

    glPushMatrix();

        glTranslatef(0, 4.5, -3.2);
        glScalef(1.2, 1, 0.2);

        //okvir slike
        glColor3f(0.0, 0.0, 0.0);  // crna
        glutSolidCube(1.2);

        //slika
        glTranslatef(0, 0, 0.4);
        glColor3ub(158,55,159); // lila
        glutSolidCube(1);

    glPopMatrix();
}

void crtajDruguSliku() {

    glPushMatrix();

        glTranslatef(0, 4.5, -3.2);
        glScalef(1.2, 1, 0.2);

        //okvir slike
        glColor3ub(102,178,178);
        glutSolidCube(1.2);

        //slika
        glTranslatef(0, 0, 0.4);
        glColor3ub(0,128,128);
        glutSolidCube(1);

    glPopMatrix();
}


//*************************************************************************
//**********************************SVETLO*********************************
//*************************************************************************

void lights()
{
     glEnable(GL_LIGHTING);
     glEnable(GL_NORMALIZE);
     glEnable(GL_COLOR_MATERIAL);
     glDisable(GL_LIGHT0);
     glEnable(GL_LIGHTING);

     GLfloat lmodel_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
     GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light_positionSunce[] = { -15.0, -15.0, 15.0, 0.0 };
     GLfloat light_position1[] = { -7, -8.7, 3.2, 0.0 };
     GLfloat light_position2[] = { -7, 0.1, 3.2, 0.0 };
     GLfloat light_position3[] = { 0.5, 8, 3.2, 0.0 };

    //samo pozicija svetla menjana
     glLightfv(GL_LIGHT0,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT0,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT0,GL_POSITION,light_positionSunce);

     glLightfv(GL_LIGHT1,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT1,GL_POSITION,light_position1);

     glLightfv(GL_LIGHT2,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT2,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT2,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT2,GL_POSITION,light_position2);

     glLightfv(GL_LIGHT3,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT3,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT3,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT3,GL_POSITION,light_position3);

     GLfloat mat_amb_diff[] = { 0.7, 0.7, 0.7, 1.0 };
     GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat low_shininess[] = { 10.0 };

     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_shininess);

     glMatrixMode(GL_MODELVIEW);
}

void lightoff(unsigned char key, int x, int y) {

    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }

    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}


//*************************************************************************
//**********************************TEKSTURE*******************************
//*************************************************************************

GLuint texture1;
GLuint texture2;
GLuint texture3;

//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}

void teksturaDvorista()
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture2);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_POLYGON);

    glTexCoord2d(1.0, 0.0); glVertex3f(200.8, -40.0, -3.8);
    glTexCoord2d(1.0, 1.0); glVertex3f(200.8, 5.0, -3.8);
    glTexCoord2d(0.0, 1.0); glVertex3f(-240.8,5.0, -3.8);
    glTexCoord2d(0.0, 0.0); glVertex3f(-240.8, -40.0, -3.8);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void teksturaPuta()
{
   glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture1);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);

    glTexCoord2d(1.0, 0.0); glVertex3f(1.8, -52.0, -3.8);
    glTexCoord2d(1.0, 1.0); glVertex3f(1.8, 0.0, -3.8);
    glTexCoord2d(0.0, 1.0); glVertex3f(-1.8,0.0, -3.8);
    glTexCoord2d(0.0, 0.0); glVertex3f(-1.8, -52.0, -3.8);

    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

//*************************************************************************
//***************************FUNKCIJE ZA ISCRTAVANJE***********************
//*************************************************************************

void crtajKlupu() {

    //sediste
    glPushMatrix();
        glScalef(1.5, 4, 0.15);
        glTranslatef(0, -2, -19.5);
        glColor3ub(158,55,159);
        glutSolidCube(1);
    glPopMatrix();

    //nogare
    glPushMatrix();
        glColor3ub(52,61,70); //siva
        glScalef(0.2, 0.2, 1);
        glTranslatef(3.5, -30.5, -3.5);
        glutSolidCube(1);

        glTranslatef(-6.5, 0, 0);
        glutSolidCube(1);

        glTranslatef(0, -19.1, 0);
        glutSolidCube(1);

        glTranslatef(6.5, 0, 0);
        glutSolidCube(1);
    glPopMatrix();

    //naslanjac
    glPushMatrix();
        glScalef(0.2, 4, 1.3);
        glTranslatef(3.0, -2.0, -1.7);
        glColor3ub(158,55,159);
        glutSolidCube(1);
    glPopMatrix();
}


void crtajSvetiljku() {
    //stalak
    glPushMatrix();
        glScalef(0.4, 0.4, 7);
        glTranslatef(-6.5, -15, -0.04);
        glColor3ub(55,58,61);
        glutSolidCube(1);
    glPopMatrix();

    //lampa
    glPushMatrix();
        glTranslatef(-2.7, -5.94, 3.5);
        glColor3ub(255,193,0);
        glutWireTorus(0.4, 0.7, 50, 50);
    glPopMatrix();
}

void crtajDrvo() {

    glPushMatrix();
        glTranslatef(-2.7, -5.94, -0.4);
        glColor3ub(0,135,68);
        glutWireTorus(0.2, 0.3, 50, 50);

        glTranslatef(0, 0, -0.4);
        glScalef(1.5, 1.5, 1);
        glutWireTorus(0.2, 0.4, 50, 50);

        glTranslatef(0, 0, -0.4);
        glScalef(1.2, 1.2, 1);
        glutWireTorus(0.2, 0.4, 50, 50);

        glTranslatef(0, 0, -0.4);
        glScalef(1.2, 1.2, 1);
        glutWireTorus(0.2, 0.4, 50, 50);

        glTranslatef(0, 0, -0.4);
        glScalef(1.2, 1.2, 1);
        glutWireTorus(0.2, 0.4, 50, 50);

        glTranslatef(0, 0, -0.4);
        glScalef(1.2, 1.2, 1);
        glutWireTorus(0.2, 0.4, 50, 50);

        glTranslatef(0, 0, -0.4);
        glScalef(1.2, 1.2, 1);
        glutWireTorus(0.2, 0.4, 50, 50);

        glTranslatef(0, 0, -0.4);
        glColor3ub(96,35,32);
        glScalef(0.2, 0.2, 3);
        glutSolidCube(1);
    glPopMatrix();
}

//*************************************************************************
//*******************************RENDEROVANJE******************************
//*************************************************************************

void renderScene(void)
{
    // Clear color and depth buffers
    glClearColor(0.678, 0.847, 0.902, 1.0); // sky color - light blue
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera centered at (x,y,1) and looking along directional
    // vector (lx, ly, 0), with the z-axis pointing up
    gluLookAt(
            x,      y,      z,
            x + lx, y + ly, z,
            0.0,    0.0,    1.0);

    //*************************************************************************
    //*******************************KULA MOTRILJA*****************************
    //*************************************************************************

    //ZADNJI DEO KULE
    glRotatef(180, 0, 0, 1);
    glColor3ub(224,172,105);
    crtajZid();// zadnji zid
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glRotatef(180, 0, 1, 0);
        glTranslatef(0, -2.0, 3.5);
        crtajPrvuSliku();
        glTranslatef(0, -2.0, 0);
        crtajDruguSliku();
        glTranslatef(0, -2.0, 0);
        crtajPrvuSliku();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.1, 1.4, 0);
        glRotatef(-50, 0, 0, 1); //leva strana
        crtajZid();

        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            glRotatef(180, 0, 1, 0);

            glTranslatef(0, -2.0, 3.5);
            crtajPrvuSliku();

            glTranslatef(0, -2.0, 0);
            crtajDruguSliku();

            glTranslatef(0, -2.0, 0);
            crtajPrvuSliku();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(3.1, 1.4, 0);
        glRotatef(50, 0, 0, 1); //desna strana
        crtajZid();

        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            glRotatef(180, 0, 1, 0);

            glTranslatef(0, -2.0, 3.5);
            crtajPrvuSliku();

            glTranslatef(0, -2.0, 0);
            crtajDruguSliku();

            glTranslatef(0, -2.0, 0);
            crtajPrvuSliku();
        glPopMatrix();
        glPopMatrix();

        //desna strana kule - srediste
        glPushMatrix();
            glTranslatef(4.2, 4.9, 0);
            glRotatef(-80, 0, 0, 1);
            crtajZid();
        glPopMatrix();

        //leva strana kule - srediste
        glPushMatrix();
            glTranslatef(-4.2, 4.9, 0);
            glRotatef(80, 0, 0, 1);
            crtajZid();
        glPopMatrix();

    glRotatef(-180, 0, 0, 1); //reset rotacije

    //PREDNJI DEO
    glPushMatrix();
        glTranslatef(-2.6, -8.2, 0.0);
        glRotatef(-50, 0, 0, 1); //leva strana, prednja

        crtajZid();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.6, -8.2, 0.0);
        glRotatef(50, 0, 0, 1); //desna strana, prednja
        crtajZid();
    glPopMatrix();

    glColor3ub(224,172,105);
    glScalef(0.77, 1, 1);
    glTranslatef(0, -9.6, 0);
    crtajZid(); //prednji zid
    teksturaPuta();

    //KROV
    glPushMatrix();
    glScalef(2.5, 1.6, 1);
    glTranslatef(0, 3, 4);
    glColor3ub(163,32,32);
    glutWireCone(2.4, 4, 8, 100);

    glPopMatrix();

    //vrata
    glPushMatrix();
    glScalef(2, 0.4, 2.5);
    glTranslatef(0, -0.2, -1.1);
    glColor3ub(198,134,66);
    glutSolidCube(1);
    glPopMatrix();

    //gornji beli kvadrat
    glPushMatrix();
    glScalef(2.8, 0.4, 2.65);
    glTranslatef(0, -0.2, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(1);

    //crni kvadratic
    glTranslatef(0, -1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidCube(0.2);

    glPopMatrix();

    //************************************************************************
    //****************************KLUPE, DRVECE, SVETILJKE********************
    //************************************************************************

    //ZELENI PROSTOR
    glPushMatrix();
    glScalef(200.8, 80, 0.1);
    glTranslatef(0, -0.2, -39.5);
    glColor3ub(119,171,89);
    glutSolidCube(1);

    glPopMatrix();

    //klupe uz put sa desne strane
    glPushMatrix();
    glTranslatef(3, 0, 0);

    for(int i = 0; i<5; i++) {
        glTranslatef(0, -8, 0);
        crtajKlupu();
    }

    glPopMatrix();

    //drvece pored kule desno
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glTranslatef(6, -4, 0);
    for(int i = 0; i<6; i++) {
        for(int j = 1; j < 7; j++) {
        glPushMatrix();
            glTranslatef(i*-9, -9*j, 0);
            crtajDrvo();
        glPopMatrix();
        }
    }
    glPopMatrix();

    //drvece pored kule levo
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0, -4, 0);
    for(int i = 0; i<6; i++) {
        for(int j = 1; j < 7; j++) {
        glPushMatrix();
            glTranslatef(i*9, -9*j, 0);
            crtajDrvo();
        glPopMatrix();
        }
    }
    glPopMatrix();

    //svetiljke
    for(int i = 0; i<4; i++) {
        glPushMatrix();
        glTranslatef(-2, -15*i, 0);
        crtajSvetiljku();
        glPopMatrix();
    }

    for(int i = 0; i<4; i++) {
        glPushMatrix();
        glTranslatef(7, -15*i, 0);
        crtajSvetiljku();
        glPopMatrix();
    }

    glutSwapBuffers(); // Make it all visible
}

//************************************************************************
//****************************OSTALO**************************************
//************************************************************************

void processNormalKeys(unsigned char key, int xx, int yy)
{
    if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

void pressSpecialKey(int key, int xx, int yy)
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 1.0; break;
        case GLUT_KEY_DOWN : deltaMove = -1.0; break;
    }
}

void releaseSpecialKey(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 0.0; break;
        case GLUT_KEY_DOWN : deltaMove = 0.0; break;
    }
}

void mouseMove(int x, int y)
{
    if (isDragging) { // only when dragging
        // update the change in angle
        deltaAngle = (x - xDragStart) * 0.005;

        // camera's direction is set to angle + deltaAngle
        lx = -sin(angle + deltaAngle);
        ly = cos(angle + deltaAngle);
    }
}

void mouseButton(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) { // left mouse button pressed
            isDragging = 1; // start dragging
            xDragStart = x; // save x where button first pressed
        }
        else  { /* (state = GLUT_UP) */
            angle += deltaAngle; // update camera turning angle
            isDragging = 0; // no longer dragging
        }
    }
}

void menu (int b)
{
     if(b==1)
     {
            x=15.0;
            y=-120.0;
            z=22.0;
     }
     if(b==2)
     {
            x=50.0;
            y=-60.0;
            z=5.5;
     }
     if(b==3)
     {
            x=0.0;
            y=-7.0;
            z=0.0;
     }
     if(b==4)
     {
            x=0.0;
            y=-25.0;
            z=0.0;
     }
     if(b==5)
     {
            x=-10.0;
            y=-40.0;
            z=2.0;
     }

     glutPostRedisplay();
}

void kreirajMeni()
{
     glutCreateMenu(menu);
     glutAddMenuEntry("Pticja perspektiva",1);
     glutAddMenuEntry("Pogled iz desnog donjeg ugla",2);
     glutAddMenuEntry("Unutrasnjost kule",3);
     glutAddMenuEntry("Startna pozicija",4);
     glutAddMenuEntry("Levi deo",5);

     glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{
    // general initializations
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 400);
    glutCreateWindow("OpenGL/GLUT Sampe Program");
    kreirajMeni();
    lights();

    // register callbacks
    glutReshapeFunc(changeSize); // window reshape callback
    glutDisplayFunc(renderScene); // (re)display callback
    glutIdleFunc(update); // incremental update
    glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
    glutMouseFunc(mouseButton); // process mouse button push/release
    glutMotionFunc(mouseMove); // process mouse dragging motion
    glutKeyboardFunc(processNormalKeys); // process standard key clicks
    glutSpecialFunc(pressSpecialKey); // process special key pressed
                        // Warning: Nonstandard function! Delete if desired.
    glutSpecialUpFunc(releaseSpecialKey); // process special key release
    glutKeyboardFunc(lightoff);

        texture1=LoadTexture("ovde upisati putanju do fajla teksture",256, 256);

    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 0; // this is just to keep the compiler happy
}
