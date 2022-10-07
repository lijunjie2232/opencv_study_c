#include <iostream>
#include <opencv2/opencv.hpp>

void show_version()
{
	std::cout << "OpenCV_Version: " << CV_VERSION << std::endl;
	cv::waitKey(0);
}