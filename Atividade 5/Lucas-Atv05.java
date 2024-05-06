package main;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Atividade5 {

    public static void main(String[] args) {
        // Exemplo de uso do programa
        File inputImage = new File("binZadeh.png"); // Arquivo de entrada
        File outputImage = new File("binZadeh.jpg"); // Arquivo de saída
        BufferedImage image = null;
        try {
            // Lê a imagem de entrada
            image = ImageIO.read(inputImage);
        } catch (IOException e) {
            e.printStackTrace();
        }
        // Realiza operações na imagem
        subtrai(image, 50); // Exemplo de subtração de 50 de todos os pixels
        divide(image, 2); // Exemplo de divisão de todos os pixels por 2
        multiplica(image, 1.5); // Exemplo de multiplicação de todos os pixels por 1.5
        // Salva a imagem resultante
        saveImage(image, outputImage);
    }

    // Método para subtrair um valor de todos os pixels da imagem
    public static void subtrai(BufferedImage image, int valor) {
        int width = image.getWidth();
        int height = image.getHeight();
        int[] pixels = image.getRGB(0, 0, width, height, null, 0, width);

        for (int i = 0; i < pixels.length; i++) {
            int pixel = pixels[i];
            int novoPixel = pixel - valor; // Subtrai o valor do pixel
            pixels[i] = novoPixel;
        }

        // Atualiza a imagem com os novos pixels
        image.setRGB(0, 0, width, height, pixels, 0, width);
    }

    // Método para dividir todos os pixels da imagem por um valor
    public static void divide(BufferedImage image, double valor) {
        int width = image.getWidth();
        int height = image.getHeight();
        int[] pixels = image.getRGB(0, 0, width, height, null, 0, width);

        for (int i = 0; i < pixels.length; i++) {
            int pixel = pixels[i];
            double res = (double) pixel / valor;
            int novoPixel = (int) Math.min(255, Math.max(0, res)); // Garante que o valor do pixel esteja entre 0 e 255
            pixels[i] = novoPixel;
        }

        // Atualiza a imagem com os novos pixels
        image.setRGB(0, 0, width, height, pixels, 0, width);
    }

    // Método para multiplicar todos os pixels da imagem por um valor
    public static void multiplica(BufferedImage image, double valor) {
        int width = image.getWidth();
        int height = image.getHeight();
        int[] pixels = image.getRGB(0, 0, width, height, null, 0, width);

        for (int i = 0; i < pixels.length; i++) {
            int pixel = pixels[i];
            int novoPixel = (int) Math.min(255, Math.max(0, pixel * valor)); // Garante que o valor do pixel esteja entre 0 e 255
            pixels[i] = novoPixel;
        }

        // Atualiza a imagem com os novos pixels
        image.setRGB(0, 0, width, height, pixels, 0, width);
    }

    // Método para salvar a imagem resultante
    public static void saveImage(BufferedImage image, File outputImageFile) {
        try {
            ImageIO.write(image, "jpg", outputImageFile);
            System.out.println("Conversão concluída."); // Indica que a conversão foi concluída com sucesso
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
