#include "compress_filter.h"
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

vector<fs::path> getCompressList(const fs::path& curPath)
{
    // compressList.txt路径
    string confPath;
    vector<fs::path> compressList;
    if (!findConf(curPath, confPath, "compressList.txt"))
    {
        std::cout << "there is no config file : compressList.txt " << std::endl;
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
        std::cout << " ----------- file to compress : " << file.string() << std::endl;
    }
    confFile.close();

    return compressList;
}

vector<fs::path> getSkipList(const fs::path& curPath)
{
    // skipList.txt路径
    string confPath;
    vector<fs::path> skipList;
    if (!findConf(curPath, confPath, "skipList.txt"))
    {
        std::cout << "there is no config file : skipList.txt " << std::endl;
        return skipList;
    }

    std::ifstream confFile(confPath);
    if (!confFile.is_open()) {
        throw runtime_error("can not open the skipList config file : " + confPath);
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
        skipList.push_back(file);
        std::cout << " ----------- file to skip : " << file.string() << std::endl;
    }
    confFile.close();

    return skipList;
}