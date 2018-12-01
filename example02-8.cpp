#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

/*
Example 2-8. Combining the pyramid down operator (twice) and the Canny
subroutine in a simple image pipeline
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

	waitKey(0);

}

