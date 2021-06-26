#ifndef DESENHA_H_INCLUDED
#define DESENHA_H_INCLUDED
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

#define MAX 500
typedef struct {
    double x;
    double y;
}COORD2D;

typedef struct {
    COORD2D ponto[MAX];
    int quantidade;
}VERTICES2D;


void desenhaPontos2D(VERTICES2D p);

#endif