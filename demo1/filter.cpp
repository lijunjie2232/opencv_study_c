#include <iostream>
#include "opencv2/opencv.hpp"

void filter(cv::Mat src)
{
	cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cv::Mat dist;
	cv::filter2D(src, dist, src.depth(), kernel);
	cv::namedWindow("filter2D try", cv::WINDOW_AUTOSIZE);
	cv::imshow("origin pic", src);
	cv::waitKey(0); 
	cv::imshow("filter2D try", dist);
	cv::waitKey(0);
}