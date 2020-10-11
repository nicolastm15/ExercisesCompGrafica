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

vector<vector<int>> histograma(Mat i);

vector<vector<int>> histograma(Mat i){

	vector<vector<int>> h;
	vector<int> t;

	for( c=0; c< 3 ; c++)
		t.push_back(0);

	for( int c=0; c < 256; c++)
		h.push_back(t);

	for ( int r=0; r < i.rows ; r++)
		for ( int c=0; i.cols; c++){
			Vec3b p = i.at<Vec3b>(r,c);
			h[ p[0] ][0]++;
			h[ p[1] ][1]++;
			h[ p[2] ][2]++;
		}
/*
	h [0][0]  = 59
	h [0][1]  = 5
	h [0][2]  = 200
*/
	return h;
}

int main(void) {

Mat		image;		// Image object
Mat 		imgblur, gaussian, median;
string	filename;	// Image file name

	filename = "../imagens/imagem_01.jpg";

	// Read image from disk
	image = imread(filename);

	// Check if image was loaded
	if ( image.empty() ){
		cerr << "Image [ " << filename << " ] not found!" << endl;
		cerr << "Quitting!" << endl;
		exit (-1);
	}

	blur(image, imgblur, Size(11,11));
	medianBlur(image, median, 11);

	// Create a window for display.
	namedWindow( filename.c_str(), WINDOW_NORMAL); 
	// Show our image inside it.
	imshow( filename.c_str(), image );                
	// Create a window for display.
	namedWindow( "BLUR", WINDOW_NORMAL); 
	// Show our image inside it.
	imshow( "BLUR", imgblur );                
	// Create a window for display.
	namedWindow( "Median", WINDOW_NORMAL); 
	// Show our image inside it.
	imshow( "Median", median );                

	waitKey(0);			// Wait for any key was pressed and return
							// the key code pressed or -1 if no key pressed
							// Parameter
							// =0 - Wait for until key pressed
							// >0 - Wait by N miliseconds and return
	return 0;

}
