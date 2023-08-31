cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(APP_NAME test)

# 第三方 代码库
set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty")
set(JSON_INCLUDE ${THIRD_PARTY_DIR}/json11)
# 设置动态库/静态库生成路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/Release)
# # 包含静态库路径
# link_directories(LIBRARY_OUTPUT_PATH)
# # 链接静态库
# link_libraries(json11)

message(json : ${LIBRARY_OUTPUT_PATH})

include_directories(
    ${JSON_INCLUDE}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    
)
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
add_executable(${APP_NAME} json.cpp)

find_library(JSON11_LIB json11 PATHS ${LIBRARY_OUTPUT_PATH})
target_link_libraries(${APP_NAME} PRIVATE ${JSON11_LIB})