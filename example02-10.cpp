#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

/*
Example 2-10. The same object can load videos from a camera or a file
*/

using namespace cv;

int main(int argc)
{
	namedWindow("example02-10", WINDOW_AUTOSIZE);
	VideoCapture cap;
	if (argc == 1) {
		cap.open(0);
	}
	else {
		cap.open("tree.avi");
	}

	if (!cap.isOpened()) {
		std::cerr << "Couldn't open capture." << std::endl;
	}
	Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty()) break;
		imshow("example02-10", frame);
		if (waitKey(33) >= 0) break;
	}

	return 0;
}

