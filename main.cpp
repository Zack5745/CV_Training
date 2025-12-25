#include <iostream>
#include "video.hpp"
#include "image.hpp"

int main(){
    std::cout << "======== 1. 开始图片处理 ========" << std::endl;
    runImageDemo();      // 先处理图片

    std::cout << "======== 2. 开始视频处理 ========" << std::endl;
    runVideoDemo();      // 再处理视频

    std::cout << "======== 全部完成 ========" << std::endl;
    return 0;
}