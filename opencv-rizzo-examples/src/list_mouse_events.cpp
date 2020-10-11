/**
***	File: list_mouse_events.cpp
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
***
*** Methods
***
***	In vi/vim editors use tabstop=3
***	In geany editor use preferences->Editor->Ident
***		set width to 	3
***		type				tab
**/
/**
*** Open the namespaces
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

int main(void);

int main(void) {

	cout << "This values are in highgui.hpp OpenCV include" << endl;
	cout << "Event id\tEvent string" << endl;
	cout << setw(8) << hex << EVENT_MOUSEMOVE 		<< "\tMouse Move"	<< endl;
	cout << setw(8) << hex << EVENT_LBUTTONDOWN 		<< "\tLeft Down" 	<< endl;
	cout << setw(8) << hex << EVENT_RBUTTONDOWN  	<< "\tRigth Down"	<< endl;
	cout << setw(8) << hex << EVENT_MBUTTONDOWN 		<< "\tMiddle Down"<< endl;
	cout << setw(8) << hex << EVENT_LBUTTONUP 		<< "\tLeft Up" 	<< endl;
	cout << setw(8) << hex << EVENT_RBUTTONUP 		<< "\tRigth UP"	<< endl;
	cout << setw(8) << hex << EVENT_MBUTTONUP 		<< "\tMiddle UP"	<< endl;
	cout << setw(8) << hex << EVENT_LBUTTONDBLCLK 	<< "\tDouble Click Left"	<< endl;
	cout << setw(8) << hex << EVENT_RBUTTONDBLCLK 	<< "\tDouble Click Rigth"	<< endl;
	cout << setw(8) << hex << EVENT_MBUTTONDBLCLK	<< "\tDouble Click Middle"	<< endl;
	cout << setw(8) << hex << EVENT_MOUSEWHEEL		<< "\tMouse Wheel +"	<< endl;
	cout << setw(8) << hex << EVENT_MOUSEHWHEEL		<< "\tMouse Wheel -"	<< endl;
	cout << setw(8) << hex << EVENT_FLAG_LBUTTON 	<< "\tFlag Mouse Left"	<< endl;
	cout << setw(8) << hex << EVENT_FLAG_RBUTTON 	<< "\tFlag Mouse Rigth"	<< endl;
	cout << setw(8) << hex << EVENT_FLAG_MBUTTON 	<< "\tFlag Mouse Middle"<< endl;
   cout << setw(8) << hex << EVENT_FLAG_CTRLKEY 	<< "\tFlag Ctrl"	<< endl;
   cout << setw(8) << hex << EVENT_FLAG_SHIFTKEY 	<< "\tFlag Shift"	<< endl;
   cout << setw(8) << hex << EVENT_FLAG_ALTKEY 		<< "\tFlag Alt"	<< endl;

}
