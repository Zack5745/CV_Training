#include "image.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void runImageDemo(){
    Mat img = imread("../images/mowan.png");
    if(img.empty()){
        cout << "读图失败" << endl;
        return;
    }

    bool jpg = imwrite("converted.jpg", img);
    if(jpg) cout << "转换成功" << endl;

    namedWindow("图片展示", WINDOW_NORMAL);
    imshow("图片展示", img);
    waitKey(0);
    destroyAllWindows();

    cout << "图像读取成功" << endl;
}