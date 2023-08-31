cmake_minimum_required(VERSION 3.15)
project(pngCompression)

set(CMAKE_CXX_STANDARD 17)
set(APP_NAME pngCompression)

# 设置动态库/静态库生成路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 第三方 代码库
set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty")
set(JSON_INCLUDE ${THIRD_PARTY_DIR}/json11)
add_library(json11 STATIC ${JSON_INCLUDE}/json11.cpp)

# 包含静态库路径
link_directories(LIBRARY_OUTPUT_PATH)
# 链接静态库
link_libraries(json11)
# 包含头文件路径
include_directories(
    ${JSON_INCLUDE}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# 指定源文件路径
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

add_executable(${APP_NAME} ${SRC})
