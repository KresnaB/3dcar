#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

/*
author dan pemilik : Kresna Bayu Sanyoto 181511051 JTK POLBAN
dibuat pada : 10 Januari 2021
matkul : komputer grafik
*/
GLfloat rotateTire, angleCar = -0.0f;
GLint spin_x = 0;
GLint spin_y = 0;
GLfloat New_x;
GLfloat New_y;
GLfloat Zoom = 1;
GLfloat movement= 0;
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, -3.0f, -40.0f);
    glRotatef(spin_x+35, 0.0, 1.0, 0.0);
    glRotatef(spin_y+25, 0.0, 0.0, 1.0);
    glScalef(Zoom, Zoom, Zoom);
    GLfloat ground[8][3] =
    {
        {-4,-0.5,40.0},
        {4,-0.5,40.0},
        {4,-0.5,-40.0},
        {-4,-0.5,-40.0},

        {-20,-0.6,40.0},
        {20,-0.6,40.0},
        {20,-0.6,-40.0},
        {-20,-0.6,-40.0},

    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(ground)/sizeof(ground[0]);i++){
            if (i>3){
                glColor3f(0.176, 0.623, 0.098);
            }else{
                glColor3f(0.207, 0.227, 0.231);

            }
            glVertex3f(ground[i][0],ground[i][1],ground[i][2]+movement);
        }
    glEnd();
    // badan mobil bagian depan
    GLfloat frontBody[14][3] =
    {
        {2.8,1.0,10.5},
        {3.0,1.0,8.0},
        {2.8,3.5,10.5},
        {3.0,4.0,8.0},
        {0.0,3.5,10.7},
        {0.0,4.0,8.0},
        {-2.8,3.5,10.5},
        {-3.0,4.0,8.0},
        {-2.8,1.0,10.5},
        {-3.0,1.0,8.0},
        {0.0,1.1,10.7},
        {0.0,1.1,8.0},
        {2.8,1.0,10.5},
        {3.0,1.0,8.0},

    };
    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i< sizeof(frontBody)/sizeof(frontBody[0]);i++){
            glColor3f(0.956, 0.592, 0.203);
            glVertex3f(frontBody[i][0],frontBody[i][1],frontBody[i][2]+movement);
        }
    glEnd();
    // depan mobil | bagian bumper depan
    GLfloat grill[6][3] =
    {
        {2.8,1.0,10.5},
        {2.8,3.5,10.5},
        {0.0,1.1,10.7},
        {0.0,3.5,10.7},
        {-2.8,1.0,10.5},
        {-2.8,3.5,10.5},

    };
    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i< sizeof(grill)/sizeof(grill[0]);i++){
            glColor3f(0.964, 0.639, 0.298);
            glVertex3f(grill[i][0],grill[i][1],grill[i][2]+movement);
        }
    glEnd();
    //lampu depan
    GLfloat frontLight[8][3] =
    {
        {2.6,3.2,10.55},
        {1.6,3.2,10.6},
        {1.6,2.7,10.6},
        {2.6,2.7,10.55},

        {-2.6,3.2,10.55},
        {-1.6,3.2,10.6},
        {-1.6,2.7,10.6},
        {-2.6,2.7,10.55},

    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(frontLight)/sizeof(frontLight[0]);i++){
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(frontLight[i][0],frontLight[i][1],frontLight[i][2]+movement);
        }
    glEnd();
    // cap mesin depan
    GLfloat hood[4][3] =
    {
        {3.0,4.0,8.0},
        {3.0,4.0,4.0},
        {-3.0,4.0,4.0},
        {-3.0,4.0,8.0},
    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(hood)/sizeof(hood[0]);i++){
            glColor3f(0.956, 0.541, 0.101);
            glVertex3f(hood[i][0],hood[i][1],hood[i][2]+movement);
        }
    glEnd();
    //panel body di atas ban kiri depan
    GLfloat leftTirePanel[7][3] =
    {
        {-3.0,1.0,8.0},
        {-3.0,4.0,8.0},
        {-3.0,2.5,7.0},
        {-3.0,4.0,6.0},
        {-3.0,2.5,5.0},
        {-3.0,4.0,4.0},
        {-3.0,1.0,4.0},
    };
    glBegin(GL_TRIANGLE_STRIP);
        for(int i = 0; i< sizeof(leftTirePanel)/sizeof(leftTirePanel[0]);i++){
            glVertex3f(leftTirePanel[i][0],leftTirePanel[i][1],leftTirePanel[i][2]+movement);
        }
    glEnd();
    //panel body di atas ban kanan depan
    GLfloat rightTirePanel[7][3] =
    {
        {3.0,1.0,8.0},
        {3.0,4.0,8.0},
        {3.0,2.5,7.0},
        {3.0,4.0,6.0},
        {3.0,2.5,5.0},
        {3.0,4.0,4.0},
        {3.0,1.0,4.0},
    };
    glBegin(GL_TRIANGLE_STRIP);
        for(int i = 0; i< sizeof(rightTirePanel)/sizeof(rightTirePanel[0]);i++){
            glVertex3f(rightTirePanel[i][0],rightTirePanel[i][1],rightTirePanel[i][2]+movement);
        }
    glEnd();
    // rangka kaca depan
    GLfloat frontGlassRim[4][3] =
    {
        {-3.0,4.0,4.0},
        {3.0,4.0,4.0},
        {3.0,6.0,1.0},
        {-3.0,6.0,1.0},
    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(frontGlassRim)/sizeof(frontGlassRim[0]);i++){
            glVertex3f(frontGlassRim[i][0],frontGlassRim[i][1],frontGlassRim[i][2]+movement);
        }
    glEnd();
    // kaca depan
    GLfloat frontGlass[4][3] =
    {
        {-2.8,4.0,4.08},
        {2.8,4.0,4.08},
        {2.8,5.9,1.14},
        {-2.8,5.9,1.14},
    };
    glBegin(GL_QUADS);
        glColor3f(0.317, 0.309, 0.301);
        for(int i = 0; i< sizeof(frontGlass)/sizeof(frontGlass[0]);i++){
            glVertex3f(frontGlass[i][0],frontGlass[i][1],frontGlass[i][2]+movement);
        }
    glEnd();
    //atap mobil
    GLfloat roof[4][3] =
    {
        {-3.0,6.0,1.0},
        {3.0,6.0,1.0},
        {3.0,6.0,-3.0},
        {-3.0,6.0,-3.0},
    };
    glBegin(GL_QUADS);
        glColor3f(0.913, 0.494, 0.047);
        for(int i = 0; i< sizeof(roof)/sizeof(roof[0]);i++){
            glVertex3f(roof[i][0],roof[i][1],roof[i][2]+movement);
        }
    glEnd();
    //pintu sebelah kiri
    GLfloat leftBody[8][3] =
    {
        {-3.0,4.0,4.0},
        {-3.0,6.0,1.0},
        {-3.0,6.0,-3.0},
        {-3.0,4.5,-5.0},
        {-3.0,2.5,-5.0},
        {-3.0,1.0,-4.0},
        {-3.0,1.0,1.5},
        {-3.0,1.0,4.0},
    };
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i< sizeof(leftBody)/sizeof(leftBody[0]);i++){
            glColor3f(0.960, 0.6, 0.219);
            glVertex3f(leftBody[i][0],leftBody[i][1],leftBody[i][2]+movement);
        }
    glEnd();
    //pintu sebelah kanan
    GLfloat rightBody[8][3] =
    {
        {3.0,4.0,4.0},
        {3.0,6.0,1.0},
        {3.0,6.0,-3.0},
        {3.0,4.5,-5.0},
        {3.0,2.5,-5.0},
        {3.0,1.0,-4.0},
        {3.0,1.0,1.5},
        {3.0,1.0,4.0},
    };
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i< sizeof(rightBody)/sizeof(rightBody[0]);i++){
            glVertex3f(rightBody[i][0],rightBody[i][1],rightBody[i][2]+movement);
        }
    glEnd();
    //bawah mobil
    GLfloat bottom[4][3] =
    {
        {-3.0,1.0,4.0},
        {3.0,1.0,4.0},
        {3.0,1.0,-4.0},
        {-3.0,1.0,-4.0},
    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(bottom)/sizeof(bottom[0]);i++){
            glVertex3f(bottom[i][0],bottom[i][1],bottom[i][2]+movement);
        }
    glEnd();
    // kaca kiri depan
    GLfloat rightGlassOne[4][3] =
    {
        {-3.1,4.0,3.5},
        {-3.1,5.8,0.8},
        {-3.1,5.8,-0.8},
        {-3.1,4.0,-0.8},
    };
    glBegin(GL_QUADS);
        glColor3f(0.317, 0.309, 0.301);
        for(int i = 0; i< sizeof(rightGlassOne)/sizeof(rightGlassOne[0]);i++){
            glVertex3f(rightGlassOne[i][0],rightGlassOne[i][1],rightGlassOne[i][2]+movement);
        }
    glEnd();
    // kaca kanan depan
    GLfloat leftGlassOne[4][3] =
    {
        {3.1,4.0,3.5},
        {3.1,5.8,0.8},
        {3.1,5.8,-1.0},
        {3.1,4.0,-1.0},
    };
    glBegin(GL_QUADS);
        glColor3f(0.317, 0.309, 0.301);
        for(int i = 0; i< sizeof(leftGlassOne)/sizeof(leftGlassOne[0]);i++){
            glVertex3f(leftGlassOne[i][0],leftGlassOne[i][1],leftGlassOne[i][2]+movement);
        }
    glEnd();
    GLfloat handle[8][3] =
    {
        {3.1,3.5,0.0},
        {3.1,3.5,0.8},
        {3.1,3.2,0.8},
        {3.1,3.2,0.0},

        {-3.1,3.5,0.0},
        {-3.1,3.5,0.8},
        {-3.1,3.2,0.8},
        {-3.1,3.2,0.0},
    };
    glBegin(GL_QUADS);
        glColor3f(0.317, 0.309, 0.301);
        for(int i = 0; i< sizeof(handle)/sizeof(handle[0]);i++){
            glVertex3f(handle[i][0],handle[i][1],handle[i][2]+movement);
        }
    glEnd();
    // kaca belakang
    GLfloat backGlass[7][3] =
    {
        {-2.8,5.9,-3.3},
        {2.8,5.9,-3.3},
        {2.8,4.5,-5.0},
        {-2.8,4.5,-5.0},
    };
    glBegin(GL_QUADS);
        glColor3f(0.317, 0.309, 0.301);
        for(int i = 0; i< sizeof(backGlass)/sizeof(backGlass[0]);i++){
            glVertex3f(backGlass[i][0],backGlass[i][1],backGlass[i][2]+movement);
        }
    glEnd();
    //rangka kaca belakang
    GLfloat backGlassRim[4][3] =
    {
        {-3.0,6.0,-3.0},
        {3.0,6.0,-3.0},
        {3.0,4.5,-5.0},
        {-3.0,4.5,-5.0},
    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(backGlassRim)/sizeof(backGlassRim[0]);i++){
            glColor3f(0.956, 0.560, 0.145);
            glVertex3f(backGlassRim[i][0],backGlassRim[i][1],backGlassRim[i][2]+movement);
        }
    glEnd();
    //panel body di atas ban kelakang
    GLfloat backTirePanel[10][3] =
    {
        {3.0,2.5,-5.0},
        {3.0,2.5,-7.5},
        {3.0,4.5,-5.0},
        {3.0,4.0,-7.0},
        {-3.0,4.5,-5.0},
        {-3.0,4.0,-7.0},
        {-3.0,2.5,-5.0},
        {-3.0,2.5,-7.5},
        {3.0,2.5,-5.0},
        {3.0,2.5,-7.5},
    };
    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i< sizeof(backTirePanel)/sizeof(backTirePanel[0]);i++){
            glVertex3f(backTirePanel[i][0],backTirePanel[i][1],backTirePanel[i][2]+movement);
        }
    glEnd();
    //bodi belakang
    GLfloat backBody[10][3] =
    {
        {3.0,1.0,-8.0},
        {3.0,1.5,-10.0},
        {3.0,4.0,-7.0},
        {3.0,4.5,-10.5},
        {-3.0,4.0,-7.0},
        {-3.0,4.5,-10.5},
        {-3.0,1.0,-8.0},
        {-3.0,1.5,-10.0},
        {3.0,1.0,-8.0},
        {3.0,1.5,-10.0},
    };
    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i< sizeof(backBody)/sizeof(backBody[0]);i++){
            glColor3f(0.964, 0.6, 0.215);
            glVertex3f(backBody[i][0],backBody[i][1],backBody[i][2]+movement);
        }
    glEnd();
    //bumper belakang
    GLfloat bumper[10][3] =
    {
        {-3.0,1.5,-10.0},
        {3.0,1.5,-10.0},
        {3.0,4.5,-10.5},
        {-3.0,4.5,-10.5},
    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(bumper)/sizeof(bumper[0]);i++){
            glColor3f(0.964, 0.631, 0.274);
            glVertex3f(bumper[i][0],bumper[i][1],bumper[i][2]+movement);
        }
    glEnd();
    GLfloat backLight[10][3] =
    {
        {-2.6,3.5,-10.4},
        {-1.2,3.5,-10.4},
        {-1.2,4.2,-10.5},
        {-2.6,4.2,-10.5},

        {2.6,3.5,-10.4},
        {1.2,3.5,-10.4},
        {1.2,4.2,-10.5},
        {2.6,4.2,-10.5},
    };
    glBegin(GL_QUADS);
        for(int i = 0; i< sizeof(backLight)/sizeof(backLight[0]);i++){
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(backLight[i][0],backLight[i][1],backLight[i][2]+movement);
        }
    glEnd();
    //ban
    glColor3f(0.470, 0.517, 0.529);
    //tire front right
    glTranslatef(3.0f, 1.0f, 6.0f);
    glTranslatef(0.0f, 0.0f, movement);
    glRotatef(90,0,1,0);
    glutSolidTorus(0.75,0.75,10,10);
    glRotatef(-90,0,1,0);
    glTranslatef(0.0f, 0.0f, -movement);
    //tire front left
    glTranslatef(-6.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, movement);
    glRotatef(90,0,1,0);
    glutSolidTorus(0.75,0.75,10,10);
    glRotatef(-90,0,1,0);
    glTranslatef(0.0f, 0.0f, -movement);
    //tire back left
    glTranslatef(0.0f, 0.0f, -12.0f);
    glTranslatef(0.0f, 0.0f, movement);
    glRotatef(90,0,1,0);
    glutSolidTorus(0.75,0.75,10,10);
    glRotatef(-90,0,1,0);
    glTranslatef(0.0f, 0.0f, -movement);
    //tire back right
    glTranslatef(6.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, movement);
    glRotatef(90,0,1,0);
    glutSolidTorus(0.75,0.75,10,10);
    glRotatef(-90,0,1,0);
    glTranslatef(0.0f, 0.0f, -movement);


    angleCar-= 0.15f;
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    if (h == 0) h = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}
void time(int x){
    glutPostRedisplay();
    glutTimerFunc(1000/60, time, 0);
}
void specialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		spin_y += 1;
		spin_y = spin_y % 360;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_DOWN:
	{
		spin_y -= 1;
		spin_y = spin_y % 360;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_LEFT:
	{
		spin_x += 1;
		spin_x = spin_x % 360;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		spin_x -= 1;
		spin_x = spin_x % 360;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_PAGE_UP:
	{
		Zoom = Zoom + 0.01;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_PAGE_DOWN:
	{
		if (Zoom >= 0) {
			Zoom = Zoom - 0.01;
		}
		glutPostRedisplay();
		break;
	}
	}
}
void mouseMovement(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		New_x = x;
		New_y = y;
	}
}
void mouseMotion(int x, int y)
{
	spin_x = x - New_x;
	spin_y = y - New_y;
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key){
    case 'w':
        {
            movement+=0.20;
            glutPostRedisplay();
            break;
        }
    case 's':
        {
            movement-=0.20;
            glutPostRedisplay();
            break;
        }

    }

}
void scroll (int button, int dir, int x, int y){
    if (dir > 0){
        Zoom = Zoom + 0.01;
		glutPostRedisplay();
    }else{
        if (Zoom >= 0) {
			Zoom = Zoom - 0.01;
		}
		glutPostRedisplay();
    }
}
int main(int argc, char** argv)
{
    cout << "List funngsi keyboard dan mouse\n";
    cout << "Klik mouse lalu drag dan lepas pada sumbu x dan y -> digunakan untuk merotate objek di sumbu x dan y\n";
    cout << "Scroll kedepan untuk zoom in || scroll kebelakang untuk zoom out\n";
    cout << "w untuk memajukan mobil, s untuk memundurkan mobil\n";
    cout << "page up untuk zoom in dan page down untuk zoom out\n";
    cout << "arrow key kanan dan kiri untuk rotasi pada sumbu x dan arrow key atas dan bawah untuk rotasi sumbu y\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("mobil");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKey);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseMovement);
	glutMotionFunc(mouseMotion);
	glutMouseWheelFunc(scroll);
    init();
    glutMainLoop();
    return 0;
}
