#ifndef _UTIL_H
#define _UTIL_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

//查找文件路径
bool findFile(const fs::path& curPath, string& conf, string file);
//文件是否存在
inline bool fileExists (const std::string& path);

fs::path getResPath(const fs::path& curPath);

int getPngSize(const fs::path& pngPath);

bool endsWith(const std::string& fullString, const std::string& ending);

void fixPath(fs::path& path, string suffix);

#endif // _UTIL_H