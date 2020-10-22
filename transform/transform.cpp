#include <iostream>
#include <fstream>
#include <string>

#include <Eigen/Dense>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace Eigen;
using namespace cv;

int main(void)
{

    Matrix3d R;              //matriz de rotacao
    Matrix3d T1, T2;         //matriz de translacao
    Matrix3d S;              //matriz de escala
    Vector3d p1, p2, p3, p4; //pontos do quadrado
    Vector3d pd;
    Vector3d d1, d2, d3, d4;
    Mat img = imread("imagem_01.jpg");
    Mat img_result = Mat::zeros(img.rows, img.cols, CV_8UC3);

    double escala;
    double angulo;

    if (img.empty())
    {
        cerr << "Deu ruim";
    };

    int comp = 50;

    cout << "Digite os valores do ponto base para o quadrado.\n";
    cout << "x: ";
    cin >> p1[0];
    cout << "y: ";
    cin >> p1[1];
    p1[2] = 1;

    cout << "digite o comprimento desejado para o quadrado:\n";
    cin >> comp;

    cout << "digite a escala que sera usada para alongar o quadrado:\n";
    cin >> escala;

    cout << "digite o angulo que o quadrado será girado:\n";
    cin >> angulo;

    p2 << p1[0], p1[1] + comp, 1;
    p3 << p1[0] + comp, p1[1], 1;
    p4 << p1[0] + comp, p1[1] + comp, 1;

    angulo = angulo * 3.1415 / 180;

    R << cos(angulo), sin(angulo), 0,
        -sin(angulo), cos(angulo), 0,
        0, 0, 1;

    T1 << 1, 0, 0,
        0, 1, 0,
        -p1[0], -p1[1], 1;

    T2 << 1, 0, 0,
        0, 1, 0,
        p1[0], p1[1], 1;

    S << escala, 0, 0,
        0, escala, 0,
        0, 0, 1;

    for (int y = p1[1]; y < p4[1]; y++)
    {
        for (int x = p1[0]; x < p4[0]; x++)
        {
            img_result.at<Vec3b>(y, x) = img.at<Vec3b>(y, x);
        }
    }

    d1 = p1.transpose() * T1 * R * S;
    d2 = p2.transpose() * T1 * R * S;
    d3 = p3.transpose() * T1 * R * S;
    d4 = p4.transpose() * T1 * R * S;

    rectangle(img, Point(p1[0], p1[1]), Point(p4[0], p4[1]), Scalar(255, 255, 255), 3);

    line(img_result, Point(d1[0], d1[1]), Point(d2[0], d2[1]), Scalar(0, 0, 255), 3);
    line(img_result, Point(d1[0], d1[1]), Point(d3[0], d3[1]), Scalar(0, 255, 0), 3);
    line(img_result, Point(d2[0], d2[1]), Point(d4[0], d4[1]), Scalar(255, 0, 0), 3);
    line(img_result, Point(d3[0], d3[1]), Point(d4[0], d4[1]), Scalar(0, 0, 255), 3);

    namedWindow("canvas", WINDOW_NORMAL);
    // Show our image ins , image );
    imshow("canvas", img_result);

    waitKey(0);
}
