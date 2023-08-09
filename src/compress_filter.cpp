#include "compress_filter.h"
#include "util.h"

bool findConf(const fs::path& curPath, string& conf)
{
    for (const auto& entry : fs::directory_iterator(curPath)) {
        if (fs::is_directory(entry)) 
        {
            if(findConf(entry.path(), conf))// 递归遍历子文件夹
            {
                return true;
            }
        } else if (fs::is_regular_file(entry) && entry.path().filename() == "compressList.txt") 
        {
            conf = entry.path().string();
            std::cout << "filter config : " << conf << std::endl;
            return true;
        }
    }
    return false;
}

vector<fs::path> getCompressList(const fs::path& curPath)
{
    // compressList.txt路径
    string confPath;
    vector<fs::path> compressList;
    if (!findConf(curPath, confPath))
    {
        std::cout << " warning : there is no config file : compressList.txt " << std::endl;
        return compressList;
    }

    std::ifstream confFile(confPath);
    if (!confFile.is_open()) {
        throw runtime_error("can not open the compress config file : " + confPath);
    }

    std::string line;
    fs::path res = getResPath(curPath);
    while (std::getline(confFile, line)) {
        // Remove white space characters using std::remove_if and isspace
        line.erase(remove_if(line.begin(), line.end(), [](unsigned char c) {
            return isspace(c);
        }), line.end());

        if(line.empty() || line._Starts_with("#"))
        {
            continue;
        }

        fs::path file = (res / (line + ".png"));
        compressList.push_back(file);
        std::cout << " ----------- compress file : " << file.string() << std::endl;
    }
    confFile.close();

    return compressList;
}