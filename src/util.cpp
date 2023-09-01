#include "util.h"

bool findConf(const fs::path& curPath, string& conf, string file)
{
    for (const auto& entry : fs::directory_iterator(curPath)) {
        if (fs::is_directory(entry)) 
        {
            if(findConf(entry.path(), conf, file))// 递归遍历子文件夹
            {
                return true;
            }
        } else if (fs::is_regular_file(entry) && entry.path().filename() == file) 
        {
            conf = entry.path().string();
            std::cout << "filter config : " << conf << std::endl;
            return true;
        }
    }
    return false;
}

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

void fixPath(fs::path& path, string suffix)
{
    // 统一斜杠
    string pathStr = path.string();
    bool hasPoint = false;
    for (char& c : pathStr) {
        if (c == '/') {
            c = '\\';
        }else if (c == '.')
        {
            hasPoint = true;
        }
    }
    path = fs::path(pathStr);
    if(!fs::is_directory(path) && !hasPoint)
    {
        path += suffix;
    }
}