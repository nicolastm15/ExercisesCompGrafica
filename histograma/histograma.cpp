#include "iostream"
#include "fstream"
#include "type_traits"
#include "cmath"
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;
 
 
int main(void) {
 Mat img = imread("a.jpeg");
 if (img.empty()){
     cerr << "Deu ruim";
 };
 cout << img.cols;
//  namedWindow("First Image", WINDOW_AUTOSIZE);
for (int i; i<img.rows; i++){
    for (int j; img.cols; i++){
        vector<int> value_blue = img[i][j][0];
        vector<int> value_green = img[i][j][1];
        vector<int> value_red = img[i][j][2];
    }
}
};
