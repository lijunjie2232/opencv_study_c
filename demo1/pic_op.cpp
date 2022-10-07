#include <iostream>
#include "pic_op.h"
#include "show_pic.h"

void pic_op(cv::Mat a, cv::Mat b)
{
	//show_pic(a);
	//show_pic(b);
	cv::Mat dst;
	//cv::addWeighted(a, 0.5, b, 0.5, 0, dst);
	//show_pic(dst);
	//cv::Mat mask = cv::Mat::zeros(a.rows, a.cols, CV_8UC1);
	//mask(cv::Rect(220, 120, 200, 200)).setTo(255);
	//show_pic(mask);
	//cv::add(a, b, dst, mask);
	//a.copyTo(dst, mask);
	//show_pic(dst);
	//cv::multiply(a, b, dst);
	//show_pic(dst);

	/*float alpha = 0.8;
	float beta = (1 - alpha) * 255;

	//cv::convertScaleAbs(a, dst, alpha, beta);
	//show_pic(dst);

	dst = cv::Mat::zeros(a.size(), a.type());

	int c = a.channels();
	int tmp;
	for(int i = 0; i < a.rows; i++)
		for (int j = 0; j < a.cols; j++)
		{
			if(c == 1)
			{
				tmp = a.at<uchar>(i, j);
				dst.at<uchar>(i, j) = cv::saturate_cast<uchar>(tmp * alpha + beta);
			}
			else if(c == 3)
			{
				for (int k = 0; k < c; k++)
				{
					tmp = a.at<cv::Vec3b>(i, j)[k];
					dst.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>(tmp * alpha + beta);
				}
			}
		}
	show_pic(dst);*/


}