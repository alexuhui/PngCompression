#ifndef _COMPRESS_FILTER_H
#define _COMPRESS_FILTER_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>  

using namespace std;
namespace fs = std::filesystem;

// v2 filter by conf.json 
vector<fs::path> getCompressList(const fs::path& curPath, vector<fs::path>& compressList, vector<fs::path>& skipList, bool no_log);
void findPngs(const fs::path& compressPath, vector<fs::path>& pngs, bool no_log);

#endif // _COMPRESS_FILTER_H