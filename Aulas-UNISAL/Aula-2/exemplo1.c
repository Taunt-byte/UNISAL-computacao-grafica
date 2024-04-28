#include<GL/glut.h>

void Desenha(void){
    glCLear(GL_COLOR_BUFFER_BIT);

    int i;

    glColor3f(1.0,0.0,0.0);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(1.0);

    glLineStipple(1,0x0101);
    glBegin(GL_LINES);
        glVertex2f(30.0,30.0);
        glVertex2f(220.0,30.0);
    glEnd();

    glLineStipple(1,0x00FF);
    glBegin(GL_LINES);
        glVertex2f(30.0,80.0);
        glVertex2f(220.0,80.0);
    glEnd();

    glLineStipple(1,0x1C47);
    glBegin(GL_LINES);
        glVertex2f(30.0,120.0);
        glVertex2f(220.0,120.0);
    glEnd();

    glLineStipple(1,0xAAAA);
    glBegin(GL_LINES);
        glVertex2f(30.0,150.0);
        glVertex2f(220.0,150.0);
    glEnd();

    glLineStipple(1,0x0C0F);
    glBegin(GL_LINES);
        glVertex2f(30.0,180.0);
        glVertex2f(220.0,180.0);
    glEnd();

    glDisable(GL_LINE_STIPPLE);

    glFlush();
}

void Inicializador(void){
    glCLearColor(0.0,0.0,0.0,1.0);
    gluOrtho2D(0,250,0,250);
}

void main (int argc, char **argv){
    glutInit(&argc,argv);
       
}