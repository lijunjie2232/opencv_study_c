#include "opencv2/opencv.hpp"
#include <iostream>

void pixel_op(cv::Mat src)
{
	cv::Mat dst = src.clone();
	//cv::Scalar a = dst.at<uchar>(500, 500);
	//RGB图的.at<uchar> 转为灰度
	cv::Scalar a = dst.at<uchar>(cv::Point(50, 50));
	std::cout << a << std::endl;

	a = dst.at<cv::Vec3b>(cv::Point(50, 50));
	std::cout << a << std::endl;

	a = dst.at<cv::Vec3b>(cv::Point(50, 50));
	std::cout << a << std::endl;

	cv::Vec3b b = dst.at<cv::Vec3b>(50, 50);
	std::cout << b << std::endl;
	std::cout << (int)b.val[0] << std::endl;

	//modify pixel value
	/*
	dst.at<cv::Vec3b>(50, 50)[0] = 0;
	*/
	cv::Vec3b pixel(255, 255, 255);
	for(int i = 50; i < 100; i ++)
		for(int j = 50; j < 100; j ++)
		dst.at<cv::Vec3b>(i, j) = pixel;
	cv::namedWindow("a", 1);
	cv::imshow("a", dst);
	cv::waitKey(0);

	cv::Rect r(150, 150, 500, 500);
	cv::Mat roi = dst(r);
	cv::imshow("test", roi);
	cv::waitKey(0);
}