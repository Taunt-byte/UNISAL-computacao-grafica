#include <GL/glut.h> // Inclui o cabeçalho da GLUT para uso das funções OpenGL
#include <stdlib.h> // Inclui o cabeçalho para funcionalidades padrão, como a função exit()
#include <math.h> // Inclui o cabeçalho para operações matemáticas

void Desenha(void){ // Função responsável por desenhar a cena
	glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor para a cor de fundo especificada
	glBegin(GL_TRIANGLES); // Inicia a definição de um triângulo
		glColor3f(0.0, 0.0, 1.0); // Define a cor atual para azul (RGB: 0.0, 0.0, 1.0)
		glVertex3f(0.0f, 0.5f, 0.0f); // Define o primeiro vértice do triângulo
		glColor3f(0.0, 1.0, 0.0); // Define a cor atual para verde (RGB: 0.0, 1.0, 0.0)
		glVertex3f(-0.5f, -0.5f, 0.0f); // Define o segundo vértice do triângulo
		glColor3f(1.0, 0.0, 0.0); // Define a cor atual para vermelho (RGB: 1.0, 0.0, 0.0)
		glVertex3f(0.5f, -0.5f, 0.0f); // Define o terceiro vértice do triângulo
	glEnd(); // Finaliza a definição do triângulo
	glFlush(); // Força a execução de todos os comandos OpenGL pendentes
}

void Inicializa(void){ // Função responsável por inicializar o ambiente OpenGL
	glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo como preto
}

int main(int argc, char **argv){ // Função principal do programa
	glutInit(&argc, argv); // Inicializa a GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura o modo de exibição para buffer único e RGB
	glutInitWindowSize(250, 250); // Define o tamanho da janela
	glutInitWindowPosition(100, 100); // Define a posição inicial da janela na tela
	glutCreateWindow("Atividade 2 - Lucas Neves da Silva"); // Cria a janela com o título especificado
	glutDisplayFunc(Desenha); // Define a função de desenho a ser chamada quando a janela precisa ser redesenhada
	Inicializa(); // Chama a função de inicialização do ambiente OpenGL
	glutMainLoop(); // Inicia o loop principal da GLUT
	return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
