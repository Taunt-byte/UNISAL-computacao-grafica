package pdi;

import java.io.File;

public class histoGrab extends Frame{
    int w, h , hist[] = new int[256], max_hist=0;
    Image img;
    
    public static void main(String args[]) {
    // Nome da imagem a ser processada
    String nomeImg = "mini_einstein.jpg";

    // Recupera tempo de processamento
    long startTime = System.currentTimeMillis();

    // Chama o construtor passando o nome do arquivo da imagem
    HistoGrab frame = new HistoGrab(nomeImg);

    // Torna o frame visível
    frame.setVisible(true);

    // Recupera tempo de processamento
    long endTime = System.currentTimeMillis() - startTime;

    // Imprime o tempo de execução
    System.out.println("Tempo de execução: " + endTime + " milissegundos.");
}
}

