//show_pic.cpp
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

void show_pic(cv::Mat src, const char * title)
{
	cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
	cv::imshow(title, src);
	cv::waitKey(0);
}

void show_pic(std::vector<cv::Mat> src, const char* title)
{
	for (int i = 0; i < src.size(); i++)
		show_pic(src[i], title);
}