#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

/*
In Example 2-9, we show a simple way to read and write pixel values from
Example 2-8
*/

using namespace cv;

int main()
{
	Mat img_rgb, img_gry, img_cny, img_pyr1, img_pyr2;

	namedWindow("Example Gray", WINDOW_AUTOSIZE);
	namedWindow("Example Canny", WINDOW_AUTOSIZE);

	img_rgb = imread("fruits.jpg");

	cvtColor(img_rgb, img_gry, COLOR_RGB2GRAY);
	imshow("Example Gray", img_gry);
	pyrDown(img_gry, img_pyr1);
	pyrDown(img_pyr1, img_pyr2);

	Canny(img_pyr2, img_cny, 10, 100, 3, true);
	imshow("Example Canny", img_cny);

	int x = 16, y = 32;
	Vec3b intensity = img_rgb.at<Vec3b>(y, x);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	std::cout << "at(x,y) = (" << x << ", " << y << "): (blue, green, red) = (" <<
		(unsigned int)blue <<
		", " << (unsigned int)green << ", " <<
		(unsigned int)red << ")" << std::endl;

	std::cout << "Gray pixel there is: " <<
		(unsigned int)img_gry.at<uchar>(y, x) << std::endl;

	x /= 4; y /= 4;

	std::cout << "pyramid2 pixel there is: " <<
		(unsigned int)img_pyr2.at<uchar>(y, x) << std::endl;

	img_cny.at<uchar>(x, y) = 128;

	waitKey(0);

}

