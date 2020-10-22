#include <iostream>
#include <fstream>
#include <string>

#include <Eigen/Dense>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#ifdef __OPENCV_VERSION_3_0
#define TOHSV CV_BGR2HSV
#else
#define TOHSV COLOR_BGR2HSV
#endif

using namespace std;
using namespace Eigen;
using namespace cv;

int main(void);

int main(void)
{

	Matrix3d T1, T2, S;
	Matrix3d R;
	Vector3d p1, p2, p3, p4, pc;
	Vector3d d1, d2, d3, d4;

	double angulo;

	Mat out;

	out = Mat::zeros(512, 512, CV_8UC3);

	rectangle(out, Point(200, 200), Point(300, 300), Scalar(255, 255, 255), 1);

	namedWindow("canvas", WINDOW_NORMAL);
	// Show our image ins , image );
	imshow("canvas", out);

	p1 << 200, 200, 1;
	p2 << 200, 300, 1;
	p3 << 300, 200, 1;
	p4 << 300, 300, 1;

	angulo = 30 * 3.1415 / 180;

	R << cos(angulo), sin(angulo), 0, 
		-sin(angulo), cos(angulo), 0, 
		0, 0, 1;

	d1 = p1.transpose() * R;
	d2 = p2.transpose() * R;
	d3 = p3.transpose() * R;
	d4 = p4.transpose() * R;

	cout << "P1" << endl
		 << d1 << endl;
	cout << "P2" << endl
		 << d2 << endl;
	cout << "P3" << endl
		 << d3 << endl;
	cout << "P4" << endl
		 << d4 << endl;

	line(out, Point(d1[0], d1[1]), Point(d2[0], d2[1]), Scalar(0, 0, 255), 1);
	line(out, Point(d1[0], d1[1]), Point(d3[0], d3[1]), Scalar(0, 0, 255), 1);
	line(out, Point(d2[0], d2[1]), Point(d4[0], d4[1]), Scalar(0, 0, 255), 1);
	line(out, Point(d3[0], d3[1]), Point(d4[0], d4[1]), Scalar(0, 0, 255), 1);

	pc = (p1 + p4) / 2;
	cout << "PC" << endl
		 << pc << endl;

	T1 << 1, 0, 0,
		0, 1, 0,
		-pc[0], -pc[1], 1;

	T2 << 1, 0, 0,
		0, 1, 0,
		pc[0], pc[1], 1;

	S << 1.2, 0, 0,
		0, 1.3, 0,
		0, 0, 1;

	d1 = p1.transpose() * T1 * S * R * T2;
	d2 = p2.transpose() * T1 * S * R * T2;
	d3 = p3.transpose() * T1 * S * R * T2;
	d4 = p4.transpose() * T1 * S * R * T2;

	line(out, Point(d1[0], d1[1]), Point(d2[0], d2[1]), Scalar(255, 0, 255), 1);
	line(out, Point(d1[0], d1[1]), Point(d3[0], d3[1]), Scalar(255, 0, 255), 1);
	line(out, Point(d2[0], d2[1]), Point(d4[0], d4[1]), Scalar(255, 0, 255), 1);
	line(out, Point(d3[0], d3[1]), Point(d4[0], d4[1]), Scalar(255, 0, 255), 1);

	d1 = p1.transpose() * T1 * R * T2 * S;
	d2 = p2.transpose() * T1 * R * T2 * S;
	d3 = p3.transpose() * T1 * R * T2 * S;
	d4 = p4.transpose() * T1 * R * T2 * S;

	line(out, Point(d1[0], d1[1]), Point(d2[0], d2[1]), Scalar(255, 255, 0), 1);
	line(out, Point(d1[0], d1[1]), Point(d3[0], d3[1]), Scalar(255, 255, 0), 1);
	line(out, Point(d2[0], d2[1]), Point(d4[0], d4[1]), Scalar(255, 255, 0), 1);
	line(out, Point(d3[0], d3[1]), Point(d4[0], d4[1]), Scalar(255, 255, 0), 1);

	namedWindow("canvas", WINDOW_NORMAL);
	// Show our image ins , image );
	imshow("canvas", out);

	waitKey(0);

	return 0;
}
