#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

/*
Example 2-7. The Canny edge detector writes its output to a single-channel (grayscale)
image
*/

using namespace cv;

int main()
{
	Mat img_rgb, img_gry, img_cny;

	namedWindow("Example Gray", WINDOW_AUTOSIZE);
	namedWindow("Example Canny", WINDOW_AUTOSIZE);

	img_rgb = imread("fruits.jpg");

	cvtColor(img_rgb, img_gry, COLOR_RGB2GRAY);
	imshow("Example Gray", img_gry);

	Canny(img_gry, img_cny, 10, 100, 3, true);
	imshow("Example Canny", img_cny);

	waitKey(0);

}

