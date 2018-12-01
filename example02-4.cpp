

#include "pch.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>

using namespace std;

/*
Example 2-4. Adding a trackbar slider to the basic viewer window for moving around
within the video file
*/

/*

代码基本思路：
从循环for(;;),也可以用while(1)开始，g_run=1,执行if语句，
读入第一帧，获取当前位置并更新进度条的位置，显示，g_run=g_run-1=0
跳出if。根据用户键入值选择运行模式，若选择单步，则g_run=1,再次进入if语句
若选择正常播放，则g_run=-1,进入if,按照以上方式放完一帧，g_run=g_run-1=-2,
满足if条件，继续执行。若是用户输入ESC,则跳出循环。

*/

//设置全局变量
int g_slider_position = 0;//设置初始位置为0
int g_run = 1;//是否单步运行，单步便为1
int g_dontset = 0;//避免在滑动条同步画面回调程序时单步运行。进入单步运行，变为0；不进入变为1
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);//让进度条移动到我们希望的位置
	if (!g_dontset)//是否进入单步模式
	{
		g_run = 1;
		g_dontset = 0;
	}
}

int main()
{
	cv::namedWindow("example02-4", cv::WINDOW_AUTOSIZE);
	g_cap.open("tree.avi");
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);//读取总帧数
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);//读取视频的宽
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);//读取视频的高
	cout << "Video has " << frames << "frames of dimensions("
		<< tmpw << "," << tmph << ")." << endl;//显示字符
	//创建一个滚动条，格式为createTrackbar(名称，依附于哪个窗口，初始化阈值，刻度范围，回调函数)
	cv::createTrackbar("Position", "example02-4", &g_slider_position, frames, onTrackbarSlide);

	cv::Mat frame;

	//播放开始
	for (;;) {
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty())
				break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);//获取当前帧的位置
			g_dontset = 1;
			cv::setTrackbarPos("Position", "example02-4", current_pos);//根据current_pos回调bar的位置
			cv::imshow("example02-4", frame);//显示当前帧
			g_run -= 1;//自减1
		}
		//根据用户输入设定模式
		char c = (char)cv::waitKey(10);
		if (c == 's')//单步运行模式
		{
			g_run = 1;
			cout << "Single step,run = " << g_run << endl;
		}
		if (c == 'r')//运行模式
		{
			g_run = -1;
			cout << "Run mode,run = " << g_run << endl;
		}
		if (c == 27)//如果按下ESC,退出（ESC键的ASCLL码就是27）
			break;
	}

	return 0;
}

