#include <GL/glut.h> // Inclui o cabeçalho da GLUT para uso das funções OpenGL

void Desenha(void){ // Função responsável por desenhar a cena
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor para a cor de fundo especificada

    int i; // Declara uma variável i que não é utilizada

    glColor3f(1.0, 0.0, 0.0); // Define a cor atual para vermelho (RGB: 1.0, 0.0, 0.0)
    glEnable(GL_LINE_SMOOTH); // Ativa o suavização de linhas para desenho de linhas suaves
    glEnable(GL_LINE_STIPPLE); // Ativa o uso de padrões de traçado de linha
    glLineWidth(1.0); // Define a largura da linha como 1.0

    glLineStipple(1, 0x0101); // Define o padrão de traçado da linha para 0x0101 (linhas sólidas)
    glBegin(GL_LINES); // Inicia a definição de uma série de linhas
        glVertex2f(30.0, 30.0); // Define o primeiro ponto da linha
        glVertex2f(220.0, 30.0); // Define o segundo ponto da linha
    glEnd(); // Finaliza a definição das linhas

    // Os próximos blocos repetem o processo para desenhar várias linhas com diferentes padrões de traçado

    glDisable(GL_LINE_STIPPLE); // Desativa o uso de padrões de traçado de linha

    glFlush(); // Força a execução de todos os comandos OpenGL pendentes
}

void Inicializador(void){ // Função responsável por inicializar o ambiente OpenGL
    glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo como preto
    gluOrtho2D(0, 250, 0, 250); // Define a projeção ortográfica para coordenadas 2D
}

int main(int argc, char **argv){ // Função principal do programa
    glutInit(&argc, argv); // Inicializa a GLUT

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura o modo de exibição para buffer único e RGB
    glutInitWindowSize(500, 500); // Define o tamanho da janela
    glutCreateWindow("Desenhando Linhas"); // Cria a janela com o título especificado

    glutDisplayFunc(Desenha); // Define a função de desenho a ser chamada quando a janela precisa ser redesenhada

    Inicializador(); // Chama a função de inicialização do ambiente OpenGL

    glutMainLoop(); // Inicia o loop principal da GLUT

    return 0;
}
