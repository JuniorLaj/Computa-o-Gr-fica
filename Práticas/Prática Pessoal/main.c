#include <iostream>
#include <windows.h>
#include <math.h>
#include <pthread.h>
#include <GL/gl.h>
#include <GL/glut.h>

typedef struct {
    GLfloat x, y;
}Points2D;

typedef struct {
    GLfloat x, y, z;
}Points3D;

GLfloat secDia = 24*60*60;
GLfloat displayX = 1280;
GLfloat displayY = 720;
GLfloat freq = 256;
GLfloat raioSol = 1;
GLfloat distanciaDoSolAoPlaneta = 4;
GLfloat tx = distanciaDoSolAoPlaneta;
GLfloat ty = 0;
GLfloat thetaInicial = 0;
GLfloat offsetPlanetaTerra = 0.00261799f;

void* run() {
    for(int i=0; i<secDia; i++){
        tx = distanciaDoSolAoPlaneta*cos(thetaInicial + offsetPlanetaTerra);
        ty = distanciaDoSolAoPlaneta*sin(thetaInicial + offsetPlanetaTerra);
        thetaInicial+=offsetPlanetaTerra;
        glutPostRedisplay();
    }
}
void EixoCoordenado(float r, float g, float b){
    double t=0;
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,+1);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(0,displayY);
    glVertex2f(0,-displayY);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-displayX,0);
    glVertex2f(displayX,0);
    glEnd();
}

void Sol(float r, float g, float b){
    double t=0, freq = 1024;
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,+1);
    glLineWidth(4);
    glBegin(GL_POLYGON);
    GLfloat thetaAnt = 0;
    for(int t=0; t<freq; t++){
        GLdouble theta = 2*M_PI*t/freq;  
        GLfloat x = raioSol*cos(thetaAnt+theta);
        GLfloat y = raioSol*sin(thetaAnt+theta);
        glVertex2f(x,y);
        thetaAnt = theta;
    }
    glEnd();
}

void Planeta2(float r, float g, float b){
    double t=0;
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,+1);
    glTranslatef(tx,ty,0);
    glBegin(GL_POLYGON);
    for(int t=0; t<freq; t++){
        GLdouble theta = 2*M_PI*t/freq;  
        GLfloat x = cos(theta);
        GLfloat y = sin(theta);
        glVertex2f(x,y);
    }
    glEnd();
}

void Teclado(unsigned char key, int x, int y){
    if(key=='o'){
        pthread t1;
        pthread_create(&t1, NULL, run, NULL);
    }
}

void Desenha(){
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    EixoCoordenado(0.0,0.0,0.0);
    Sol(1.0,1.0,0.0);
    Planeta2(0.0,1.0,1.0);
    glFlush();
}




int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("Sistema planetário 2D");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    
}