#ifndef __IMAGE_LIB_HPP__
#define __IMAGE_LIB_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void showInfo(Mat image);
string type2Str(Mat image);
unsigned int getDepth(Mat image);


#endif
