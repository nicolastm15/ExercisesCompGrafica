/**
***
***	File: mouse.cpp
***
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
***   imread				Read image from file
***   imshow				Show Image in window
***   namedWindow			Create window
***	resizeWindow		Resize Window
***   waitkey				Wait a key pressed or time delay
***	setMouseCallback	Create a callback to mouse events
***
*** Methods:
***
***	Mat::empty()	Return true if image is empty, else return false
***	Mat::clone()	Create a new copy of image
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

void mouseCallBack(int event, int x, int y, int flags, void *userdata){
string msg;
int delta;
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
	Vec3b v = tmp.at<Vec3b>(y,x);
	cout << msg << ">> [" << 
			setw(3) << hex << event << "][" <<
			setw(3) << hex << flags << "]"<< 
			setw(3) << dec << delta <<
			setw(2) << "(" << setw(4) << x << "," << setw(4) << y << ")" <<
			" RGB(" 
					<< setw(3) << (int)(v[2]) << ", " 
					<< setw(3) << (int)(v[1]) << ", " 
					<< setw(3) << (int)(v[0]) << " )" 
			<< setw(11) << '\r' << flush;	
}


int main(void) {

Mat		image;		// Image object to be used
Mat		tmp;			// Temporary image
string	filename;	// Image name
int		h,w,height, width;
char		ch;
string	wname;		// Window name

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
	namedWindow( wname.c_str(), WINDOW_NORMAL); 

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

	tmp = image.clone();			// Create a new copy of image

	do {
		ch = waitKey(1);			// Wait for a key press
										// If the parameter differ from 0
										// wait for the given time
										// If equal 0, wait indefinitely 
										//		for the pressed key
		switch( ch ) {
			case 'b':
			case 'B': {
				tmp = tmp > 128;
				break;
			}
			case 'r':
			case 'R':
				tmp = image.clone();
				break;
			case 'h':
			case 'H':
			case '?':
				showHelp();
				break;
		}
		imshow( wname.c_str() , tmp );                
	} while ( ch != 27 );		// Wait until <ESC> was pressed
	cout << endl;
	return 0;

}

void showHelp(void){

	cout << "\n\
Mouse Example Version 1.0.0\n\n\
This examples show how mouse works\n\
\tKeys\tActions\n\n\
\t<b>\tTransform image to binary\n\
\t<h>\tThis help screen\n\
\t<r>\tReset to original image\n\
\t<ESC>\tQuit\n\n";

}
