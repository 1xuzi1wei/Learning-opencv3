#include "pch.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>

/*
Example 2-5. Loading and then smoothing an image before it is displayed on the screen
*/

using namespace cv;

int main()
{
	//在命令行加载图像
	Mat img = imread("fruits.jpg");

	//创建一些窗口显示输入跟输出的图像
	namedWindow("example02-5-in", WINDOW_AUTOSIZE);
	namedWindow("example02-5-out", WINDOW_AUTOSIZE);

	//创建窗口显示输入的图像
	imshow("example02-5-in", img);

	//创建图像保存平滑后的输出图像
	Mat out;

	//做一些平滑（可以用高斯平滑，线性平滑，中值平滑，双边平滑）
	GaussianBlur(img, out, Size(5, 5), 3, 3);
	GaussianBlur(out, out, Size(5, 5), 3, 3);

	//在输出的窗口上显示平滑后的图像
	imshow("example02-5-out", out);

	//等待用户按下按键，窗口自动消失
	waitKey(0);

	return 0;
}

