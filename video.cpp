#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
    VideoCapture cap("../images/xiaoxin.mp4");
    if(!cap.isOpened()){
        cout << "打开视频失败" << endl;
        return -1;
    }

    double fps = cap.get(CAP_PROP_FPS);
    int    delay = static_cast<int>(1000.0 / fps);
    int    frameWidth  = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int    frameHeight = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
    Size   frameSize(frameWidth, frameHeight);

    // 准备写前 30 帧
    VideoWriter writer;
    int fourcc = VideoWriter::fourcc('m','p','4','v');
    writer.open("video_30frames.mp4",
                fourcc,
                fps,
                frameSize,
                true);   // isColor
    if (!writer.isOpened()) {
        cout << "无法创建输出视频" << endl;
        return -1;
    }
   
    Mat frame;
    int  frameCount = 0;
    bool paused = false;

    while (true){
        if (!paused) {
            cap >> frame;     // 读取下一帧
            if (frame.empty()) break;   // 视频结束
            ++frameCount;
        }

        imshow("video show", frame);

        // 保存前 30 帧
        if (frameCount <= 30 && !paused) {
            writer.write(frame);
        }

        char c = waitKey(paused ? 0 : delay);
        if (c == 'q' || c == 'Q') {
            break;                      // 提前退出
        }
        if (c == ' ') {
            paused = !paused;           // 空格暂停/继续
        }
    }

    cap.release();
    writer.release();
    destroyAllWindows();
    cout << "已播放并保存前 30 帧到 video_30frames.mp4" << endl;
    return 0;
}