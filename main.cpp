#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;

void init(void)
{
	glClearColor(0.0, 0.8, 1.5, 1.5);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

///=================///
///*** All_Model ***///
///=================///


///*** Circle_Model ***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

/// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(500,0,0);
    circle(30);
    glPopMatrix();
}
void Moving_Sun(){
    glPushMatrix();
    glRotatef(-sun_spin, 0,0,-0.009);
    Sun_Model();
    glPopMatrix();
}

///*** Cloud_Model***///
void cloud_one(){

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();

    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();
    ///****Fill End****///
}

void cloud_Two(){

    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();
}

///*** Hill_Model***///
void hill(){

    ///Hill
	glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);
	glEnd();

	///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
	glVertex2i(200, 225);
	glVertex2i(230, 190);
	glVertex2i(220, 180);
	glVertex2i(200, 190);
	glVertex2i(190, 180);
	glVertex2i(170, 190);
	glEnd();
}

///*** House_Model ***///
void house(){
    ///House_Roof
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);
	glEnd();

    ///House_Fence
	glBegin(GL_QUADS);
    glColor3f(1.5, 1.5, 1.5);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();

    ///House_Door
	glBegin(GL_QUADS);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);
	glEnd();

    ///House_Window1
	glBegin(GL_QUADS);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);
	glEnd();

    ///House_Window2
	glBegin(GL_QUADS);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);
	glEnd();

    ///House_Window3
	glBegin(GL_QUADS);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);
	glEnd();

    ///House_Small_Roof
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);
	glEnd();

    ///House_Small_Fence
	glBegin(GL_QUADS);
    glColor3f(1.5, 1.5, 0.5);
    glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);
	glEnd();

    ///House_Small_Door
	glBegin(GL_QUADS);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);
	glEnd();
}

///*** Field_Model ***///
void field(){

   ///Green Field
	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.8, 0.0);
	glVertex2i(0, 50);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 50);
	glEnd();

    ///Road Field
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(0, 0);
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, 0);
	glEnd();

	///Road Bumps
	glColor3ub(255,255,255);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(1000,50);
	glVertex2f(1000,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(950,50);
	glVertex2f(950,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(900,50);
	glVertex2f(900,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(850,50);
	glVertex2f(850,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(800,50);
	glVertex2f(800,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(600,50);
	glVertex2f(600,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(550,50);
	glVertex2f(550,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(500,50);
	glVertex2f(500,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(450,50);
	glVertex2f(450,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(400,50);
	glVertex2f(400,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(200,50);
	glVertex2f(200,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(150,50);
	glVertex2f(150,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(100,50);
	glVertex2f(100,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(50,50);
	glVertex2f(50,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0,50);
	glVertex2f(0,0);
	glEnd();
}

///*** Tree_Model ***///
void Tree_Model(){

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(109, 70);
	glVertex2i(109, 90);
	glVertex2i(111, 90);
	glVertex2i(111, 70);
    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///
void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();
}

///*** Windmill_Final_Model ***///
void Windmill(){

     ///Windmill_Stand
    glColor3f(0.11, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();
}
///=====================///
///***   Model_End  ***///
///===================///




///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun();
    glPopMatrix();
}

///*** Cloud_One_Model_One ***///
void cloud1(){
    glPushMatrix();
    glTranslatef(cx,-40,0);
    cloud_one();
    glPopMatrix();
}

///*** Cloud_Two_Model_one ***///
void cloud2(){
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    cloud_one();
    glPopMatrix();
}

///*** Cloud_Three_Model_Two ***///
void cloud3(){
    glPushMatrix();
    glTranslatef(ax-80,80,0);
    cloud_Two();
    glPopMatrix();

}

///*** Cloud_Four_Model_Two ***///
void cloud4(){
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_Two();
    glPopMatrix();
}

///*** House_One ***///
void house_one(){
    glPushMatrix();
    glTranslatef(0,0,0);
    house();
    glPopMatrix();
}

///*** House_Two ***///
void house_two(){
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}

///*** Hill_big_One ***///
void Hill_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill();
    glPopMatrix();
}

///*** Hill_big_Two ***///
void Hill_Two(){
    glPushMatrix();
    glTranslatef(550,-20,0);
    hill();
    glPopMatrix();
}

///*** Tree_1 ***///
void Tree_One(){
     glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two(){
     glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(540,0,0);
    Tree_Model();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three(){
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();
}

void Windmill_Two(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,-90,0);
    Windmill();
    glPopMatrix();
}

///=======================///
///***   Object Ends  ***///
///=====================///



///========================///
///*** Display Function ***///
///========================///

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

    ///*** Object_Layer ***///

    ///*** Sun ***///
    Sun();

    ///*** Windmills ***///
    Windmill_One();
    Windmill_Two();

    ///*** Hills ***///
    Hill_One();
    Hill_Two();

    ///*** Clouds ***///
    cloud1();
    cloud2();
    cloud3();
    cloud4();

    ///*** Houses ***///
    house_one();
    house_two();

    ///*** Trees ***///
    Tree_One();
    Tree_Two();
    Tree_Three();

    ///*** Field ***///
    field();

	glFlush();
}
///========================///
///*** Speed & Movement ***///
///========================///

///*** Sun_Move ***///
void sun_move(){

    sun_spin = sun_spin + 0.0008;

}
void move_right(){

    sun_move();

    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
}
    if(bx>1000){
            bx= -400;}
    if(cx>1000){
            cx= -400;}
    if(dx>1000){
            dx= -500;}
    glutPostRedisplay();
}
///*** Mouse_Click_To_Move_The_Objects ***///
void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

///*** The main function ***///
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200,0);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("  Our Small Village  19101522 / 19100190 / 19100219");
	init();
	glutDisplayFunc(display);
    glutMouseFunc(mouse);
	glutMainLoop();
}
