

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

�������˼·��
��ѭ��for(;;),Ҳ������while(1)��ʼ��g_run=1,ִ��if��䣬
�����һ֡����ȡ��ǰλ�ò����½�������λ�ã���ʾ��g_run=g_run-1=0
����if�������û�����ֵѡ������ģʽ����ѡ�񵥲�����g_run=1,�ٴν���if���
��ѡ���������ţ���g_run=-1,����if,�������Ϸ�ʽ����һ֡��g_run=g_run-1=-2,
����if����������ִ�С������û�����ESC,������ѭ����

*/

//����ȫ�ֱ���
int g_slider_position = 0;//���ó�ʼλ��Ϊ0
int g_run = 1;//�Ƿ񵥲����У�������Ϊ1
int g_dontset = 0;//�����ڻ�����ͬ������ص�����ʱ�������С����뵥�����У���Ϊ0���������Ϊ1
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);//�ý������ƶ�������ϣ����λ��
	if (!g_dontset)//�Ƿ���뵥��ģʽ
	{
		g_run = 1;
		g_dontset = 0;
	}
}

int main()
{
	cv::namedWindow("example02-4", cv::WINDOW_AUTOSIZE);
	g_cap.open("tree.avi");
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);//��ȡ��֡��
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);//��ȡ��Ƶ�Ŀ�
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);//��ȡ��Ƶ�ĸ�
	cout << "Video has " << frames << "frames of dimensions("
		<< tmpw << "," << tmph << ")." << endl;//��ʾ�ַ�
	//����һ������������ʽΪcreateTrackbar(���ƣ��������ĸ����ڣ���ʼ����ֵ���̶ȷ�Χ���ص�����)
	cv::createTrackbar("Position", "example02-4", &g_slider_position, frames, onTrackbarSlide);

	cv::Mat frame;

	//���ſ�ʼ
	for (;;) {
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty())
				break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);//��ȡ��ǰ֡��λ��
			g_dontset = 1;
			cv::setTrackbarPos("Position", "example02-4", current_pos);//����current_pos�ص�bar��λ��
			cv::imshow("example02-4", frame);//��ʾ��ǰ֡
			g_run -= 1;//�Լ�1
		}
		//�����û������趨ģʽ
		char c = (char)cv::waitKey(10);
		if (c == 's')//��������ģʽ
		{
			g_run = 1;
			cout << "Single step,run = " << g_run << endl;
		}
		if (c == 'r')//����ģʽ
		{
			g_run = -1;
			cout << "Run mode,run = " << g_run << endl;
		}
		if (c == 27)//�������ESC,�˳���ESC����ASCLL�����27��
			break;
	}

	return 0;
}

