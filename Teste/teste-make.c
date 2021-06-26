////////////////////////////////////////////////////////////////////////////////////////////
// bezierCurves.cpp
// 
// This program shows Bezier curves of orders 2 to 6, where each control point can be moved.
// Also drawn is the control polygon.
//
// Interaction:
// Press the up/down arrows to select an order and press enter.
// Press space to select a control point. 
// Press the arrow keys to move the selected control point.
// Press delete to reset.
//
// Sumanta Guha
////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>

void Desenha(){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glColor3f(0.0, 1.0, 0.0); //set ball colour
   glTranslatef(10, 10, 10); //moving it toward the screen a bit on creation
   glutSolidSphere(1,10,10);
   glutSwapBuffers();
}
// Main routine.
int main(int argc, char** argv){
    glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   glutInitWindowSize(720, 720);

   glutCreateWindow("Moving Circle");

   glEnable(GL_DEPTH_TEST);

   glutDisplayFunc(Desenha);

   glutMainLoop();
}