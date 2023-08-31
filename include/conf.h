#ifndef _CONF_H
#define _CONF_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "json11.hpp"
#include "util.h"

using Json = json11::Json;
using namespace std;
namespace fs = std::filesystem;

/*
*   {
*       "tip":"",
*       "CompressPath":[
*           "path1",
*           "path2"
*       ],
*       "SkipPath":[
*           "path1",
*           "path2"
*       ]
*    }
*/
void Parse(const fs::path& path, vector<fs::path> compressList, vector<fs::path> skipList);

#endif  //_CONF_H