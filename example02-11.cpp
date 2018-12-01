#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

/*
Example 2-11. A complete program to read in a color video and write out the log-polartransformed video
*/

using namespace cv;

int main(int argc)
{
	namedWindow("example02-11", WINDOW_AUTOSIZE);
	namedWindow("Log-Polar", WINDOW_AUTOSIZE);

	VideoCapture cap;
	cap.open("tree.avi");
	if (!cap.isOpened()) {
		std::cerr << "Couldn't open capture." << std::endl;
	}

	double fps = cap.get(CV_CAP_PROP_FPS);
	Size size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH), (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;
	writer.open("vout.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	Mat logpolar_frame, bgr_frame;
	for (;;) {
		cap >> bgr_frame;
		if (bgr_frame.empty()) break;
		imshow("example02-11", bgr_frame);

		logPolar(bgr_frame, logpolar_frame, Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40, WARP_FILL_OUTLIERS);
		imshow("Log-Polar", logpolar_frame);
		writer << logpolar_frame;

		char c = waitKey(10);
		if (c == 27)
			break;
	}
	cap.release();
	return 0;
}

