//load_pic.cpp
#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat load_pic(const char * path, int ImreadModes_num)
{
	std::cout << "loading: " << path << "as pic" << std::endl;
	if (path)
	{
		//cv::Mat src = cv::imread(path, cv::IMREAD_UNCHANGED);//ImreadModes
		cv::Mat src = cv::imread(path, ImreadModes_num);/*
		IMREAD_UNCHANGED(<0)表示加载原图，不做任何改变。
		IMREAD_GRAYSCALE(0)表示把原图作为灰度图像加载进来。
		IMREAD_COLOR(>0)表示把原图作为RGB图像加载进来。*/

		if (src.empty())
		{
			std::cout << "load faild, please check file path ..." << std::endl;
			return src;
		}
		//cv::namedWindow(path, cv::WINDOW_NORMAL);
		/*WINDOW_AUTOSIZE会自动根据图像大小，显示窗口大小，不能人为改变窗口大小。
		WINDOW_NORMAL允许修改窗口的大小。
		cv::imshow根据窗口名称显示图像到指定的窗口上去，第一个参数是窗口名称，第二个参数是Mat对象。*/

		/*cv::imshow(path, src);
		cv::waitKey(0);*/

		/*cv::Mat src_cvt;
		cv::cvtColor(src, src_cvt, cv::COLOR_BGR2GRAY);//ColorConversionCodes
		cv::namedWindow(path, cv::WINDOW_AUTOSIZE);
		cv::imshow(path, src_cvt);
		cv::waitKey(0);

		cv::imwrite("F:\\c++\\opencv\\demo1\\demo1\\res\\p1_new.jpg", src_cvt);*/

		return src;
	}
}