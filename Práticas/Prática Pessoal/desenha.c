#include "desenha.h"

void desenhaPontos2D(VERTICES2D c) {
    for(int i=0; i<c.quantidade; i++){  
        glVertex2f(c.ponto[i].x,c.ponto[i].y);
    }
}