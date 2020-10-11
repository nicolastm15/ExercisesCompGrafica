/**
***
***	File: image_lib.cpp
***
***   Author:     Nilton Jose Rizzo
***   Date:       08/01/2019
***   Git:        git@gitlab.com:ufrrj/opencv.git
***   LICENSE:    see LICENSE file
***
***
***   OpenCV How-to by examples
***
*** User Functions:
***
***	Function
***
***		type2Str
***
***		Convert to string th numeric type of image
***
***		Parameter
***
***			image		The image to reconise type
***
***		Return value
***
***			string with image type, like CV_(BITS)(TYPE)[C(CHANNELS)]
***
***		BITS: 8, 16, 32, 64
***		TYPE: (U)nsigned, (S)igned, (F)loat, 
***		CHANNELS: 1, 3, 4, 5, 6, and others
***			the channels can be ommited if the value was equal to 1
***
***		showInfo
***
***			Show image infomations
***
***			Parameters
***
***				image		The image object
***
***			Return value
***
***				Nothing
***
***		getDepth
***
***			get image depth, in bits
***
***		Parameter
***
***			Image		The Mat object (image)
***
***		Return
***
***			Value of bits ( 8, 16, 32, 64 or 0 to unknow)
***
***   In vi/vim editors use tabstop=3
***   In geany editor use preferences->Editor->Ident
***      set width to   3
***      type           tab
**/

#include "../include/image.hpp"

void showInfo(Mat image){

   cout << "Image Info:" << endl;
   cout << ">>> Image Type:......" << type2Str(image) << endl;
   cout << ">>> Image size:......" << image.rows << " x " << image.cols << endl;
	cout << ">>> Image Depth:....." << getDepth(image) << " Bits" << endl;
   cout << ">>> Image Channels:.." << image.channels() << endl;
}

unsigned int getDepth(Mat image){
unsigned int d, r;

   d = image.depth();
   switch(d){
      case 0:
      case 1:
         r = 8;
         break;
      case 2:
      case 3:
         r = 16;
         break;
      case 4:
      case 5:
         r = 32;
         break;
      case 6:
         r = 64;
         break;
		default:
			r = 0;
			break;
   }
   return r;
}
string type2Str(Mat image){
string type;

   switch (image.type()){
      case CV_8U:
         type = "CV_8U";
         break; 
      case CV_8UC3:
         type = "CV_8UC3";
         break; 
      case CV_8S:
         type = "CV_8S";
         break; 
      case CV_16U:
         type = "CV_16U";
         break; 
      case CV_16S:
         type = "CV_16S";
         break; 
      case CV_32S:
         type = "CV_32S";
         break; 
      case CV_32F:
         type = "CV_32F";
         break; 
      case CV_64FC1:
         type = "CV_64FC1";
         break; 
      case CV_64FC3:
         type = "CV_64FC3";
         break; 
      default:
         type = "UNKNOW";
   }
   return type;
}
