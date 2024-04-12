#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

void Desenha(void){

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 1.0); //(R=1.0, G=0.0, B=0.0)
		glVertex3f(0.0f, 0.5f, 0.0f);
		glColor3f(0.0, 1.0, 0.0); //(R=1.0, G=0.0, B=0.0)
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glColor3f(1.0, 0.0, 0.0); //(R=0.0, G=0.0, B=0.0)
		glVertex3f(0.5f, -0.5f, 0.0f);
	glEnd();
	glFlush();
}

void Inicializa(void){
	glClearColor(0.0,0.0,0.0,1.0);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250,250);
	glutInitWindowPosition(100,100);
	
	glutCreateWindow("Atividade 2 - Lucas Neves da Silva");
	glutDisplayFunc(Desenha);
	
	Inicializa();
	
	glutMainLoop();
}