cmake_minimum_required(VERSION 3.5.0)
project(CV_training VERSION 0.1.0 LANGUAGES C CXX)

# 查找 OpenCV库
find_package(OpenCV REQUIRED)

# 图像示例可执行文件
add_executable(image image.cpp)

# 视频示例可执行文件
add_executable(video video.cpp)

# 把 OpenCV 库链接到可执行文件
# 分别链接 OpenCV
target_link_libraries(image ${OpenCV_LIBS})
target_link_libraries(video ${OpenCV_LIBS})

