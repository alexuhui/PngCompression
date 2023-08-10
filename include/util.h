#ifndef _UTIL_H
#define _UTIL_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

fs::path getResPath(const fs::path& curPath);

int getPngSize(const fs::path& pngPath);

#endif // _UTIL_H