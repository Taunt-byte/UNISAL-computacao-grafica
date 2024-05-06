#include <GL/glut.h>

void Inicializa ();
void Cubo1 ();
void Cubo2 ();
void teclado(unsigned char tecla, int x, int y);
void reshape (int w, int h);

static GLfloat vertices [30] = {
0.0, 30.0, 30.0,  //0
30.0, 30.0, 30.0, //1
30.0, 30.0, 30.0, //2
30.0, 0.0, 30.0, //3
0.0, 0.0, 30.0, //4
0.0, 30.0, 0.0, //5
30.0, 30.0, 0.0, //6
30.0, 0.0, 0.0, //7
0.0, 0.0, 0.0, //8
30.0, 30.0, 30.0 //9
};
//definição das faces
static GLubyte frente[] = {0, 4, 3, 2, 1};
static GLubyte tras[] = {5, 6, 7, 8};
static GLubyte esquerda[] = {0, 5, 8, 4};
static GLubyte direita[] = {2, 3, 7, 6, 9};
static GLubyte topo[] = {0, 1, 9, 6, 5};
static GLubyte fundo[] = {3, 4, 8, 7};

static int eixox, eixoy;
int largura, altura;

void main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(256,256);
	glutInitWindowPosition(10,10);
	glutCreateWindow("LUCAS NEVES");
	
	Inicializa();
	
	glutDisplayFunc(Cubo1);
	glutDisplayFunc(Cubo2);
	glutKeyboardFunc(teclado);
	glutReshapeFunc(reshape);
	
	glutMainLoop();

}


void Inicializa(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-50, 50, -50, 50, -50, 50);
	
	glEnable(GL_DEPTH_TEST); // CALCULAR OS PONTOS (PROFUNDIDADE)
	
	glEnable(GL_CULL_FACE); // REMOVE A FACE TRASEIRA
	
}


void Cubo1(){
	glPushMatrix();
	
	//rotações
	glRotatef((GLfloat)eixoy, 0.0, 1.0 , 0.0);
	glRotatef((GLfloat)eixox, 1.0, 0.0 , 0.0);
	
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// desenhar usando os vertices 
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	// 3 Numero de elementos para formar vertice
	// GL_FLOAT tipo do dado no vetor
	// 0 Stride, deslocamento inicial
	// Vertices nome do vetor que armazena os pontos 
	
	
	glColor3f(1.0, 0.0, 0.0);
	glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, frente);
	//GL_POLYGON primitiva a ser desenhada
	// 5 Numero de vertices
	// GL_UNSIGNED_BYTE tipo de dado
	// Frente vetor de indices 	
	glColor3f(1.0, 1.0, 0.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerda);
	glColor3f(1.0, 1.0, 0.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, tras);
	glColor3f(1.0, 1.0, 0.0);
	glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, direita);
	glColor3f(1.0, 1.0, 0.0);
	glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, topo);
	glColor3f(1.0, 1.0, 0.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, fundo);
	glColor3f(1.0, 1.0, 0.0);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
	
	glFlush();
}
void Cubo2(){
		glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	
	glutWireCube(1.0);
	glFlush();

}

void teclado (unsigned char tecla, int x, int y){
	switch(tecla){
		case 27:
			exit(0);
			break;
		case 'd':
			eixoy = (eixoy + 5) % 360;
			glutPostRedisplay();
			break;	
			
		case 'a':
			eixoy = (eixoy - 5) % 360;
			glutPostRedisplay();
			break;		
		
		case 'w':
			eixox = (eixox + 5) % 360;
			glutPostRedisplay();
			break;	
			
		case 's':
			eixox = (eixox - 5) % 360;
			glutPostRedisplay();
			break;
			
		case 'p':
		glLoadIdentity();
		gluPerspective(65.0,(GLfloat) largura/(GLfloat) altura, 20.0, 120.0);
		gluLookAt(0, 0, -90, 0, 0, 0, 0, 1, 0 );
		glutPostRedisplay();
		break;
		
		case 'o':
		glLoadIdentity();
		glOrtho(-50, 50, -50, 50, -50, 50);
		glutPostRedisplay;
		break;	
	}
}

void reshape (int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	largura = w;
	altura = h;
	
}
