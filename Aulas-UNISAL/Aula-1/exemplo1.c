#include <GL/glut.h>
#include <math.h>

void Desenho() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 0.0, 0.0); // Cor vermelha
    glVertex2f(300, 450); // Vértice superior
    glVertex2f(500, 450); // Vértice superior direito
    glVertex2f(400, 300); // Vértice inferior

    glVertex2f(300, 450); // Vértice superior
    glVertex2f(400, 300); // Vértice inferior
    glVertex2f(200, 450); // Vértice superior esquerdo

    glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Coração em OpenGL");

    glutDisplayFunc(Desenho);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
