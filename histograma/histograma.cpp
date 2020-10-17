#include "iostream"
#include "fstream"
#include "type_traits"
#include "cmath"
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;
 
int main(void) {
 Mat origImg = imread("a.jpeg");
 vector<Mat> splitImg; 
 int HIST_SIZE_X = 256;
 float range[] = {0,256};
 const float *histRange = {range};
 bool uniform = true, accumulate = false;

 int qtd_blue_px[HIST_SIZE_X] = {};
 int qtd_green_px[HIST_SIZE_X] = {};
 int qtd_red_px[HIST_SIZE_X] = {};

 if (origImg.empty()){
     cerr << "Deu ruim";
 };
 //separar a imagem em 3 imagens BGR
 split(origImg, splitImg);
 Mat img_blue = splitImg[0];
 Mat img_green = splitImg[1];
 Mat img_red = splitImg[2];
 
Mat blue_hist, green_hist, red_hist;

calcHist(&img_blue, 1,0,Mat(), blue_hist,1, &HIST_SIZE_X, &histRange, uniform, accumulate );
calcHist(&img_green, 1,0,Mat(), green_hist,1, &HIST_SIZE_X, &histRange, uniform, accumulate );
calcHist(&img_red, 1,0,Mat(), red_hist,1, &HIST_SIZE_X, &histRange, uniform, accumulate );

int hist_width = 512, hist_height = 512;
int bin_w = cvRound((double)hist_width / HIST_SIZE_X);

Mat histImage(hist_height, hist_width, CV_8UC3, Scalar(0, 0, 0));
normalize(blue_hist, blue_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
normalize(green_hist, green_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
normalize(red_hist, red_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

for (int i = 1; i < HIST_SIZE_X; i++)
{
  line(histImage, Point(bin_w * (i - 1), hist_height - cvRound(blue_hist.at<float>(i - 1))),
       Point(bin_w * (i), hist_height - cvRound(blue_hist.at<float>(i))),
       Scalar(255, 0, 0), 1, LINE_AA , 0);
  line(histImage, Point(bin_w * (i - 1), hist_height - cvRound(green_hist.at<float>(i - 1))),
       Point(bin_w * (i), hist_height - cvRound(green_hist.at<float>(i))),
       Scalar(0, 255, 0), 1, LINE_AA , 0);
  line(histImage, Point(bin_w * (i - 1), hist_height - cvRound(red_hist.at<float>(i - 1))),
       Point(bin_w * (i), hist_height - cvRound(red_hist.at<float>(i))),
       Scalar(0, 0, 255), 1, LINE_AA, 0);
}

for (int i = 0; i < origImg.rows; i++)
{
  for (int j = 0; j < origImg.cols; j++)
  {
    int value_blue = (int)img_blue.at<uchar>(i, j);
    int value_green = (int)img_green.at<uchar>(i, j);
    int value_red = (int)img_red.at<uchar>(i, j);

    ++qtd_blue_px[value_blue];
    ++qtd_green_px[value_green];
    ++qtd_red_px[value_red];
  }
  }

  imshow("Histograma", histImage);

  waitKey(0);

};
