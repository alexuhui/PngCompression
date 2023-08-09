cmake_minimum_required(VERSION 3.15)
project(pngCompression)

set(CMAKE_CXX_STANDARD 17)
set(APP_NAME pngCompression)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

add_executable(${APP_NAME} ${SRC})
