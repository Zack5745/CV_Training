#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
    //读取一张图片（路径自定，支持 JPG/PNG），
    //若读取失败，提示 “图片无法打开”。
    Mat img = imread("../images/mowan.png");
    if(img.empty()){
        cout << "读图失败" << endl;
        return -1;
    }

    bool jpg = imwrite("converted.jpg",img);
    if(jpg) cout << "zhuanhuanchenggong" << endl;

    namedWindow("图片展示",WINDOW_NORMAL);
    imshow("图片展示", img);
    waitKey(0);
    destroyAllWindows();

    cout << "图像读取成功" << endl;
    return 0;
}