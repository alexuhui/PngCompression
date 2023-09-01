#include "conf.h"
#include <sstream>

void ParseConf(const fs::path& path, vector<fs::path>& compressList, vector<fs::path>& skipList, bool no_log)
{
    string pathStr = path.string();
    std::ifstream confFile(pathStr);
    if (!confFile.is_open()) {
        throw runtime_error("can not open the compress config file : " + pathStr);
    }

    std::stringstream buffer;
    buffer << confFile.rdbuf();

    std::string fileContent = buffer.str();
    string err;
    auto json = Json::parse(fileContent, err);
    auto compress = json["CompressPath"].array_items();
    auto skip = json["SkipPath"].array_items();
    
    for (int i = 0; i < compress.size(); i++)
    {
        compressList.push_back(compress[i].string_value());
    }
    for (int i = 0; i < skip.size(); i++)
    {
        skipList.push_back(skip[i].string_value());
    }

    confFile.close();
}
