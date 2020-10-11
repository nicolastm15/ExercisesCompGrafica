/**
***
***	File:			work_image.cpp
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
***	cvtColor		Transform a image from the one color space to other
***
*** Methods
***
***	Mat::empty()	Return true if image is empty, else return false
***	Mat::clone()	Create a new copy from image
***
*** libimage		This lib was part from this how-to
***
***	showInfo			Show the basic information about image
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

#include "../include/image.hpp"

/**
*** open namespaces
**/
using namespace std;
using namespace cv;

int 	main(void);
void	showHelp(void);		// Show help mensage to user


int main(void) {

Mat		image;		// Image object to be used, original Image
Mat		work;			// Working image
Mat		tmp;			// temporary Image
string	filename;	// Image name
int		h,w,height, width;
char		ch;

	filename = "../imagens/imagem_01.jpg";

	// Read image from disk
	image = imread(filename);

	if ( image.empty() ){
		cerr << "Erro: Image not found [" << filename << "]" << endl;
		exit(-1);
	}

	// Create a window for display.
	namedWindow( filename.c_str(), WINDOW_NORMAL); 

	work = image.clone();
	tmp = work.clone();

	do {
		width = work.cols;
		height = work.rows;

		// Resize windows and image will fit in
   	w = 800;
   	h = height * w / width;
        	
		// Resize the window to width 800xh
   	resizeWindow( filename.c_str(), w, h);

		// Show our image inside it.
		imshow( filename.c_str(), work );                

		ch = waitKey(100);		// Wait for a key press
										// If the parameter differ from 0
										// wait for the given time
										// If equal 0, wait indefinitely 
										//		for the pressed key
		switch( ch ) {
			case 'b':	
			case 'B': 
				tmp = work > 128;
				break;
			case 'g':	// Convert image to Gray Scale
			case 'G':
				cvtColor( work, tmp, COLOR_BGR2GRAY);
				break;
			case 'h':	// Show Help
			case 'H':
			case '?':
				showHelp();
				break;
			case 'i':	// Show Image infoemations
			case 'I':
				showInfo(work);
				break;
			case 'r':	// Reset to original image
			case 'R':
				tmp = image.clone();
				break;
		}
		work = tmp.clone();
	} while ( ch != 27 );		// Wait until <ESC> was pressed
	cout << endl;
	return 0;
}


void showHelp(void){

	cout << " \n\
Working Image version 1.0.0 \n\
\n\
This program describe how we can work with images, transform, change format and much more.\n\
\n\
Commands:\n\
\n\
\t<b>\tModify all values bellow thresould to zero\n\
\t<g>\tTransform image to gray scale\n\
\t<h>\tThis help page\n\
\t<i>\tShow Image informations\n\
\t<ESC>\tQuit program\n\
" << endl;
}

