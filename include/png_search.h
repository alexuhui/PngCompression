#ifndef _PNG_SEARCH_H
#define _PNG_SEARCH_H

#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void checkPngs(vector<fs::path>& pngs, const fs::path& path);
vector<fs::path> getPngs(const fs::path& path);

#endif // _PNG_SEARCH_H