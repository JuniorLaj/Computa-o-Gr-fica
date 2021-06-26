#include <iostream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

typedef struct {
    GLfloat x, y;
}Points2D;

typedef struct {
    GLfloat x, y, z;
}Points3D;


GLfloat pontosQuestao1e2[6][2]  = {{1,1},{6,1}, {6,5}, {3,3}, {1,6}, {1,1} };
GLfloat pontosQuestao3e4[5][2] = {{2,1}, {6,1}, {6,2}, {2,2}, {2,1}};
GLfloat pontosQuestao7A[4][2] = {{-1,0}, {0,1}, {1,0}, {-1,0}};
GLfloat pontosQuestao7B[5][2] = {{0,-1}, {0,1}, {1,1}, {1,-1}, {0,-1}};
GLfloat pontosQuestao7C[3][2] = {{0,0}, {0,1}, {1,0}};

/*
#pragma region 'Exercício de Bezier do livro'
    void plotPoint (Points3D bezCurvePt) {
        glBegin(GL_POINTS);
        glVertex2f(bezCurvePt.x, bezCurvePt.y);
        glEnd();
    }

    void computeBezPt(GLfloat u, Points3D *bezPt, GLint nCtrlPts, Points3D * ctrlPoints, GLint *C){
        int k, n = nCtrlPts - 1;
        GLfloat bezBlendFcn;
        bezPt->x = bezPt->y = bezPt->z = 0.0;
        for (k = 0; k < nCtrlPts; k++){
            bezBlendFcn = C[k]*pow(u, k)*pow(1 - u, n - k);
            bezPt->x += ctrlPoints[k].x * bezBlendFcn;
            bezPt->y += ctrlPoints[k].y * bezBlendFcn;
            bezPt->z += ctrlPoints[k].z * bezBlendFcn;
        }
    }

    void bezier(int qtCtrlPoints, Points3D ctrlPoints[], int nBezCurvePoints){
        Points3D bezCurvePt;
        GLfloat u;
        GLint C[qtCtrlPoints];
        for(int k=0; k<=qtCtrlPoints-1; k++){
            C[k] = 1;
            for(int j= qtCtrlPoints; j >= k+1; j--){
                C[k] *= j; 
            }
            for(int j = qtCtrlPoints -k; j >= 2; j--){
                C[k] /= j;
            }
        }

        for(int k=0; k <= nBezCurvePoints; k++){
            u = GLfloat(k) / GLfloat(nBezCurvePoints);
            computeBezPt(u, &bezCurvePt, qtCtrlPoints, ctrlPoints, C);
            plotPoint(bezCurvePt);
        }
    }

    void DesenhaQuestao6Livro(float r, float g, float b){
        int nBezCurvePoints = 1000;
        int qtPoints = 5;
        Points3D pontosQuestao6Ctrl[4] = { {0.0, 2.0, 0.0}, {1.0, -2.0, 0.0}, {3.0, 0.0, 0.0}, {4.0, 3.0, 0.0} };
        glPointSize(qtPoints);
        glColor3f(r,g,b);
        bezier(qtPoints,pontosQuestao6Ctrl,nBezCurvePoints);
        glFlush();
    }

#pragma endregion
*/
void DesenhaQuestao7C(float r, float g, float b){
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-1,+1);
    glBegin(GL_POLYGON);
    for(int i=0; i<3; i++){
        glVertex2f(pontosQuestao7C[i][0],pontosQuestao7C[i][1]);
    }
    glEnd();
}
void DesenhaQuestao7B(float r, float g, float b){
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-1,+1);
    glBegin(GL_POLYGON);
    for(int i=0; i<5; i++){
        glVertex2f(pontosQuestao7B[i][0],pontosQuestao7B[i][1]);
    }
    glEnd();
}
void DesenhaQuestao7A(float r, float g, float b){
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-1,+1);
    glBegin(GL_POLYGON);
    for(int i=0; i<4; i++){  
        glVertex2f(pontosQuestao7A[i][0],pontosQuestao7A[i][1]);
    }
    glEnd();
}


void DesenhaQuestao6(float r, float g, float b){
    Points3D pontosQuestao6Ctrl[4] = { {0.0, 2.0, 0.0}, {1.0, -2.0, 0.0}, {3.0, 0.0, 0.0}, {4.0, 3.0, 0.0} };
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-1,+1);
    glLineWidth(4);
    double t=0;
    glBegin(GL_LINE_STRIP);
    while(t<1){
        GLfloat curvaBezier4pontosX = pow(1-t,3)*pontosQuestao6Ctrl[0].x + 3*t*pow(1-t,2)*pontosQuestao6Ctrl[1].x + 3*(pow(t,2))*(1-t)*pontosQuestao6Ctrl[2].x + pow(t,3)*pontosQuestao6Ctrl[3].x;
        GLfloat curvaBezier4pontosY = pow(1-t,3)*pontosQuestao6Ctrl[0].y + 3*t*pow(1-t,2)*pontosQuestao6Ctrl[1].y + 3*(pow(t,2))*(1-t)*pontosQuestao6Ctrl[2].y + pow(t,3)*pontosQuestao6Ctrl[3].y;
        glVertex2f(curvaBezier4pontosX, curvaBezier4pontosY);
        t+=0.05;
    }
    glEnd();

}
void DesenhaQuestao5(float r, float g, float b){
    double t=0;
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,+1);
    glBegin(GL_POLYGON);
    while(t<2*3.14){  
        glVertex2f(2*cos(t),5*sin(t));
        t+=0.2;
    }
    glEnd();
}
void DesenhaQuestao4(float r, float g, float b, float angle, float rx, float ry, float rz) {
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,+1);
    glRotatef(angle, rx, ry, rz);
    glBegin(GL_POLYGON);
    for(int i=0; i<5; i++){  
        glVertex2f(pontosQuestao3e4[i][0],pontosQuestao3e4[i][1]);
    }
    glEnd();
}
void DesenhaQuestao3(float r, float g, float b, float sx, float sy, float dx, float dy) {
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-1,+1);
    glScalef(sx,sy,0);
    glTranslatef(dx,dy,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<5; i++){  
        glVertex2f(pontosQuestao3e4[i][0],pontosQuestao3e4[i][1]);
    }
    glEnd();
}
void DesenhaQuestao1e2(float r, float g, float b, float dx, float dy){
    int i, x, y;
    glColor3f(r,g,b);
    glLoadIdentity();
    glOrtho(0,20,0,20,-1,+1);
    glTranslatef(dx,dy,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<6; i++){  
        glVertex2f(pontosQuestao1e2[i][0],pontosQuestao1e2[i][1]);
    }
    glEnd();
}

void Desenha(){
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // DesenhaQuestao1e2(1.0,0.0,0.0,0,0);
    // DesenhaQuestao1e2(0.0,1.0,0.0,6,2);
    // DesenhaQuestao3(0.0,0.0,1.0,2,2,-1,-1);
    // DesenhaQuestao4(1.0,0.0,1.0,45,0,0,1);
    // DesenhaQuestao5(1.0,1.0,0.0);
    // DesenhaQuestao6(0,0.4,0.8);
    DesenhaQuestao7A(0.75,0.8,0.3);
    DesenhaQuestao7B(1.0,0.0,0.0);
    DesenhaQuestao7C(0.0,0.0,1.0);
    
    glFlush();
}

void winReshapeFcn (GLint newWidth, GLint newHeight) {
    /* Maintain an aspect ratio of 1.0. */
    glViewport (0, 0, newHeight, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-25, 25, -25, 25);
    glClear (GL_COLOR_BUFFER_BIT);
}


int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,400);
    glutCreateWindow("Exercicio 07");
    glutDisplayFunc(Desenha);
    // glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}