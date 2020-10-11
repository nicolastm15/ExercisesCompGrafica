/**
***	File: waitkey.cpp
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
***	imread			Read image from file
***	namedWindow		Create a window
***	imshow			Show image on window
***   waitkey			Wait a key pressed or time delay
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

int main(void) {
Mat      image;      // Image object
string   filename;   // Image file name
char		ch;


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
   namedWindow( filename.c_str(), WINDOW_NORMAL);
   // Show our image inside it.
   imshow( filename.c_str(), image );

	do {
		string msg;
		string space = " ";
		ch = waitKey(5000);		// Wait for a key press
										// If the parameter differ from 0
										// wait for the given time
										// If equal 0, wait indefinitely 
										//		for the pressed key
		if ( ch >= 0 )
			msg = "Key [ " ;
		else
			msg = "No key was pressed by 5s [ " ;
		cout 	<< msg << setw(3) << (int)(ch) << " ]" 
				<< setw(22) << space << "\r" << flush;
	} while ( ch != 27 );		// Wait until <ESC> was pressed
	cout << endl;
	return 0;

}
