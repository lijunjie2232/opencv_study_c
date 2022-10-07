#pragma once
#ifndef _FORMAT_CONV__
#define _FORMAT_CONV__
#include "opencv2/opencv.hpp"

cv::Mat toRgb(cv::Mat src, const char* path = NULL);
cv::Mat toYuv(cv::Mat src, const char* path = NULL);
cv::Mat toGray(cv::Mat src, const char* path = NULL);
cv::Mat reQutz(cv::Mat src, int bl = 1);

#endif