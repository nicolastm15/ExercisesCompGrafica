/**
***
***	File: effect_image.cpp
***
***   Author:     Nilton Jose Rizzo
***   Date:       08/01/2019
***   Git:        git@gitlab.com:ufrrj/opencv.git
***   LICENSE:    see LICENSE file
***
***
***   OpenCV How-to by examples
***
*** Functions from OpenCV:
***
***   imread				Read image from file
***   imshow				Show Image in window
***   namedWindow			Create window
***	resizeWindow		Resize Window
***   waitkey				Wait a key pressed or time delay
***	setMouseCallback	Create a callback to mouse events
***	cvtColor				Transfor color space
***
***	Methods:
***
***	Mat::empty			Check if image was empty 
***
***   In vi/vim editors use tabstop=3
***   In geany editor use preferences->Editor->Ident
***      set width to   3
***      type           tab
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

/**
*** Function:
***
***    mouseCallBack
***
***		Function to handle mouse events
***
***	Parameters
***
***		event			: Show what the mouse is doing
***		x,y			: image position of mouse pointer
***		flags			: To show if <ALT>, <CTRL> or <SHIT> keys were pressed
***		userdata		: User data to pass to function
***
**/
void mouseCallBack(int event, int x, int y, int flags, void *userdata);

void showHelp(void);

int main(void);

int delta;			//  Global zoom multiply


void mouseCallBack(int event, int x, int y, int flags, void *userdata){
string msg;
Mat tmp = *(static_cast<Mat *>(userdata));

	switch ( event ){
		case EVENT_MOUSEMOVE:
			msg = "Mouse moving";
			break;
		case EVENT_LBUTTONDOWN:
			msg = "Left Down";
			break;
		case EVENT_LBUTTONUP:
			msg = "Left Up";
			break;
		case EVENT_RBUTTONDOWN:
			msg = "Rigth Down";
			break;
		case EVENT_RBUTTONUP:
			msg = "Rigth UP";
			break;
		case EVENT_MBUTTONDOWN:
			msg = "Middle Down";
			break;
		case EVENT_MBUTTONUP:
			msg = "Middlw UP";
			break;
		case EVENT_LBUTTONDBLCLK:
			msg = "Double click Left";
			break;
		case EVENT_RBUTTONDBLCLK:
			msg = "Double click Rigth";
			break;
		case EVENT_MBUTTONDBLCLK:
			msg = "Double click Middle";
			break;
		case EVENT_MOUSEWHEEL:
			msg = "Mouse Wheel (+)";
			break;
		case EVENT_MOUSEHWHEEL:
			msg = "Mouse Wheel (-)";
			break;
	}
	if ((event == EVENT_MOUSEWHEEL) || (event == EVENT_MOUSEHWHEEL))
		delta = getMouseWheelDelta(flags);
	
}


int main(void) {

Mat		image;		// Image object to be used
Mat		tmp;			// Temporary image
Mat		workimage;	// Imagem para ser mostrada
string	filename;	// Image name
int		h,w,height, width;
char		ch;
string	wname;		// Window name
float		zoom = 1.0;
int 		newx, newy, last_delta;

	filename = "../imagens/imagem_01.jpg";
	wname = "Working Window";

	// Read image from disk
	image = imread(filename);

	// check if image was loaded
	if (image.empty()){
		cerr << "Error: Image not found! [ " << filename << " ]" << endl;
		exit (-1);
	}

	// Create a window for display.
	namedWindow( wname.c_str()); //, WINDOW_NORMAL); 

	// Create callback to handle mouse events
	setMouseCallback(wname.c_str(), mouseCallBack, &image);

	// Resize windows and image will fit in
	width = image.cols;
	height = image.rows;
   w = 800;
   h = height * w / width;
        
	// Resize the window to width 800xh
   resizeWindow( wname.c_str(), w, h);

	// Show our image inside it.
	imshow( wname.c_str(), image );                

	workimage = image.clone();
	last_delta = 0;

	do {
		Mat imagezoom;
		ch = waitKey(1);			// Wait for a key press
										// If the parameter differ from 0
										// wait for the given time
										// If equal 0, wait indefinitely 
										//		for the pressed key
		if ( delta != 0 ) {
			zoom = zoom + (delta / 10.0); 	// zoom in/out 10%
			if ( zoom < 0.1 )
				zoom = 0.1;
			if ( zoom > 5.0 )
				zoom = 5.0;
			newx = workimage.cols * zoom;
			newy = workimage.rows * zoom;
			Size	s= Size(newx, newy);
			imagezoom = Mat::zeros(s, CV_8UC3);
			resize(workimage, imagezoom, s);
			if ( zoom > 1.0 ){
				Rect	r = Rect((int)(newx/2)-(int)(w/2), (int)(newy/2)-(int)(h/2), w, h);
				imagezoom = imagezoom(r);
			}
			imshow( wname.c_str() , imagezoom );                
			last_delta = delta;
			delta = 0;
		}
		switch  ( ch ) {
			case 'g':
			case 'G': {
				Mat  tmp;
				if ( imagezoom.empty() )
					imagezoom = workimage.clone();
				cvtColor(imagezoom, tmp, COLOR_BGR2GRAY);
				imagezoom = tmp.clone();
				workimage = tmp.clone();
				zoom -= 0.1;
				delta = 1;
				break;
				}
			case 'h':
			case 'H':
			case '?':
				showHelp();
				break;
			case 'i':
			case 'I':
				showInfo(workimage);
				break;
			case 'r':
			case 'R':
				imagezoom = image.clone();
				workimage = image.clone();
				zoom = 1.0;
				imshow( wname.c_str() , imagezoom );                
				break;
		}
	} while ( ch != 27 );		// Wait until <ESC> was pressed
	cout << endl;
	return 0;

}

void showHelp(void){

	cout << "\n\
Mouse Example Version 1.0.0\n\n\
This examples show how mouse works\n\
\tKeys\tActions\n\n\
\t<g>\tConvert image to gray scale\n\
\t<h>\tThis help screen\n\
\t<i>\tShow basic information about image\n\
\t<ESC>\tQuit\n\n";

}

