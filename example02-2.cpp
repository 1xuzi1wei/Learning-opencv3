#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

/*
Example 2-2. Same as Example 2-1 but employing the ¡°using namespace¡± directive
*/

int main()
{
	Mat img = imread("fruits.jpg");

	if (img.empty()) return -1;

	namedWindow("Example 2-1", WINDOW_AUTOSIZE);
	imshow("Example 2-1", img);
	waitKey(0);
	destroyWindow("Example 2-1");

	return 0;
}