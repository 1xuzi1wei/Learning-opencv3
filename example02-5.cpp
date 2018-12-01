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
	//�������м���ͼ��
	Mat img = imread("fruits.jpg");

	//����һЩ������ʾ����������ͼ��
	namedWindow("example02-5-in", WINDOW_AUTOSIZE);
	namedWindow("example02-5-out", WINDOW_AUTOSIZE);

	//����������ʾ�����ͼ��
	imshow("example02-5-in", img);

	//����ͼ�񱣴�ƽ��������ͼ��
	Mat out;

	//��һЩƽ���������ø�˹ƽ��������ƽ������ֵƽ����˫��ƽ����
	GaussianBlur(img, out, Size(5, 5), 3, 3);
	GaussianBlur(out, out, Size(5, 5), 3, 3);

	//������Ĵ�������ʾƽ�����ͼ��
	imshow("example02-5-out", out);

	//�ȴ��û����°����������Զ���ʧ
	waitKey(0);

	return 0;
}

