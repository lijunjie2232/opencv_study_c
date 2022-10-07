//format_conv.cpp
#include "opencv2/opencv.hpp"
#include <iostream>

cv::Mat toYuv(cv::Mat src, const char* path)
{
	cv::Mat dst;
	cv::cvtColor(src, dst, cv::COLOR_BGR2YUV_I420);
	if (path)
	{
		unsigned char* pFrame = (unsigned char*)malloc((src.rows) * (src.cols) * 3 / 2);
		if (NULL == pFrame)
		{
			printf("malloc pFrame memory error\n");
		}
		memset(pFrame, 0, (static_cast<size_t> (src.rows)) * (src.cols) * 3 / 2);
		memcpy(pFrame, dst.data, (static_cast<size_t> (src.rows)) * (src.cols) * 3 / 2);//注意这里用的是cv_img的宽高，如果使用cv_yuv的宽高，那么就不用*3/2了。

		FILE* fp;
		fopen_s(&fp, path, "wb+");
		if (NULL == fp)
		{
			printf("file open error\n");
		}
		fwrite(pFrame, 1, (static_cast<size_t> (src.rows)) * (src.cols) * 3 / 2, fp);
		fclose(fp);
	}
	return dst;
}

cv::Mat toRgb(cv::Mat src, const char* path)
{
	cv::Mat dst;
	cv::cvtColor(src, dst, cv::COLOR_BGR2RGB);
	if (path != NULL)
		cv::imwrite(path, dst);
	return dst;
}

cv::Mat toGray(cv::Mat src, const char* path)
{
	cv::Mat dst;
	cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
	if (path != NULL)
		cv::imwrite(path, dst);
	return dst;
}

cv::Mat reQutz(cv::Mat src, int bl)
{
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			src.at<uchar>(i, j) -= src.at<uchar>(i, j) % bl;
			//src.at<uchar>(i, j) -= src.at<uchar>(i, j) / bl;

	return src;
}