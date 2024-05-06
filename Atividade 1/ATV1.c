#include <stdio.h>

#define MAX_POINTS 100

// Estrutura para armazenar um ponto (x, y)
typedef struct {
    float x;
    float y;
} Point;

int main() {
    // Abrir o arquivo "entrada.txt" para leitura
    FILE *file = fopen("entrada.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Array para armazenar os pontos lidos do arquivo
    Point points[MAX_POINTS];
    int numPoints = 0;

    // Ler os pontos do arquivo
    while (fscanf(file, "%f %f", &points[numPoints].x, &points[numPoints].y) == 2) {
        numPoints++;
        if (numPoints >= MAX_POINTS) {
            printf("Limite máximo de pontos atingido.\n");
            break;
        }
    }

    // Fechar o arquivo
    fclose(file);

    // Conectar o último ponto ao primeiro
    if (numPoints > 0) {
        points[numPoints] = points[0];
        numPoints++;
    }

    // Agora você tem os pontos armazenados em points[].
    // Você pode usar esses pontos para desenhar o contorno do objeto.

    return 0;
}
