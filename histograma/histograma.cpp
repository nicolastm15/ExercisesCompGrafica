#include "iostream"
#include "fstream"
#include "type_traits"
#include "cmath"
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;
 
vector<vector<int>> histograma(Mat i);
 
int main(void) {
 Mat img = imread("a.jpeg");
 if (img.empty()){
     cerr << "Deu ruim";
 };
//  namedWindow("First Image", WINDOW_AUTOSIZE);
imshow ("First Image", img);
waitKey(0);
 
 
};
