/**
***	File: avg.cpp
***
***   Author:     Nilton Jose Rizzo
***   Date:       08/01/2019
***   Git:        git@gitlab.com:ufrrj/opencv.git
***   LICENSE:    see LICENSE file
***
***   OpenCV How-to by examples
***
**/

#include <iostream>
#include <fstream>
#include <string>
#include <type_traits>
#include <cmath>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "../include/image.hpp"

using namespace std;
using namespace cv;

int main(void);

template <class T>

Vec3d getAverage(Mat image){
int      h,w;
Vec3d    sum,pixel;

   h = image.rows;
   w = image.cols;

  	sum[0] = sum[1] = sum[2] = 0.0;
  
	if ( is_same<T, uchar>::value ){
 		for (int r = 0; r < h; r++)
  			for ( int c = 0; c < w; c++)
   			sum[0] += image.at<uchar>(r,c);
	} else {
		if (( is_same<T, Vec3b>::value ) || ( is_same<T, Vec3d>::value )){
 			for (int r = 0; r < h; r++)
  				for ( int c = 0; c < w; c++){
   				pixel = image.at<T>(r,c);
					sum[0] += pixel[0];
					sum[1] += pixel[1];
					sum[2] += pixel[2];
				}
		}
	}
 	sum[0] = sum[0] / ( h * w);
	if ( !is_same<T, uchar>::value ){
 		sum[1] = sum[1] / ( h * w);
 		sum[2] = sum[2] / ( h * w);
	}

   return sum;

}

template <class T>

Vec3d getStdDeviation(Mat image){
int      h,w;
Vec3d		sum, mean, pixel, ret;

   h = image.rows;
   w = image.cols;

  	sum[0] = sum[1] = sum[2] = 0.0;
  
 	mean = getAverage<T>(image);
	if ( is_same<T, Vec3b>::value ){
 		for (int r = 0; r < h; r++)
  			for ( int c = 0; c < w; c++){
   			pixel = image.at<Vec3b>(r,c);
   			ret = (pixel - mean );
   			sum[0] = sum[0]+ (ret[0] * ret[0]);
   			sum[1] = sum[1] + (ret[1] * ret[1]);
   			sum[2] = sum[2] + (ret[2] * ret[2]);
			}
 			ret = sum / (( h * w) * 1.0);  
			ret[0] = sqrt(ret[0]);
			ret[1] = sqrt(ret[1]);
			ret[2] = sqrt(ret[2]);
	} else {
		if ( is_same<T, Vec3d>::value ){
 			for (int r = 0; r < h; r++)
  				for ( int c = 0; c < w; c++){
   				pixel = image.at<Vec3d>(r,c);
   				ret = (pixel - mean );
   				sum[0] = sum[0] + (ret[0] * ret[0]);
   				sum[1] = sum[1] + (ret[1] * ret[1]);
   				sum[2] = sum[2] + (ret[2] * ret[2]);
				}
 				ret = sum / (( h * w) * 1.0);  
				ret[0] = sqrt(ret[0]);
				ret[1] = sqrt(ret[1]);
				ret[2] = sqrt(ret[2]);
		} else {
 			for (int r = 0; r < h; r++)
  				for ( int c = 0; c < w; c++){
   				pixel[0] = image.at<uchar>(r,c);
   				ret[0] = (pixel[0] - mean[0] );
   				sum[0] = sum[0] + (ret[0] * ret[0]);
				}
 				ret[0] = sum[0] / (( h * w) * 1.0);  
				ret[0] = sqrt(ret[0]);
		}
	}
   return ret;

}


int main(void) {

Mat		image;		// Image object
Mat 		cimage;
string	filename;	// Image file name

	//filename = "../imagens/imagem_01.jpg";
	filename = "../imagens/teste.png";

	// Read image from disk
	image = imread(filename);

	// Check if image was loaded
	if ( image.empty() ){
		cerr << "Image [ " << filename << " ] not found!" << endl;
		cerr << "Quitting!" << endl;
		exit (-1);
	}
	
	cout << "1> Media = " << getAverage<Vec3b>(image) << endl;
	cout << "1> Media = " << getAverage<uchar>(image) << endl;

	cout << "2> Media = " << getAverage<Vec3b>(image) << endl;
	cout << "2> Media = " << getAverage<uchar>(image) << endl;

	cout << "Desvio padrao = " << getStdDeviation<Vec3b>(image) << endl;
	cout << "Desvio padrao = " << getStdDeviation<uchar>(image) << endl;

   cvtColor(image, cimage, COLOR_BGR2GRAY);
	cimage.convertTo(cimage, CV_8UC1);

	cout << "Media = " << getAverage<uchar>(cimage) << endl;
	cout << "Media = " << getAverage<uchar>(cimage) << endl;

	cout << "2> Media = " << getAverage<Vec3b>(cimage) << endl;
	cout << "2> Media = " << getAverage<uchar>(cimage) << endl;

	cout << "Desvio Padrao = " << getStdDeviation<uchar>(cimage) << endl;
	cout << "Desvio Padrao = " << getStdDeviation<uchar>(cimage) << endl;

	// Create a window for display.
	namedWindow( filename.c_str(), WINDOW_NORMAL); 
	// Show our image inside it.
	imshow( filename.c_str(), image );                

	waitKey(0);			// Wait for any key was pressed and return
							// the key code pressed or -1 if no key pressed
							// Parameter
							// =0 - Wait for until key pressed
							// >0 - Wait by N miliseconds and return
	return 0;

}
