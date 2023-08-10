#include <algorithm>
#include "png_compress.h"
#include "compress_filter.h"
#include "util.h"

bool findPngquant(const fs::path& curPath, string& pngquant)
{
    for (const auto& entry : fs::directory_iterator(curPath)) {
        if (fs::is_directory(entry)) 
        {
            if(findPngquant(entry.path(), pngquant))// 递归遍历子文件夹
            {
                return true;
            }
        } else if (fs::is_regular_file(entry) && entry.path().filename() == "pngquant.exe") 
        {
            pngquant = entry.path().string();
            std::cout << "compress tool : " << pngquant << std::endl << endl;
            return true;
        }
    }
    return false;
}

void pngCompress(const fs::path& curPath, bool no_log)
{
    string op = getOp(no_log);
    // pngquant路径
    string exePath;
    if (!findPngquant(curPath, exePath))
    {
        throw runtime_error("can not find compress tool \"pngquant.exe\" in folder : " + curPath.string());
    }

    vector<fs::path> pngs = getPngs(curPath, no_log);
    vector<fs::path> list = getCompressList(curPath);
    vector<fs::path> skipList;
    if(list.empty())
    {
        skipList = getSkipList(curPath);
    }

    std::cout << endl << "============================== start compress ===========================" << endl;
    for (const fs::path& png : pngs) {
        if(!list.empty())
        {
            auto result = std::find(list.begin(), list.end(), png);
            // did not find
            if(result == list.end())
            {
                continue;
            }
        }else if (!skipList.empty())
        {
            auto result = std::find(skipList.begin(), skipList.end(), png);
            // in skip list
            if(result != skipList.end())
            {
                continue;
            }
        }

        string pngPath = png.string();
        int oriSize = getPngSize(png);
        string cmdLine (exePath + op + pngPath);
        cmdSystem(cmdLine);
        int newSize = getPngSize(png);
        float rate = (float)(oriSize - newSize) / oriSize;
        std::cout << "completed! ori size : " << oriSize << "    new size : " << newSize << "   rate : " << rate * 100 << "%" << endl << endl;
    }
    std::cout << "============================== end compress ===========================" << endl << endl;
}