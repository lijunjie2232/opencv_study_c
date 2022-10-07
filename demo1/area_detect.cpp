//图像工程第三次作业
#include <iostream>
#include "opencv2/opencv.hpp"
#include <vector>
#include "area_detect.h"
#include "show_pic.h"

std::vector<cv::Mat> vd_process(const char* path)
{
	std::vector<cv::Mat> frames;
	cv::VideoCapture capture;
	capture.open(path);
	if (!capture.isOpened())
		std::cout << "video open faild ..." << std::endl;

	cv::Size size = cv::Size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH), (int)capture.get(cv::CAP_PROP_FRAME_WIDTH));
	double fps = capture.get(cv::CAP_PROP_FPS);
	std::cout << "size: " << size << std::endl << "fps: " << fps << std::endl;
	cv::Mat frame;
    while (capture.read(frame))
    {
		frames.push_back(frame.clone());
        //show_pic(frame);
    }
	capture.release();
	std::cout << frames.size() << std::endl;
	return frames;
}

int getMedian(std::vector<int> elements)
{
    std::vector<int> temp(elements.begin(), elements.end());

    sort(temp.begin(), temp.end());
    return temp[temp.size() / 2];
}

cv::Mat mf_process(std::vector<cv::Mat> frames)
{

    // Note: Expects the image to be CV_8UC3
    cv::Mat medianImg(frames[0].rows, frames[0].cols, CV_8UC3, cv::Scalar(0, 0, 0));

    for (int row = 0; row < frames[0].rows; row++)
    {
        for (int col = 0; col < frames[0].cols; col++)
        {
            std::vector<int> elements_B;
            std::vector<int> elements_G;
            std::vector<int> elements_R;

            for (int imgNumber = 0; imgNumber < frames.size(); imgNumber++)
            {
                int B = frames[imgNumber].at<cv::Vec3b>(row, col)[0];
                int G = frames[imgNumber].at<cv::Vec3b>(row, col)[1];
                int R = frames[imgNumber].at<cv::Vec3b>(row, col)[2];

                elements_B.push_back(B);
                elements_G.push_back(G);
                elements_R.push_back(R);
            }

            medianImg.at<cv::Vec3b>(row, col)[0] = getMedian(elements_B);
            medianImg.at<cv::Vec3b>(row, col)[1] = getMedian(elements_G);
            medianImg.at<cv::Vec3b>(row, col)[2] = getMedian(elements_R);
        }
    }
    return medianImg;
}


std::vector<cv::Mat> fr_process(std::vector<cv::Mat> frames, std::vector<cv::Mat>& frames_rec)
{
    cv::Mat temp, gray;
    cv::Mat background, foreground, foreground_BW;
    cv::Mat frame_0;
    cv::Mat mid_filer;   //中值滤波法后的照片
    std::vector<cv::Mat> f_g;
    for (int i = 0; i < frames.size(); i++)
    {
        cv::Mat frame = frames[i].clone();
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        if (i == 0)
        {
            frame_0 = gray.clone();
        }
        background = frame_0;
        //2.将当前帧与背景做差
        cv::absdiff(gray, background, foreground); //用帧差法求前景
        //3.对差值foreground进行二值化
        cv::threshold(foreground, foreground_BW, 50, 255, 0);//二值化通常设置为50  255
        //4.kernel声明, 腐蚀
        //Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
        //cv::erode(foreground_BW, foreground_BW, element);
        //5.膨胀
        //Mat kernel_dilate = getStructuringElement(MORPH_RECT, Size(18, 18));
        //dilate(foreground_BW, foreground_BW, kernel_dilate);
        //6.中值滤波
        cv::medianBlur(foreground_BW, mid_filer, 3);     //中值滤波法
        f_g.push_back(foreground_BW.clone());
        //6.查找轮廓并绘制轮廓
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mid_filer, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
        //drawContours(frames[i], contours, -1, cv::Scalar(0, 0, 255), 2);//在result上绘制轮廓
        //7.查找正外接矩形
        std::vector<cv::Rect> boundRect(contours.size());

        int xmin = 352, ymin = 352, xmax = 0, ymax = 0;
        for (int i = 0; i < contours.size(); i++)
        {
            boundRect[i] = cv::boundingRect(contours[i]);
            xmin = MIN(xmin, boundRect[i].x);
            ymin = MIN(ymin, boundRect[i].y);
            xmax = MAX(xmax, boundRect[i].x + boundRect[i].width);
            ymax = MAX(ymax, boundRect[i].y + boundRect[i].height);
            //std::cout << "x1y1:" << xmin << "x2y2:" << xmax << std::endl;
        }
        if (contours.size() == 0) {
            xmin = 0, ymin = 0, xmax = 0, ymax = 0;
        }
        cv::rectangle(frame, cv::Point(xmin, ymin), cv::Point(xmax, ymax), cv::Scalar(0, 255, 0), 2);//在result上绘制正外接矩形 
        frames_rec.push_back(frame);
        frame_0 = gray.clone();
    }
    return f_g;
}


std::vector<cv::Mat> bg_process(std::vector<cv::Mat> frames)
{
    cv::Mat background = mf_process(frames);
    cv::Mat bgm, gray, foreground, foreground_BW, mid_filer;
    cv::cvtColor(background, bgm, cv::COLOR_BGR2GRAY);

    std::vector<cv::Mat> f_g;
    for (int i = 0; i < frames.size(); i++)
    {
        cv::cvtColor(frames[i], gray, cv::COLOR_BGR2GRAY);
        //将当前帧与背景做差
        cv::absdiff(gray, bgm, foreground); //用帧差法求前景
        //对差值foreground进行二值化
        cv::threshold(foreground, foreground_BW, 50, 255, 0);//二值化通常设置为50  255
        //中值滤波
        cv::medianBlur(foreground_BW, mid_filer, 3);     //中值滤波法
        f_g.push_back(foreground_BW.clone());
    }
    return f_g;
}