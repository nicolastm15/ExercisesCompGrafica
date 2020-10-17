#include "iostream"
#include "fstream"
#include "type_traits"
#include "cmath"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int y_do_ponto(Mat hist, int hist_height,  int i){
  return hist_height - cvRound(hist.at<float>(i));
}

int x_do_ponto(int largura_da_classe, int i){
  return largura_da_classe * i;
}

int main(void)
{
  //le a imagem
  Mat origImg = imread("f.jpg");

  //tamanho do eixo X do histograma
  int HIST_SIZE_X = 256;

  //criando um vetor que vai de 0 ate 255
  float range[] = {0, 256};
  const float *histRange = {range};

  //duas opcoes padroes do metodo calcHist() que nao sei exatamente pra que servem
  bool uniform = true, accumulate = false;

  //verificar se a imagem desejada realmente esta sendo lida
  if (origImg.empty())
  {
    cerr << "Deu ruim";
  };

  //separar a imagem lida em 3 imagens BGR
  vector<Mat> splitImg;
  split(origImg, splitImg);
  Mat img_blue = splitImg[0];
  Mat img_green = splitImg[1];
  Mat img_red = splitImg[2];

  //criando 3 imagens vazias para os histogramas azul, verde e vermelho.
  Mat blue_hist, green_hist, red_hist;

  //calculando cada um dos histogramas a partir da imagem original e salvando-os nas respectivas variaveis criadas acima.
  /*
  Cada histograma possui o HIST_SIZE_X, que é o comprimento do eixo x do histograma, e o histRange, que diz o intervalo de variaçao do eixo x. 
  Se histRange for maior do que HIST_SIZE_X teremos um espaço vazio no final da imagem gerada. 
  Se hsitRange for menor do que HIST_SIZE_X teremos valores fracionarios aparecendo no histograma, o que causará pontos vales zerados no gráfico.
  */
  calcHist(&img_blue, 1, 0, Mat(), blue_hist, 1, &HIST_SIZE_X, &histRange, uniform, accumulate);
  calcHist(&img_green, 1, 0, Mat(), green_hist, 1, &HIST_SIZE_X, &histRange, uniform, accumulate);
  calcHist(&img_red, 1, 0, Mat(), red_hist, 1, &HIST_SIZE_X, &histRange, uniform, accumulate);

  //determinando o tamanho das janelas do histograma
  int hist_width = 512, hist_height = 512;

  //determinando o comprimento de cada classe do histograma a partir do tamanho do histograma de fato e do tamanho da janela
  int bin_w = cvRound((double)hist_width / HIST_SIZE_X);

  //criando uma imagem preta para ser preenchida com os histogramas
  Mat histImage(hist_height, hist_width, CV_8UC3, Scalar(0, 0, 0));

  //ajustando os histogramas para se encaixar na altura da imagem criada acima
  normalize(blue_hist, blue_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
  normalize(green_hist, green_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
  normalize(red_hist, red_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

  //criando linhas na imagem histImage ligando os pontos dos histogramas gerados acima
  for (int i = 1; i < HIST_SIZE_X; i++)
  {
    /* 
    Cada linha utiliza a imagem onde será desenhada, o ponto anterior e o ponto atual do loop, a cor da linha,
    a spessura e o tipo de linha (4 vizinhos, 8 vizinhos, antialiased). O ultimo parametro nao sei o que é, 
    mas pelo que entendi parece que vai ser "sempre" 0.
    */
    /* 
    Cada ponto precisa das coordenadas x (dada pela espessura_da_classe * tom_da_cor_em_questao)
    e y (dada pela altura_da_imagem_total menos quantidade_de_pixels_daquele_tom_daquela_cor) 
    */
    int POSICAO_ANTERIOR = i-1;
    int POSICAO_ATUAL = i;
    line(histImage, Point(x_do_ponto(bin_w, POSICAO_ANTERIOR), y_do_ponto(blue_hist, hist_height, POSICAO_ANTERIOR)),
         Point(x_do_ponto(bin_w, POSICAO_ATUAL), y_do_ponto(blue_hist, hist_height, POSICAO_ATUAL)),
         Scalar(255, 0, 0), 1, LINE_AA, 0);
    line(histImage, Point(x_do_ponto(bin_w, POSICAO_ANTERIOR), y_do_ponto(green_hist, hist_height, POSICAO_ANTERIOR)),
         Point(x_do_ponto(bin_w, POSICAO_ATUAL), y_do_ponto(green_hist, hist_height, POSICAO_ATUAL)),
         Scalar(0, 255, 0), 1, LINE_AA, 0);
    line(histImage, Point(x_do_ponto(bin_w, POSICAO_ANTERIOR), y_do_ponto(red_hist, hist_height, POSICAO_ANTERIOR)),
         Point(x_do_ponto(bin_w, POSICAO_ATUAL), y_do_ponto(red_hist, hist_height, POSICAO_ATUAL)),
         Scalar(0, 0, 255), 1, LINE_AA, 0);
  }

  //mostra a imagem
  imshow("Histograma", histImage);

  waitKey(0);
};
