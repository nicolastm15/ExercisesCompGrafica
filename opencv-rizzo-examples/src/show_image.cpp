/**
***
***	File: show_image.cpp
***
***   Author:     Nilton Jose Rizzo
***   Date:       08/01/2019
***   Git:        git@gitlab.com:ufrrj/opencv.git
***   LICENSE:    see LICENSE file
***
***
***   OpenCV Howto by examples
***
*** Functions from OpenCV:
***
***   imread			Read image from file
***   imshow			Show Image in window
***   namedWindow		Create window
***	resizeWindow	Resize Window
***   waitkey			Wait a key pressed or time delay
***
*** Methods:
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

/**
*** open namespaces
**/
using namespace std;
using namespace cv;

int main(void) {

Mat		image;		// Image object to be used
string	filename;	// Image name
int		h,w,height, width;

	filename = "../imagens/imagem_01.jpg";

	// Read image from disk
	image = imread(filename);

	if ( image.empty() ){
		cerr << "Image file name not found" << endl;
		exit(-1);
	}

	// Create a window for display.
	namedWindow( filename.c_str(), WINDOW_NORMAL); 

	// Resize windows and image will fit in
	width = image.cols;
	height = image.rows;
   w = 800;
   h = height * w / width;
        
	// Resize the window to width 800xh
   resizeWindow( filename.c_str(), w, h);

	// Show our image inside it.
	imshow( filename.c_str(), image );                

	waitKey(0);			// Wait for a key press
							// If the parameter differ from 0
							// wait for the given time
							// If equal 0, wait indefinitely for the pressed key
	return 0;

}
