#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

/*
Example 2-6. Using cv::pyrDown() to create a new image that is half the width and
height of the input image
*/

using namespace cv;

int main()
{
	Mat img1, img2;

	namedWindow("Example1", WINDOW_AUTOSIZE);
	namedWindow("Example2", WINDOW_AUTOSIZE);

	img1 = imread("faces.png");
	imshow("Example1", img1);

	pyrDown(img1, img2);
	imshow("Example2", img2);

	waitKey(0);
	return 0;
}