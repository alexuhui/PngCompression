#include "util.h"

fs::path getResPath(const fs::path& curPath)
{
    // 同级目录查找 res 目录
    fs::path res = curPath / "./res/";
    if (!fs::is_directory(res)) 
    {
        // 上级目录查找 res 目录
        res = curPath / "../res/";
         if (!fs::is_directory(res)) 
         {
            throw runtime_error("Directory \"res\" not exist! Please place the compression program and execute itcd in the same-level directory as the 'res' directory.");
         }
    }

    return res;
}

int getPngSize(const fs::path& pngPath)
{
    std::ifstream file(pngPath, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open the file : " << pngPath << std::endl;
        return 0;
    }

    // 获取文件大小
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    // cout << "png : " << pngPath <<  " size : " << fileSize << endl;
    return fileSize;
}

bool endsWith(const std::string& fullString, const std::string& ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    return false;
}