/**
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
***	cvtColor		Transform image from one color space to another
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

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

/**
*** Open the namespaces
**/
using namespace std;
using namespace cv;

int main(void) {

Mat		image;		// Image object
Mat		gray;			// Destination image in GRAY color space
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

	// Create a window for display.
	namedWindow( "Original Image", WINDOW_NORMAL); 

	// Show our image ins , image );                
	imshow( "Original Image", image );                

	cvtColor(image, gray, COLOR_BGR2GRAY);

	// Create a window for display.
	namedWindow( "GRAY Image", WINDOW_NORMAL); 

	// Show our image ins , image );                
	imshow( "GRAY Image", gray );                

	waitKey(0);			// Wait for any key was pressed and return
							// the key code pressed or -1 if no key pressed
							// Parameter
							// =0 - Wait for until key pressed
							// >0 - Wait by N miliseconds and return
	return 0;

}
