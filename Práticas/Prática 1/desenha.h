#ifndef DESENHA_H_INCLUDED
#define DESENHA_H_INCLUDED
#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <GL/gl.h>
#include <GL/glut.h>

#define LINHAS 4
#define COLUNAS 4
#define WIDTH 600
#define HEIGTH 400

typedef struct {
    GLfloat dx, dy, dz;
}Deslocamento;

typedef struct {
    GLfloat r, g, b;
}Cores;


void init(Deslocamento* deslocamento, Cores* cores);
void Triangulo(Cores cores, Deslocamento deslocamento);

#endif