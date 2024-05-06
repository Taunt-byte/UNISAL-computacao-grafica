# Atividade 2

Este é um programa em C que utiliza a biblioteca OpenGL para desenhar um triângulo colorido na janela gráfica.

## Compilação e Execução

### Compilação

Certifique-se de ter o OpenGL instalado em seu sistema. Em sistemas baseados em Unix/Linux, você pode instalar os pacotes de desenvolvimento OpenGL utilizando o gerenciador de pacotes padrão.

Para compilar o programa, utilize o seguinte comando:

```bash
gcc -o main main.c -lGL -lGLU -lglut -lm
```

### Execução

Após compilar, execute o programa da seguinte maneira:

```bash
./main
```

## Funcionalidades

O programa desenha um triângulo colorido na tela utilizando a biblioteca OpenGL. As cores do triângulo são definidas pelas funções `glColor3f`, que especificam a cor vermelha (R), verde (G) e azul (B), respectivamente, para cada vértice do triângulo.

## Autor

Este programa foi desenvolvido por Lucas Neves da Silva.
