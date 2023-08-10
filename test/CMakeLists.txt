cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(APP_NAME test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR}/../include)
add_executable(${APP_NAME} test_util.cpp ../src/util.cpp)
