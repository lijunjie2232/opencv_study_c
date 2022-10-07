#include "opencv2/opencv.hpp"
#include <iostream>
#include "load_pic.h"


cv::Mat new_pic()
{
	cv::Mat newpic;
	cv::Size size = cv::Size(1920,1080);
	newpic.create(size, 16);
	newpic = cv::Scalar(77, 77, 77);
	cv::namedWindow("newpic", cv::WINDOW_AUTOSIZE);
	cv::imshow("newpic", newpic);
	cv::waitKey(0);

	char* path = (char*)"F:\\c++\\opencv\\demo1\\demo1\\res\\p1.jpg";
	cv::Mat src = load_pic(path, 1);

	cv::Mat dst0, dst1, dst2, dst3;

	dst0 = cv::Mat(src.size(), src.type());
	dst0 = cv::Scalar(177, 177, 177);

	dst1 = cv::Mat(src);

	dst2 = src.clone();

	src.copyTo(dst3);

	cv::imshow("", dst1);
	cv::waitKey(0);

	cv::imshow("", dst0);
	cv::waitKey(0);

	cv::imshow("", dst2);
	cv::waitKey(0);

	cv::imshow("", dst3);
	cv::waitKey(0);

	cv::Mat newone = cv::Mat::ones(512, 512, 16);
	cv::imshow("", newone);
	cv::waitKey(0);

	cv::Mat dst4(512, 512, CV_8UC3, cv::Scalar::all(177));
	cv::imshow("", dst4);
	cv::waitKey();


	const int* p = dst3.ptr<int>(100);

	std::cout << dst3.size() << dst3.type() << std::endl;

	std::cout << dst3.depth() << " " << dst3.cols << " " << dst3.rows << " " << dst3.channels() << std::endl;

	std::cout << sizeof(p) / sizeof(int64) << std::endl;

	std::cout << p[100] << std::endl;

	return newpic;
}