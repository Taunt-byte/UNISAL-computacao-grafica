package pdi;

import java.io.File;
import java.io.IOException;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import java.util.Random;
import javax.imageio.ImageIO;

public class Aula5 {
    public static void main(String[] args) throws IOException {
        // Definindo as dimensões da imagem
        int width = 256;
        int height = 256;

        // Criando uma nova imagem em escala de cinza com as dimensões especificadas
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_BYTE_GRAY);
        
        // Obtendo o raster da imagem para manipulação direta dos pixels
        WritableRaster raster = image.getRaster();

        // Criando um objeto Random para gerar valores aleatórios de cinza
        Random randColor = new Random();

        // Iterando sobre todos os pixels da imagem
        for(int h = 0; h < height; h++) {
            for(int w = 0; w < width; w++) {
                // Gerando um valor aleatório de cinza entre 0 e 255
                int grayValue = randColor.nextInt(256);
                
                // Criando um array com o valor de cinza para cada canal (apenas um canal, pois é uma imagem em escala de cinza)
                int[] cor = new int[]{grayValue};
                
                // Definindo o valor de cinza para o pixel atual
                raster.setPixel(w, h, cor);
            }
        }

        // Definindo o arquivo de saída
        File output = new File("tabuleiro.png");
        
        // Escrevendo a imagem em formato PNG no arquivo de saída
        ImageIO.write(image, "PNG", output);
    }
}

