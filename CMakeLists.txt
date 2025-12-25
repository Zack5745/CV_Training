cmake_minimum_required(VERSION 3.5.0)
project(CV_training VERSION 0.1.0 LANGUAGES C CXX)

# 查找 OpenCV库
find_package(OpenCV REQUIRED)

# 头文件搜索路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 统一入口
add_executable(main
    main.cpp
    src/image.cpp
    src/video.cpp
)

# 链接 OpenCV
target_link_libraries(main ${OpenCV_LIBS})

