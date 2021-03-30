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
char title[] = "Moving train with scenery background";
GLfloat ballRadius=0.06f;
GLfloat sunRadius=0.4f;
GLfloat squareX=1.0f;
GLfloat squareY=0.0f;
GLfloat speed =0.010f;
int refreshMillis = 30;
float z=0;
float n=0;
int windowWidth = 640;
int windowHeight = 640;
int windowPosX = 50;
int windowPosY = 50;
GLfloat clipAreaXLeft = -1.0;
GLfloat clipAreaXRight = 1.0;
GLfloat clipAreaYBottom = -1.0;
GLfloat clipAreaYTop = 1.0;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
GLfloat xSpeedSaved, ySpeedSaved, a1;
 bool paused = false;
 bool fullScreenMode = true;

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);

}


void initGL() {
glClearColor(0.0, 0.0, 0.0, 1.0);
}

void reshape(GLsizei width, GLsizei height)
{
glViewport(0, 0, width, height);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (height == 0) // Calculate The Aspect Ratio Of The Window
gluPerspective(80, (float)width, 1.0, 5000.0);
else
gluPerspective(80, (float)width / (float)height, 1.0, 5000.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity(); // Reset The Model View Matrix

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


glBegin(GL_QUADS);
glColor3f( 0.196078,0.6, 0.8);
glVertex2f(-1,1);                   //sky
glColor3f( 1,1, 1);
glVertex2f(-1,-1);
glColor3f( 1,1, 1);
glVertex2f(1,-1);
glColor3f( 0.196078,0.6, 0.8);
glVertex2f(1,1);
glEnd();



glColor3f(1,1,0);
    int sun_numsegments=10000;
    GLfloat sun_angle=2*PI/sun_numsegments;                 //sun
    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(0,0);
        for (int i=0;i<=sun_numsegments;i++)
        {
            glVertex2f((sunRadius*cos(i*sun_angle)),(sunRadius*sin(i*sun_angle)+n));
        }

glEnd();






glColor3f(0.125,0.15, 0.1);
glBegin(GL_TRIANGLES);
glColor3f(.8,0.498039,  0.196078);
glVertex2f(0.4,0.36);
glColor3f(00.0,0.1, 0.0);                  //mountain1
glVertex2f(0.8,0);
glColor3f(.125,0.15, 0.1);
glVertex2f(0,0);
glEnd();


glColor3f(.125,0.15, 0.1);
glBegin(GL_TRIANGLES);
glColor3f(.8,0.498039,  0.196078);
glVertex2f(-0.4,0.38);                   //mountain1
glColor3f(00.0,0.1, 0.0);
glVertex2f(-0.9,0);
glColor3f(.125,0.15, 0.1);
glVertex2f(0,0);
glEnd();

glColor3f(0.125,0.15, 0.1);
glBegin(GL_TRIANGLES);
glColor3f(.8,0.498039,  0.196078);
glVertex2f(-0.8,0.36);
glColor3f(00.0,0.1, 0.0);                   //mountain1
glVertex2f(-1.5,0);
glColor3f(.125,0.15, 0.1);
glVertex2f(-0.2,0);
glEnd();




glBegin(GL_TRIANGLES);
glColor3f(.8,0.498039,  0.196078);
glVertex2f(0,0.39);                   //mountain1
glColor3f(00.0,0.1, 0.0);
glVertex2f(0.4,0);
glColor3f(.125,0.15, 0.1);
glVertex2f(-0.4,0);
glEnd();


glBegin(GL_TRIANGLES);
glColor3f(.8,0.498039,  0.196078);
glVertex2f(0.8,0.37);                   //mountain1
glColor3f(00.0,0.1, 0.0);
glVertex2f(1.5,0);
glColor3f(.125,0.15, 0.1);
glVertex2f(0.2,0);
glEnd();








glBegin(GL_QUADS);
glColor3f(  0, .55, .0);
glVertex2f(-1,-0);           //grass
glColor3f(  0, .35, .0);
glVertex2f(-1,-1);
glColor3f(  0, .35, .0);
glVertex2f(1,-1);
glColor3f(  0, .55, .0);
glVertex2f(1,-0);
glEnd();







glColor3f(  0.4, .4, .0);
glBegin(GL_QUADS);
glVertex2f(-0.795,-0.04);           //tree1 trunk
glVertex2f(-0.795,-0.2);
glVertex2f(-0.775,-0.2);
glVertex2f(-0.775,-0.04);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.785,-0.02);                   //tree1 branch lowest
glVertex2f(-0.88,-0.05);
glVertex2f(-0.69,-0.05);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.785,0.00);                   //tree1 branch upper
glVertex2f(-0.87,-0.03);
glVertex2f(-0.70,-0.03);
glEnd();


glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.785,0.025);                   //tree1 branch uppermost
glVertex2f(-0.86,-0.01);
glVertex2f(-0.71,-0.01);
glEnd();


glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.785,0.030);                   //tree2 branch uppermost
glVertex2f(-0.84,0.01);
glVertex2f(-0.73,0.01);
glEnd();




glColor3f(  0.4, .4, .0);
glBegin(GL_QUADS);
glVertex2f(-0.495,-0.04);           //tree3 trunk
glVertex2f(-0.495,-0.2);
glVertex2f(-0.475,-0.2);
glVertex2f(-0.475,-0.04);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.485,-0.02);                   //tree3 branch lowest
glVertex2f(-0.58,-0.05);
glVertex2f(-0.39,-0.05);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.485,0.00);                   //tree3 branch upper
glVertex2f(-0.57,-0.03);
glVertex2f(-0.40,-0.03);
glEnd();


glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.485,0.025);                   //tree3 branch uppermost
glVertex2f(-0.56,-0.01);
glVertex2f(-0.41,-0.01);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.485,0.030);                   //tree2 branch uppermost
glVertex2f(-0.54,0.01);
glVertex2f(-0.43,0.01);
glEnd();









glColor3f(  0.4, .4, .0);
glBegin(GL_QUADS);
glVertex2f(0.495,-0.04);           //tree4 trunk
glVertex2f(0.495,-0.2);
glVertex2f(0.475,-0.2);
glVertex2f(0.475,-0.04);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.485,-0.02);                   //tree4 branch lowest
glVertex2f(0.58,-0.05);
glVertex2f(0.39,-0.05);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.485,0.00);                   //tree4 branch upper
glVertex2f(0.57,-0.03);
glVertex2f(0.40,-0.03);
glEnd();


glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.485,0.025);                   //tree4 branch uppermost
glVertex2f(0.56,-0.01);
glVertex2f(0.41,-0.01);
glEnd();
glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.485,0.030);                   //tree2 branch uppermost
glVertex2f(0.54,0.01);
glVertex2f(0.43,0.01);
glEnd();





glColor3f(  0.4, .4, .0);
glBegin(GL_QUADS);
glVertex2f(0.795,-0.04);           //tree2 trunk
glVertex2f(0.795,-0.2);
glVertex2f(0.775,-0.2);
glVertex2f(0.775,-0.04);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.785,-0.02);                   //tree2 branch lowest
glVertex2f(0.88,-0.05);
glVertex2f(0.69,-0.05);
glEnd();

glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.785,0.00);                   //tree2 branch upper
glVertex2f(0.87,-0.03);
glVertex2f(0.70,-0.03);
glEnd();


glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.785,0.025);                   //tree2 branch uppermost
glVertex2f(0.86,-0.01);
glVertex2f(0.71,-0.01);
glEnd();


glColor3f(0,.3, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.785,0.030);                   //tree2 branch uppermost
glVertex2f(0.84,0.01);
glVertex2f(0.73,0.01);
glEnd();





glColor3f( 0.52,0.39, 0.39);
glBegin(GL_QUADS);

glColor3f( 0.52,0.39, 0.39);
glVertex2f(-0.3,-0.25);                   //station

glColor3f( 0.9,0.39, 0.39);
glVertex2f(-0.3,0.05);

glColor3f( 0.9,0.39, 0.39);
glVertex2f(0.3,0.05);

glColor3f( 0.52,0.39, 0.39);
glVertex2f(0.3,-0.25);
glEnd();



glBegin(GL_QUADS);
glColor3f( 0.82,0.37, 0.26);
glVertex2f(-0.29,0.1);
glColor3f( 0.52,0.37, 0.26);                  //roof
glVertex2f(-0.33,0.0);
glColor3f( 0.52,0.37, 0.26);
glVertex2f(0.33,0.0);
glColor3f( 0.82,0.37, 0.26);
glVertex2f(0.29,0.1);
glEnd();


glColor3f(0.8,.8,0.0);
     glRasterPos2f(-.225,.03);
     declare("RAILWAY STATION");
glFlush();




glBegin(GL_QUADS);
glColor3f( 0.125,0.1, 0.15);
glVertex2f(-0.07,-0.1);
glColor3f( 0,0,0);
glVertex2f(-0.07,-0.25);
glColor3f( 0,0,0);                           //DOOR
glVertex2f(0.07,-0.25);
glColor3f( 0.125,0.1, 0.15);
glVertex2f(0.07,-0.1);
glEnd();



glBegin(GL_QUADS);
glColor3f( 0.196,0.6, 0.7);
glVertex2f(-0.23,-0.06);
glColor3f( 0.196,0.4, 0.45);
glVertex2f(-0.23,-0.16);
glColor3f( 0.196,0.4, 0.45);                  //window leeft
glVertex2f(-0.13,-0.16);
glColor3f( 0.196,0.6, 0.7);
glVertex2f(-0.13,-0.06);
glEnd();


glColor3f( 0.0,0.0, 0.0);
glBegin(GL_LINES);
glVertex2f(-0.18,-0.06);
glVertex2f(-0.18,-0.16);                   //window lines left


glVertex2f(-0.13,-0.11);
glVertex2f(-0.23,-0.11);
glEnd();


glColor3f( 0.196,0.6, 0.6);
glBegin(GL_QUADS);
glColor3f( 0.196,0.6, 0.7);
glVertex2f(0.23,-0.06);
glColor3f( 0.196,0.4, 0.45);
glVertex2f(0.23,-0.16);
glColor3f( 0.196,0.4, 0.45);                  //window right
glVertex2f(0.13,-0.16);
glColor3f( 0.196,0.6, 0.7);
glVertex2f(0.13,-0.06);
glEnd();


glColor3f( 0.0,0.0, 0.0);
glBegin(GL_LINES);
glVertex2f(0.18,-0.06);
glVertex2f(0.18,-0.16);                   //window lines right
glVertex2f(0.13,-0.11);
glVertex2f(0.23,-0.11);
glEnd();





glColor3f(0,0,0);                           //track line  lowermost
glBegin(GL_LINES);
glVertex2f(1,-0.77);
glVertex2f(-1,-0.77);

glVertex2f(1,-0.7);
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


glVertex2f(0.0,0.765);
glTranslatef(squareX, squareY , 0.0f);


glBegin(GL_POLYGON);                    //bird feather2
{
glColor3f(0.71,.65,.26);
glVertex2f(.325,0.810);
glColor3f(0.847059, 0.847059, 0.74912);
glVertex2f(.245,0.730);
glColor3f(0.847059, 0.847059, 0.74912);
glVertex2f(.280,0.710);
glColor3f(0.71,.65,.26);
glVertex2f(.355,0.750);
}
glEnd();


glBegin(GL_POLYGON);                    //birdbody2
glColor3f(0.71,.65,.26);
glVertex2f(0.23,0.775);
glVertex2f(0.26,0.792);
glVertex2f(0.29,0.777);
glVertex2f(0.32,.745);
glVertex2f(0.35,.725);
glVertex2f(0.35,.705);
glColor3f(0.847059, 0.847059, 0.74912);
glVertex2f(0.34,.695);
glColor3f(0.847059, 0.847059, 0.74912);
glVertex2f(0.30,.695);
glColor3f(0.847059, 0.847059, 0.74912);
glVertex2f(0.26,.710);
glColor3f(0.847059, 0.847059, 0.74912);;
glVertex2f(0.23,0.755);
glEnd();


glColor3f(1, 0.9, 0.0);
glBegin(GL_TRIANGLES);                  //bird beak2
glVertex2f(0.23,0.775);
glVertex2f(0.2,0.765);
glVertex2f(0.23,0.755);
glEnd();



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




glBegin(GL_POLYGON);
glColor3f(0,  0.0,  0.0);                 //Train 1 box  black
glVertex2f(-0.7+z,-0.30);   //1
glColor3f(0.1,  0.1,  0.1);
glVertex2f(-0.8+z,-0.50);   //2
glColor3f(0.1,  0.1,  0.1);
glVertex2f(-0.8+z,-0.70);   //3
glColor3f(0.1,  0.0,  0.1);
glVertex2f(-0.2+z,-0.70);   //4
glColor3f(0.0,  0.0,  0.0);
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







glBegin(GL_QUADS);
glColor3f(1, 1, 1);                     //Train 1 white window
glVertex2f(-0.7+z,-0.35);   //1
glColor3f(.5,.5,.5);
glVertex2f(-0.7+z,-0.48);   //2
glColor3f(.5,.5,.5);
glVertex2f(-0.62+z,-0.48);   //3
glColor3f(1, 1, 1);
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



glBegin(GL_QUADS);                        //Train 2 box  blue
glColor3f(0, 0, .6);
glVertex2f(-0.15+z,-0.30);   //1
glColor3f(0, 0, .0);
glVertex2f(-0.15+z,-0.70);   //3
glColor3f(0, 0, .0);
glVertex2f(0.25+z,-0.70);   //4
glColor3f(0, 0, .6);
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



glBegin(GL_QUADS);
glColor3f(0, 2, 2);                          //Train 2 cyan window left
glVertex2f(0.0+z,-0.35);   //1
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.0+z,-0.44);   //2
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.095+z,-0.44);   //3
glColor3f(0, 2, 2);
glVertex2f(0.095+z,-0.35);   //4
glEnd();



glBegin(GL_QUADS);
glColor3f(0, 2, 2);                         //Train 2 cyan window right
glVertex2f(0.115+z,-0.35);   //1
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.115+z,-0.44);   //2
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.21+z,-0.44);   //3
glColor3f(0, 2, 2);
glVertex2f(0.21+z,-0.35);   //4
glEnd();



glColor3f(0, 0, 1);
glBegin(GL_QUADS);                        //Train 3 box  blue
glColor3f(0, 0, .6);
glVertex2f(0.30+z,-0.30);   //1
glColor3f(0, 0, .00);
glVertex2f(0.30+z,-0.70);   //3
glColor3f(0, 0, .00);
glVertex2f(0.70+z,-0.70);   //4
glColor3f(0, 0, .6);
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





glBegin(GL_QUADS);                          //Train 3 cyan window left
glColor3f(0, 2, 2);
glVertex2f(0.45+z,-0.35);   //1
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.45+z,-0.44);   //2
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.545+z,-0.44);   //3
glColor3f(0, 2, 2);
glVertex2f(0.545+z,-0.35);   //4
glEnd();



glBegin(GL_QUADS);
glColor3f(0, 2, 2);                    //Train 3 cyan window right
glVertex2f(0.565+z,-0.35);   //1
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.565+z,-0.44);   //2
glColor3f( 0.0 , 0.4,  0.4);
glVertex2f(0.66+z,-0.44);   //3
glColor3f(0, 2, 2);
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
glutTimerFunc(0, Timer, 0);
initGL();
glutMainLoop();
return 0;
}


