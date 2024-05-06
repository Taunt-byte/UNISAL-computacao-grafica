#include <GL/glut.h>

static int year = 0, day = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor de fundo preta
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); // Define a viewport para a janela inteira
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); // Define a perspectiva
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt (0.0, -10.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0); // Define a posi��o e orienta��o da c�mera
}

void keyboard (unsigned char key, int x, int y){
    switch (key) {
        case 'd':
            day = (day + 24) % 360; break; // Rotaciona os planetas no eixo Y no sentido hor�rio
        case 'D':
            day = (day - 24) % 360; break; // Rotaciona os planetas no eixo Y no sentido anti-hor�rio
        case 'y':
            year = (year + 365) % 360; break; // Rotaciona os planetas no eixo Y (�rbita) no sentido hor�rio
        case 'Y':
            year = (year - 365) % 360; break; // Rotaciona os planetas no eixo Y (�rbita) no sentido anti-hor�rio
        case 27: 
            exit(0); break; // Fecha a janela quando a tecla ESC � pressionada
        default: break;
    }
    glutPostRedisplay(); // Marca a janela para ser redesenhada
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa o buffer de cor e de profundidade

    // Sol
    glColor3f(1.0, 1.0, 0.0); // Cor amarela
    glPushMatrix();
        glRotatef((GLfloat) year * 0.05, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
        glutWireSphere(1.0, 20, 16); // Desenha o Sol
        glRotatef((GLfloat) day * 0.05, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)

        // *** Planetas do Sistema Solar ***
        // Merc�rio
        glColor3f(0.8, 0.8, 0.8); // Cor cinza
        glPushMatrix();
            glRotatef((GLfloat) year * 4.15, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(1.4, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day * 6.14, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(0.05, 10, 8); // Desenha Merc�rio
        glPopMatrix();

        // V�nus
        glColor3f(0.8, 0.4, 0.0); // Cor laranja
        glPushMatrix();
            glRotatef((GLfloat) year * 1.62, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(1.9, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day * 1.62, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(0.1, 10, 8); // Desenha V�nus
        glPopMatrix();

        // Terra
        glColor3f(0.0, 0.0, 1.0); // Cor azul
        glPushMatrix();
            glRotatef((GLfloat) year, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(2.6, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(0.2, 10, 8); // Desenha a Terra
        glPopMatrix();

        // Marte
        glColor3f(1.0, 0.0, 0.0); // Cor vermelha
        glPushMatrix();
            glRotatef((GLfloat) year * 1.5, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(3.5, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day * 1.03, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(0.1, 10, 8); // Desenha Marte
        glPopMatrix();

        // J�piter
        glColor3f(0.7, 0.5, 0.3); // Cor marrom
        glPushMatrix();
            glRotatef((GLfloat) year * 0.41, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(6.5, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day * 0.41, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(1.0, 10, 8); // Desenha J�piter
        glPopMatrix();

        // Saturno
        glColor3f(0.8, 0.8, 0.6);// Cor amarelo claro
        glPushMatrix();
            glRotatef((GLfloat) year * 0.32, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(10.5, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day * 0.45, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(0.8, 10, 8); // Desenha Saturno
        glPopMatrix();

        // Urano
        glColor3f(0.5, 0.5, 0.5); // Cor cinza claro
        glPushMatrix();
            glRotatef((GLfloat) year * 0.23, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(15.0, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day * 0.72, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(0.7, 10, 8); // Desenha Urano
        glPopMatrix();

        // Netuno
        glColor3f(0.2, 0.2, 0.8); // Cor azul claro
        glPushMatrix();
            glRotatef((GLfloat) year * 0.18, 0.0, 1.0, 0.0); // Rota��o no eixo Y (�rbita)
            glTranslatef(17.0, 0.0, 0.0); // Transla��o para a �rbita correta
            glRotatef((GLfloat) day * 0.67, 0.0, 1.0, 0.0); // Rota��o no eixo Y (pr�prio eixo)
            glutWireSphere(0.6, 10, 8); // Desenha Netuno
        glPopMatrix();
        
    glPopMatrix();

    glutSwapBuffers(); // Troca os buffers para exibir o desenho atualizado
}

int main(int argc, char** argv){
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Modo de exibi��o com buffer duplo, cor RGB e profundidade
    glutInitWindowSize(500, 500); // Tamanho da janela
    glutInitWindowPosition(100, 100); // Posi��o da janela na tela
    glutCreateWindow(argv[0]); // Cria a janela com o nome do programa
    init(); // Fun��o de inicializa��o
    glutDisplayFunc(display); // Fun��o de exibi��o
    glutReshapeFunc(reshape); // Fun��o de redimensionamento
    glutKeyboardFunc(keyboard); // Fun��o de teclado
    glutMainLoop(); // Loop principal do GLUT
    return 0;
}
