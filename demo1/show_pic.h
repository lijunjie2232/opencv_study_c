#pragma once
#ifndef _SHOW_PIC__
#define _SHOW_PIC__
#include "opencv2/opencv.hpp"

void show_pic(cv::Mat src, const char* title = "show_pic");

void show_pic(std::vector<cv::Mat> src, const char* title = "show_pic");

#endif