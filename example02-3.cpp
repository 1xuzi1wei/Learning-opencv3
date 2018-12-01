#include "pch.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

/*
Example 2-3. A simple OpenCV program for playing a video file from disk
*/

int main()
{
	namedWindow("example02-3", WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open("tree.avi");
	Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty()) break;
		imshow("example02-3", frame);
		if (waitKey(33) >= 0) break;
	}

	return 0;
}

