#pragma once
#ifndef _AREA_DETECT__
#define _AREA_DETECT__

#include "opencv2/opencv.hpp"
#include <vector>

std::vector<cv::Mat> vd_process(const char* url); 

cv::Mat mf_process(std::vector<cv::Mat> frames);

std::vector<cv::Mat>fr_process(std::vector<cv::Mat> frames, std::vector<cv::Mat> &frames_rec);

std::vector<cv::Mat>bg_process(std::vector<cv::Mat> frames);

#endif