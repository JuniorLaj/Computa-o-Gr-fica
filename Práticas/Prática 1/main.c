#include "desenha.h"

Deslocamento deslocamento[LINHAS*COLUNAS];
Cores cores[LINHAS*COLUNAS];

void InputMouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        GLuint aux = 0;
        for(int l=0; l<LINHAS; l++){
            GLfloat xmin =  l*WIDTH/LINHAS;
            GLfloat xmax =  l*WIDTH/LINHAS + WIDTH/LINHAS;
            for(int c=0; c<COLUNAS; c++){
                GLfloat ymin = HEIGTH - (c+1)*HEIGTH/COLUNAS;
                GLfloat ymax = HEIGTH - c*HEIGTH/COLUNAS + HEIGTH/COLUNAS;
                if(x >= xmin && x<= xmax && y>= ymin && y<= ymax){
                    cores[aux].r = sqrt(pow(1 - rand() % 2,2));
                    cores[aux].g = sqrt(pow(1 - rand() % 2,2));
                    cores[aux].b = sqrt(pow(1 - rand() % 2,2));
                    glutPostRedisplay();
                    return;
                }else {
                    aux++;
                }   
            }
        }
    }
}

void Desenha(){
    GLuint aux = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    for(int l=0; l<LINHAS; l++){
        for(int c=0; c<COLUNAS; c++){
            glViewport(l*WIDTH/LINHAS,c*HEIGTH/COLUNAS,WIDTH/LINHAS,HEIGTH/COLUNAS);
            Triangulo(cores[aux],deslocamento[aux]);
            aux++;
        }
    }
    glFlush();
}

int main(int argc, char** argv){
    srand(time(NULL));
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WIDTH,HEIGTH);
    glutCreateWindow("Segunda pratica Computacao Grafica");
    init(deslocamento,cores);
    glutMouseFunc(InputMouse);
    glutDisplayFunc(Desenha);
    glutMainLoop();
    
}