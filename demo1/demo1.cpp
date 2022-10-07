// demo1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


#include <iostream>
#include "opencv2/opencv.hpp"
#include "show_version.h"
#include "load_pic.h"
#include "filter.h"
#include "new_pic.h"
#include "pixel_op.h"
#include "show_pic.h"
#include "format_conv.h"
#include "area_detect.h"
#include "pic_op.h"

int main(int argc, char** argv)
{
    show_version();
    //char* path = new char[100];
    //std::cin >> path;
    
    const char* path_1 = (const char*)"F:\\c++\\opencv\\demo1\\demo1\\res\\p1.jpg";
    cv::Mat src = load_pic(path_1, 1);

    const char* path_2 = (const char*)"F:\\c++\\opencv\\demo1\\demo1\\res\\p1_rgb.jpg";
    cv::Mat src_new = load_pic(path_2, 1);
    //show_pic(src);

    // 
    //std::cout << src.type() << std::endl;
    //filter(src);
    //cv::Mat pic;
    //pic.ones(5, 5, 3);
    // 
    //cv::Mat a = new_pic();

    //src.copyTo(a);
    //pixel_op(src);

    //cv::Mat yuv = toYuv(src, "F:\\c++\\opencv\\demo1\\demo1\\res\\p1.yuv");
    //cv::Mat rgb = toRgb(src, "F:\\c++\\opencv\\demo1\\demo1\\res\\p1_rgb.jpg");

    /*图像工程第二次作业
    show_pic(src);
    cv::Mat yuv = toYuv(src);
    show_pic(yuv);
    cv::Mat rgb = toRgb(src);
    show_pic(rgb);
    cv::Mat dst = toGray(src);
    show_pic(dst);
    show_pic(reQutz(dst, 2));
    show_pic(reQutz(dst, 4));
    show_pic(reQutz(dst, 64));*/
    
    /*图像工程第三次作业
    const char* vd_path = "F:\\c++\\opencv\\demo1\\demo1\\res\\tom_and_cat.avi";
    std::vector<cv::Mat> frames = vd_process(vd_path);
    //show_pic(frames);

    cv::Mat background = mf_process(frames);
    show_pic(background);

    std::vector<cv::Mat> frames_rec;
    std::vector<cv::Mat> f_front = fr_process(frames, frames_rec);
    show_pic(f_front);

    std::vector<cv::Mat> f_front_1 = bg_process(frames);
    show_pic(f_front_1);

    show_pic(frames_rec);*/

    pic_op(src, src_new);


    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
