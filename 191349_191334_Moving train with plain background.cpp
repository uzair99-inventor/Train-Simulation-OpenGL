/*  The purpose of the code is to animate a train.
The train is continuously moving from +x axis to -x axis.
By pressing UP key, the speed of train increases.
And by pressing DOWN key, the speed decreases.

Izzah Majid 191349
Uzair Ahmed 191334
*/
#include<windows.h>
#include<mmsystem.h>
#include<GL/glut.h>
#include <math.h>
#define PI 3.14159265f

float a;
float x;
char title[] = "Moving train with plain background";
GLfloat ballRadius=0.06f;
GLfloat squareX=1.0f;
GLfloat squareY=0.0f;
GLfloat speed =0.005f;
int refreshMillis = 30;
float z=0,y=0;
int windowWidth = 640;
int windowHeight = 640;
int windowPosX = 50;
int windowPosY = 50;
GLfloat clipAreaXLeft = -1.0;
GLfloat clipAreaXRight = 1.0;
GLfloat clipAreaYBottom = -1.0;
GLfloat clipAreaYTop = 1.0;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
 bool paused = false;
GLfloat xSpeedSaved, ySpeedSaved, a1;

void initGL() {
glClearColor(0.0, 0.0, 0.0, 1.0);
}

void reshape(GLsizei width, GLsizei height)
{
if (height == 0) height = 1;
GLfloat aspect = (GLfloat)width / (GLfloat)height;
glViewport(0, 0, width, height);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (width >= height)
{
clipAreaXLeft = -1.0 * aspect;
clipAreaXRight = 1.0 * aspect;
clipAreaYBottom = -1.0;
clipAreaYTop = 1.0;
} else {
clipAreaXLeft = -1.0;
clipAreaXRight = 1.0;
clipAreaYBottom = -1.0 / aspect;
clipAreaYTop = 1.0 / aspect;
}
gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom,clipAreaYTop);

}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


if(z>=1.99)
{

    z=z-0.0005;
}
else
{
    z=0;
}


glLoadIdentity();

glTranslatef(0,0,-1);

glColor3f(0, 1, 1);
glBegin(GL_QUADS);
glVertex2f(-1,1);                   //sky
glVertex2f(-1,-1);
glVertex2f(1,-1);
glVertex2f(1,1);
glEnd();


glColor3f(0.8, 0.8, 0.6);
glBegin(GL_QUADS);
glVertex2f(-1,-0.12);           //grey road
glVertex2f(-1,-1);
glVertex2f(1,-1);
glVertex2f(1,-0.12);
glEnd();



glColor3f(1, 1, 1);
glBegin(GL_QUADS);
glVertex2f(-1,0);
glVertex2f(-1,-0.12);
glVertex2f(1,-0.12);
glVertex2f(1,0);                    //white strip
glEnd();





glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2d(-1,0);
glVertex2d(1,0);
glVertex2d(-1,-0.12);
glVertex2d(1,-0.12);
glEnd();                                  //white rectangle strip


glColor3f(0,0,0);                           //track line  lowermost
glBegin(GL_LINES);
glVertex2f(1,-0.77);
glVertex2f(-1,-0.77);

glVertex2f(1,-0.72);
glVertex2f(-1,-0.72);
glEnd();


glColor3f(0,0,0);                           //track line  lowermost
glBegin(GL_LINES);
glVertex2f(-0.95,-0.77);
glVertex2f(-0.95,-0.72);

glVertex2f(-0.9,-0.77);
glVertex2f(-0.9,-0.72);

glVertex2f(-0.85,-0.77);
glVertex2f(-0.85,-0.72);

glVertex2f(-0.8,-0.77);
glVertex2f(-0.8,-0.72);

glVertex2f(-0.75,-0.77);
glVertex2f(-0.75,-0.72);

glVertex2f(-0.7,-0.77);
glVertex2f(-0.7,-0.72);

glVertex2f(-0.65,-0.77);
glVertex2f(-0.65,-0.72);

glVertex2f(-0.6,-0.77);
glVertex2f(-0.6,-0.72);

glVertex2f(-0.55,-0.77);
glVertex2f(-0.55,-0.72);

glVertex2f(-0.5,-0.77);
glVertex2f(-0.5,-0.72);

glVertex2f(-0.45,-0.77);
glVertex2f(-0.45,-0.72);

glVertex2f(-0.4,-0.77);
glVertex2f(-0.4,-0.72);

glVertex2f(-0.35,-0.77);
glVertex2f(-0.35,-0.72);

glVertex2f(-0.3,-0.77);
glVertex2f(-0.3,-0.72);

glVertex2f(-0.25,-0.77);
glVertex2f(-0.25,-0.72);

glVertex2f(-0.2,-0.77);
glVertex2f(-0.2,-0.72);

glVertex2f(-0.15,-0.77);
glVertex2f(-0.15,-0.72);

glVertex2f(-0.1,-0.77);
glVertex2f(-0.1,-0.72);

glVertex2f(-0.05,-0.77);
glVertex2f(-0.05,-0.72);

glVertex2f(-0.0,-0.77);
glVertex2f(-0.0,-0.72);

glVertex2f(0.05,-0.77);
glVertex2f(0.05,-0.72);

glVertex2f(0.1,-0.77);
glVertex2f(0.1,-0.72);

glVertex2f(0.15,-0.77);
glVertex2f(0.15,-0.72);

glVertex2f(0.2,-0.77);
glVertex2f(0.2,-0.72);

glVertex2f(0.25,-0.77);
glVertex2f(0.25,-0.72);

glVertex2f(0.3,-0.77);
glVertex2f(0.3,-0.72);

glVertex2f(0.35,-0.77);
glVertex2f(0.35,-0.72);

glVertex2f(0.95,-0.77);
glVertex2f(0.95,-0.72);

glVertex2f(0.9,-0.77);
glVertex2f(0.9,-0.72);

glVertex2f(0.85,-0.77);
glVertex2f(0.85,-0.72);

glVertex2f(0.8,-0.77);
glVertex2f(0.8,-0.72);

glVertex2f(0.75,-0.77);
glVertex2f(0.75,-0.72);

glVertex2f(0.7,-0.77);
glVertex2f(0.7,-0.72);

glVertex2f(0.65,-0.77);
glVertex2f(0.65,-0.72);

glVertex2f(0.6,-0.77);
glVertex2f(0.6,-0.72);

glVertex2f(0.55,-0.77);
glVertex2f(0.55,-0.72);

glVertex2f(0.5,-0.77);
glVertex2f(0.5,-0.72);

glVertex2f(0.45,-0.77);
glVertex2f(0.45,-0.72);

glVertex2f(0.4,-0.77);
glVertex2f(0.4,-0.72);
glEnd();


//train
glTranslatef(squareX, squareY , 0.0f);

glColor3f(0, 0, 0);
glBegin(GL_LINES);
                      //black line 1 connecting train parts
glVertex2f(-0.3+z,-0.41);   //1
glVertex2f(0.4+z,-0.41);
  //1
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_LINES);                          //black line 2 connecting train parts
glVertex2f(-0.3+z,-0.60);   //1
glVertex2f(0.4+z,-0.60);   //1
glEnd();


glColor3f(0, 0, 0);
glBegin(GL_POLYGON);                        //Train 1 box  black
glVertex2f(-0.7+z,-0.30);   //1
glVertex2f(-0.8+z,-0.50);   //2
glVertex2f(-0.8+z,-0.70);   //3
glVertex2f(-0.2+z,-0.70);   //4
glVertex2f(-0.2+z,-0.30);   //5
glEnd();



glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(-0.8+z,-0.62);   //1             //Train 1 box  black front lines
glVertex2f(-0.83+z,-0.62);   //1
glEnd();


glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(-0.8+z,-0.56);   //1
glVertex2f(-0.83+z,-0.56);   //1
glEnd();


glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(-0.83+z,-0.62);   //1
glVertex2f(-0.83+z,-0.54);   //1
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_QUADS);                          //Train 1 white window
glVertex2f(-0.7+z,-0.35);   //1
glVertex2f(-0.7+z,-0.48);   //2
glVertex2f(-0.62+z,-0.48);   //3
glVertex2f(-0.62+z,-0.35);   //4
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_QUADS);                          //Train 1 upper black rectangle steam
glVertex2f(-0.68+z,-0.25);   //1
glVertex2f(-0.68+z,-0.3);   //2
glVertex2f(-0.63+z,-0.3);   //3
glVertex2f(-0.63+z,-0.25);   //4
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_QUADS);                          //Train 1 upper black rectangular for curve shape
glVertex2f(-0.57+z,-0.25);   //1
glVertex2f(-0.62+z,-0.30);   //2
glVertex2f(-0.42+z,-0.30);   //3
glVertex2f(-0.47+z,-0.25);   //4
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(-0.52+z,-0.25);   //1                       //Train 1 box  black upper lines
glVertex2f(-0.52+z,-0.20);   //1
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(-0.52+z,-0.20);   //1
glVertex2f(-0.34+z,-0.12);
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(-0.34+z,-0.12);
glVertex2f(-0.33+z,-0.0);
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_LINES);
glVertex2f(-0.33+z,-0.0);
glVertex2f(-0.52+z,-0.20);   //1
glEnd();

glColor3f(0, 0, 1);
glBegin(GL_QUADS);                        //Train 2 box  blue
glVertex2f(-0.15+z,-0.30);   //1
glVertex2f(-0.15+z,-0.70);   //3
glVertex2f(0.25+z,-0.70);   //4
glVertex2f(0.25+z,-0.30);   //5
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_QUADS);                          //Train 2 white window
glVertex2f(-0.13+z,-0.40);   //1
glVertex2f(-0.13+z,-0.59);   //2
glVertex2f(-0.06+z,-0.59);   //3
glVertex2f(-0.06+z,-0.40);   //4
glEnd();

glColor3f(0.7, 0.7, 0.7);
glBegin(GL_QUADS);                          //Train 2 white window  grey inner part
glVertex2f(-0.13+z,-0.40);   //1
glVertex2f(-0.13+z,-0.59);   //2
glVertex2f(-0.09+z,-0.57);   //3
glVertex2f(-0.09+z,-0.43);   //4
glEnd();

glColor3f(0, 2, 2);
glBegin(GL_QUADS);                          //Train 2 cyan window left
glVertex2f(0.0+z,-0.35);   //1
glVertex2f(0.0+z,-0.44);   //2
glVertex2f(0.095+z,-0.44);   //3
glVertex2f(0.095+z,-0.35);   //4
glEnd();

glColor3f(0, 2, 2);
glBegin(GL_QUADS);                          //Train 2 cyan window right
glVertex2f(0.115+z,-0.35);   //1
glVertex2f(0.115+z,-0.44);   //2
glVertex2f(0.21+z,-0.44);   //3
glVertex2f(0.21+z,-0.35);   //4
glEnd();

glColor3f(0, 0, 1);
glBegin(GL_QUADS);                        //Train 3 box  blue
glVertex2f(0.30+z,-0.30);   //1
glVertex2f(0.30+z,-0.70);   //3
glVertex2f(0.70+z,-0.70);   //4
glVertex2f(0.70+z,-0.30);   //5
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_QUADS);                          //Train 3 white window
glVertex2f(0.32+z,-0.40);   //1
glVertex2f(0.32+z,-0.59);   //2
glVertex2f(0.39+z,-0.59);   //3
glVertex2f(0.39+z,-0.40);   //4
glEnd();

glColor3f(0.7, 0.7, 0.7);
glBegin(GL_QUADS);                          //Train 3 white window  grey inner part
glVertex2f(0.32+z,-0.40);   //1
glVertex2f(0.32+z,-0.59);   //2
glVertex2f(0.36+z,-0.57);   //3
glVertex2f(0.36+z,-0.43);   //4
glEnd();

glColor3f(0.7, 0.7, 0.7);
glBegin(GL_QUADS);                          //Train 2 white window  grey inner part
glVertex2f(-0.13+z,-0.40);   //1
glVertex2f(-0.13+z,-0.59);   //2
glVertex2f(-0.09+z,-0.57);   //3
glVertex2f(-0.09+z,-0.43);   //4
glEnd();

glColor3f(0, 2, 2);
glBegin(GL_QUADS);                          //Train 3 cyan window left
glVertex2f(0.45+z,-0.35);   //1
glVertex2f(0.45+z,-0.44);   //2
glVertex2f(0.545+z,-0.44);   //3
glVertex2f(0.545+z,-0.35);   //4
glEnd();

glColor3f(0, 2, 2);
glBegin(GL_QUADS);                          //Train 3 cyan window right
glVertex2f(0.565+z,-0.35);   //1
glVertex2f(0.565+z,-0.44);   //2
glVertex2f(0.66+z,-0.44);   //3
glVertex2f(0.66+z,-0.35);   //4
glEnd();

//Tyre of box 1 middle
        glTranslatef(-0.5,-0.7,0);
glColor3f(0.2,0.2,0);
    int numsegments=10000;
    GLfloat angle=2*PI/numsegments;
    glBegin(GL_POINTS);
        glVertex2f(0,0);
        for (int i=0;i<=numsegments;i++)
        {
            glVertex2f((ballRadius*cos(i*angle)+z),(ballRadius*sin(i*angle)));
        }

    glEnd();
glPushMatrix();
glTranslatef(0,0,-1);
glRotatef(a, 0, 0, 1);
glTranslatef(0,0,1);
//Lines
glColor3f(0.1, 0.1, 0.1);
glBegin(GL_LINES);
glVertex2f(-0.0+z,0.06);
glVertex2f(-0.0+z,-0.06);                          //vertical
glVertex2f(-0.06+z,0.0);
glVertex2f(0.06+z,0.0);                               //horizontal
glVertex2f(-0.045+z,-0.045);
glVertex2f(0.045+z,0.045);                             //forward tilt
glVertex2f(-0.045+z,0.045);
glVertex2f(0.045+z,-0.045);                              //backward tilt
glEnd();
glPopMatrix();
a += 1;

    //Tyre of box 1 right
        glTranslatef(0.2,-0.0,0);
glColor3f(0.2,0.2,0);
    int numsegments1=10000;
    GLfloat angle1=2*PI/numsegments1;
    glBegin(GL_POINTS);
        glVertex2f(0,0);
        for (int i=0;i<=numsegments1;i++)
        {
            glVertex2f((ballRadius*cos(i*angle1)+z),(ballRadius*sin(i*angle1)));
        }

    glEnd();

glPushMatrix();
glTranslatef(0,0,-1);
glRotatef(a, 0, 0, 1);
glTranslatef(0,0,1);
 //Lines
glColor3f(0.1, 0.1, 0.1);
glBegin(GL_LINES);
glVertex2f(0.0+z,0.06);
glVertex2f(0.0+z,-0.06);                          //vertical
glVertex2f(-0.06+z,0.0);
glVertex2f(0.06+z,0.0);                               //horizontal
glVertex2f(-0.045+z,-0.045);
glVertex2f(0.045+z,0.045);                             //forward tilt
glVertex2f(-0.045+z,0.045);
glVertex2f(0.045+z,-0.045);                              //backward tilt

glEnd();

glPopMatrix();
a += 1;


        //Tyre of box 1 left
        glTranslatef(-0.4,-0.0,0);
glColor3f(0.2,0.2,0);
    int numsegments2=10000;
    GLfloat angle2=2*PI/numsegments2;
    glBegin(GL_POINTS);
        glVertex2f(0,0);
        for (int i=0;i<=numsegments2;i++)
        {
            glVertex2f((ballRadius*cos(i*angle2)+z),(ballRadius*sin(i*angle2)));
        }
    glEnd();

glPushMatrix();
glTranslatef(0,0,-1);
glRotatef(a, 0, 0, 1);
glTranslatef(0,0,1);
     //Lines
glColor3f(0.1, 0.1, 0.1);
glBegin(GL_LINES);
glVertex2f(0.0+z,0.06);
glVertex2f(0.0+z,-0.06);                          //vertical
glVertex2f(-0.06+z,0.0);
glVertex2f(0.06+z,0.0);                               //horizontal
glVertex2f(-0.045+z,-0.045);
glVertex2f(0.045+z,0.045);                             //forward tilt
glVertex2f(-0.045+z,0.045);
glVertex2f(0.045+z,-0.045);                              //backward tilt
glEnd();
glPopMatrix();
a += 1;

        //Tyre of box 2 left
        glTranslatef(0.65,-0.0,0);
glColor3f(0.2,0.2,0);
    int numsegments3=10000;
    GLfloat angle3=2*PI/numsegments3;
    glBegin(GL_POINTS);
        glVertex2f(0,0);
        for (int i=0;i<=numsegments3;i++)
        {
            glVertex2f((ballRadius*cos(i*angle3)+z),(ballRadius*sin(i*angle3)));
        }
    glEnd();


glPushMatrix();
glTranslatef(0,0,-1);
glRotatef(a, 0, 0, 1);
glTranslatef(0,0,1);
     //Lines
glColor3f(0.1, 0.1, 0.1);
glBegin(GL_LINES);
glVertex2f(0.0+z,0.06);
glVertex2f(0.0+z,-0.06);                          //vertical
glVertex2f(-0.06+z,0.0);
glVertex2f(0.06+z,0.0);                               //horizontal
glVertex2f(-0.045+z,-0.045);
glVertex2f(0.045+z,0.045);                             //forward tilt
glVertex2f(-0.045+z,0.045);
glVertex2f(0.045+z,-0.045);                              //backward tilt
glEnd();
glPopMatrix();
a += 1;

        //Tyre of box 2 right
        glTranslatef(0.2,-0.0,0);
glColor3f(0.2,0.2,0);
    int numsegments4=10000;
    GLfloat angle4=2*PI/numsegments4;
    glBegin(GL_POINTS);
        glVertex2f(0,0);
        for (int i=0;i<=numsegments4;i++)
        {
            glVertex2f((ballRadius*cos(i*angle4)+z),(ballRadius*sin(i*angle4)));
        }
    glEnd();

glPushMatrix();
glTranslatef(0,0,-1);
glRotatef(a, 0, 0, 1);
glTranslatef(0,0,1);
     //Lines
glColor3f(0.1, 0.1, 0.1);
glBegin(GL_LINES);
glVertex2f(0.0+z,0.06);
glVertex2f(0.0+z,-0.06);                          //vertical
glVertex2f(-0.06+z,0.0);
glVertex2f(0.06+z,0.0);                               //horizontal
glVertex2f(-0.045+z,-0.045);
glVertex2f(0.045+z,0.045);                             //forward tilt
glVertex2f(-0.045+z,0.045);
glVertex2f(0.045+z,-0.045);                              //backward tilt
glEnd();
glPopMatrix();
a += 1;



       //Tyre of box 3 left
        glTranslatef(0.25,-0.0,0);
glColor3f(0.2,0.2,0);
    int numsegments5=10000;
    GLfloat angle5=2*PI/numsegments5;
    glBegin(GL_POINTS);
        glVertex2f(0,0);
        for (int i=0;i<=numsegments5;i++)
        {
            glVertex2f((ballRadius*cos(i*angle5)+z),(ballRadius*sin(i*angle5)));
        }
    glEnd();

glPushMatrix();
glTranslatef(0,0,-1);
glRotatef(a, 0, 0, 1);
glTranslatef(0,0,1);
     //Lines
glColor3f(0.1, 0.1, 0.1);
glBegin(GL_LINES);
glVertex2f(0.0+z,0.06);
glVertex2f(0.0+z,-0.06);                          //vertical
glVertex2f(-0.06+z,0.0);
glVertex2f(0.06+z,0.0);                               //horizontal
glVertex2f(-0.045+z,-0.045);
glVertex2f(0.045+z,0.045);                             //forward tilt
glVertex2f(-0.045+z,0.045);
glVertex2f(0.045+z,-0.045);                              //backward tilt
glEnd();
glPopMatrix();
a += 1;

       //Tyre of box 3 right
        glTranslatef(0.2,-0.0,0);
      glColor3f(0.2,0.2,0);
    int numsegments6=10000;
    GLfloat angle6=2*PI/numsegments6;
    glBegin(GL_POINTS);
        glVertex2f(0,0);
        for (int i=0;i<=numsegments6;i++)
        {
            glVertex2f((ballRadius*cos(i*angle6)+z),(ballRadius*sin(i*angle6)));
        }
    glEnd();

glPushMatrix();
glTranslatef(0,0,-1);
glRotatef(a, 0, 0, 1);
glTranslatef(0,0,1);
     //Lines
glColor3f(0.1, 0.1, 0.1);
glBegin(GL_LINES);
glVertex2f(0.0+z,0.06);
glVertex2f(0.0+z,-0.06);                          //vertical
glVertex2f(-0.06+z,0.0);
glVertex2f(0.06+z,0.0);                               //horizontal
glVertex2f(-0.045+z,-0.045);
glVertex2f(0.045+z,0.045);                             //forward tilt
glVertex2f(-0.045+z,0.045);
glVertex2f(0.045+z,-0.045);                              //backward tilt
glEnd();
glPopMatrix();
a += 1;


//glBegin(GL_TRIANGLES);
//glVertex2f(0.03,0.975);
//glVertex2f(0.0,0.965);
//glVertex2f(0.03,0.945);
//glEnd();



glutSwapBuffers();


squareX= squareX - speed;

if  (squareX<-1.7)
{
    squareX=2.0;
}



}

void Timer(int value)
 {
glutPostRedisplay(); // Post a paint request to activate display()
glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}










void specialKeys(int key, int x, int y)
{
switch (key)
{
case GLUT_KEY_UP: // Right: increase x speed
speed *= 1.05f;
break;
case GLUT_KEY_DOWN: // Left: decrease x speed
speed *= 0.95f;
break;
break;

}
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(windowWidth, windowHeight);
glutInitWindowPosition(windowPosX, windowPosY);
glutCreateWindow(title);
glutDisplayFunc(display);
glutReshapeFunc(reshape);

glutSpecialFunc(specialKeys);
//glutFullScreen();
glutTimerFunc(0, Timer, 0);
initGL();
glutMainLoop();
return 0;
}
