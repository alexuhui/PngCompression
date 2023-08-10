#include <algorithm>
#include "png_compress.h"
#include "compress_filter.h"

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

void pngCompress(const fs::path& curPath)
{
    string op = getOp();
    // pngquant路径
    string exePath;
    if (!findPngquant(curPath, exePath))
    {
        throw runtime_error("can not find compress tool \"pngquant.exe\" in folder : " + curPath.string());
    }

    vector<fs::path> pngs = getPngs(curPath);
    vector<fs::path> list = getCompressList(curPath);

    std::cout << endl << "============================== start compress ===========================" << endl;
    for (const fs::path& png : pngs) {
        auto result = std::find(list.begin(), list.end(), png);
        if(result == list.end())
        {
            // std::cout << "!!!!!!!!! the png has been skiped : " << png.string() << std::endl;
            continue;
        }

        string cmdLine (exePath + op + png.string());
        cmdSystem(cmdLine);
    }
    std::cout << "============================== end compress ===========================" << endl << endl;
}