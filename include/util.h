#ifndef _UTIL_H
#define _UTIL_H

#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

fs::path getResPath(const fs::path& curPath);

#endif // _UTIL_H