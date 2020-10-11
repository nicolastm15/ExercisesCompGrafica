/**
***
***	File: gray_image.cpp
***
***	Author:		Nilton Jose Rizzo
***	Date:			08/01/2019
***	Git:			git@gitlab.com:ufrrj/opencv.git
***	LICENSE:		see LICENSE file
***
***
***	OpenCV How-to by examples
***
*** Functions from OpenCV:
***
***   imread		Read image from file
***	namedWindow	Create a new window do show a image
***   imshow		Show Image on Window
***   waitkey		Wait a key pressed 
***	cvtColor		Tranform image from one color space to another
***
*** Methods
***
***	Mat::empty()	Return true if image is empty, else return false
***
***	In vi/vim editors use tabstop=3
***	In geany editor use preferences->Editor->Ident
***		set width to 	3
***		type				tab
**/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

/**
*** open namespaces
**/
using namespace std;
using namespace cv;

int 	main(void);


int main(void) {

Mat		image;		// Image object to be used, original Image
Mat		tmp;			// Temporary image
string	filename;	// Image name
int		h,w,height, width;


	cout << "Transform color image to gray scale image" << endl;

	filename = "../imagens/imagem_01.jpg";

	// Read image from disk
	image = imread(filename);

	if ( image.empty() ){
		cerr << "Erro: Image not found [" << filename << "]" << endl;
		exit(-1);
	}

	// Resize windows and image will fit in
	width = image.cols;
	height = image.rows;
  	w = 800;
  	h = height * w / width;
        	
	// Create a window for display.
	namedWindow( filename.c_str(), WINDOW_NORMAL); 

	// Resize the window to width 800xh
  	resizeWindow( filename.c_str(), w, h);

	// Show our image inside it.
	imshow( filename.c_str(), image );                

	cout << ">>> Press any key to continue" << endl;
	waitKey(0);

	// Convert color image to gray image
	cvtColor(image, tmp, COLOR_BGR2GRAY);

	imshow ( filename.c_str(), tmp );

	cout << ">>> Press any key to continue" << endl;
	waitKey(0);

	return 0;

}
