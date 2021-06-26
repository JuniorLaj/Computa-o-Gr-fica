#include "desenha.h"

void init(Deslocamento* deslocamento, Cores* cores){
    glClearColor(1.0,1.0,1.0,1.0);
    for(int i=0; i<LINHAS*COLUNAS; i++){
        deslocamento[i] = {0,0,0};
        GLfloat r = rand() % 2;
        GLfloat g = rand() % 2;
        GLfloat b = rand() % 2;
        r >= 0.9 && g >= 0.9 && b >= 0.9 ? b-=0.3 : b = b;
        cores[i] = {r,g,b};
    }
}

void Triangulo(Cores cores, Deslocamento deslocamento){
    glColor3f(cores.r, cores.g, cores.b);
    glLoadIdentity();
    glTranslatef(deslocamento.dx, deslocamento.dy, deslocamento.dz);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,1);
    glVertex2f(0,-1);
    glVertex2f(1,0);
    glEnd();

}

