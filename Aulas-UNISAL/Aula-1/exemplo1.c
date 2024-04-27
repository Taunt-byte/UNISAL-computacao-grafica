#include <GL/glut.h> // Inclui o cabeçalho da GLUT para uso das funções OpenGL
#include <math.h> // Inclui o cabeçalho para operações matemáticas

void Desenho() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor para a cor de fundo especificada

    glBegin(GL_TRIANGLES); // Inicia a definição de triângulos
    glColor3f(1.0, 0.0, 0.0); // Define a cor atual para vermelho (RGB: 1.0, 0.0, 0.0)

    // Desenha o primeiro triângulo do coração
    glVertex2f(300, 450); // Vértice superior
    glVertex2f(500, 450); // Vértice superior direito
    glVertex2f(400, 300); // Vértice inferior

    // Desenha o segundo triângulo do coração
    glVertex2f(300, 450); // Vértice superior
    glVertex2f(400, 300); // Vértice inferior
    glVertex2f(200, 450); // Vértice superior esquerdo

    glEnd(); // Finaliza a definição de triângulos

    glutSwapBuffers(); // Troca os buffers para atualizar a tela
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height); // Define a viewport da janela
    glMatrixMode(GL_PROJECTION); // Define o modo de matriz como projeção
    glLoadIdentity(); // Carrega a matriz de identidade
    gluOrtho2D(0, width, 0, height); // Define a projeção ortográfica 2D
    glMatrixMode(GL_MODELVIEW); // Define o modo de matriz como modelview
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa a GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Configura o modo de exibição para duplo buffer e RGBA
    glutCreateWindow("Coração em OpenGL"); // Cria uma janela com o título especificado

    glutDisplayFunc(Desenho); // Define a função de desenho a ser chamada quando a janela precisa ser redesenhada
    glutReshapeFunc(reshape); // Define a função de redimensionamento da janela

    glutMainLoop(); // Inicia o loop principal da GLUT

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
