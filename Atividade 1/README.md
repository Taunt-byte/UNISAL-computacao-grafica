# Atividade 1

Este projeto consiste em um programa em C que divide uma janela gráfica em três partes e realiza três tarefas diferentes em cada parte:

1. **Parte 1:** Desenho a partir de pontos sólidos de um arquivo "entrada.txt".
2. **Parte 2:** Criação de uma treliça conforme ilustração fornecida.
3. **Parte 3:** Sobreposição de elementos conforme ilustração fornecida.

## Compilação e Execução

### Compilação

Para compilar o programa, execute o seguinte comando:

```bash
gcc -o main main.c -lm
```

### Execução

Após compilar, execute o programa da seguinte maneira:

```bash
./main
```

O programa espera que o arquivo "entrada.txt" esteja presente no mesmo diretório.

## Parte 1: Desenho a partir de pontos sólidos

Para esta parte, o programa lê os pontos do arquivo "entrada.txt" e usa esses pontos para desenhar o contorno de um objeto. O último ponto é conectado ao primeiro para formar um objeto fechado.

## Parte 2: Criação de uma treliça

Para esta parte, o programa cria uma treliça semelhante à ilustração fornecida. São utilizados os atributos GL_QUAD_STRIP, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN ou GL_LINE_STRIP.

## Parte 3: Sobreposição de elementos

Para esta parte, o programa desenha os elementos sobrepostos exatamente como apresentado na figura fornecida.

## Autor

Este programa foi desenvolvido por Lucas Neves da Silva.
