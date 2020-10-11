/**
***
***	File:	info_image.cpp
***   Author:     Nilton Jose Rizzo
***   Date:       08/01/2019
***   Git:        git@gitlab.com:ufrrj/opencv.git
***   LICENSE:    see LICENSE file
***
***
***   OpenCV Hoe-to by examples
***
*** Functions from OpenCV:
***
***   imread			Read image from file
***
*** Methods
***
***	Mat::empty()	Return true if image is empty, else return false
***
***   In vi/vim editors use tabstop=3
***   In geany editor use preferences->Editor->Ident
***      set width to   3
***      type           tab
**/

#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "../include/image.hpp"

/**
*** open namespaces
**/
using namespace std;
using namespace cv;

int main(void);

int main(void) {

Mat		image;		// Image object to be used
string	filename;	// Image name
int		h,w,height, width;

	filename = "../imagens/imagem_01.jpg";

	// Read image from disk
	image = imread(filename);

	// Check if image was loaded
	if ( image.empty() ){
		cerr << "Error: Image not found [" << filename << "]" << endl;
		exit (-1);
	}


	// Note: this space are space char not tab
	cout << "Image info:" << endl;
	cout << ">>> Name: ..... " << filename << endl;
	cout << ">>> Type: ..... " << type2Str(image) << endl;
	cout << ">>> Size: ..... " << image.rows << " x " << image.cols << endl;
	cout << ">>> Channels: . " << image.channels() << endl;
	cout << ">>> Depth: .... " << image.depth() << endl;

	return 0;

}
