#ifndef _COMPRESS_FILTER_H
#define _COMPRESS_FILTER_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>  

using namespace std;
namespace fs = std::filesystem;

bool findConf(const fs::path& curPath, string& conf, string file);
vector<fs::path> getCompressList(const fs::path& curPath);
vector<fs::path> getSkipList(const fs::path& curPath);

#endif // _COMPRESS_FILTER_H