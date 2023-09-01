#include "compress_filter.h"
#include "util.h"
#include <map>
#include <functional>

map<size_t, vector<fs::path>> skipMap;
std::hash<std::string> stringHash;
vector<fs::path> getCompressList(const fs::path& curPath, vector<fs::path>& compressList, vector<fs::path>& skipList , bool no_log)
{
    for (fs::path& skip : skipList)
    {
        skip = curPath / skip;
        fixPath(skip, ".png");
        if (!no_log)
            std::cout << " --------------- skip path : " << skip.string() << std::endl;

        size_t key = stringHash(skip.string());
        auto it = skipMap.find(key);
        if (it != skipMap.end()) {
            // 找到了键为 key 的元素
            vector<fs::path> list = it-> second;
            list.push_back(skip);
        } else {
            // 没有找到键为 key 的元素
            vector<fs::path> list;
            list.push_back(skip);
            skipMap[key] = list;
        }
    }

    // test hash map
    // for (const auto& pair : skipMap) {
    //     auto key = pair.first;
    //     auto value = pair.second;

    //     std::cout << " --------------- skip key : " << key << std::endl;
    //     // 使用 key 和 value 进行操作
    //     for(fs::path& path : value)
    //     {
    //          std::cout << " --------------- skip path : " << path.string() << std::endl;
    //     }
    // }


    vector<fs::path> pngs;
    for (fs::path& compress : compressList)
    {
        compress = curPath / compress;
        fixPath(compress, ".png");
        if(!fs::exists(compress))
        {
            std::cout << ">> warnning : path not exists : " << compress.string() << std::endl;
            continue;
        }

        if (!no_log)
            std::cout << " +++++++++++ compress path : " << compress.string() << std::endl;
        findPngs(compress, pngs, no_log);
    }

    if(!no_log)
    {
        for(fs::path png : pngs)
        {
            std::cout << " **** compress png : " << png.string() << std::endl;
        }
    }

    return pngs;
}

void findPngs(const fs::path& compressPath, vector<fs::path>& pngs, bool no_log)
{
    size_t key = stringHash(compressPath.string());
    auto it = skipMap.find(key);
    if (it != skipMap.end()) {
        // 找到了键为 key 的元素
        vector<fs::path> list = it-> second;
        for(auto& skip : list)
        {
            if(skip == compressPath)
            {
                if (!no_log)
                    std::cout << " --------------- the path has been skip : " << compressPath.string() << std::endl;
                return;
            }
        }
    }

    if (fs::is_directory(compressPath)) 
    {
        for (const auto& entry : fs::directory_iterator(compressPath)) {
            findPngs(entry.path(), pngs, no_log);
        }
    }else if (endsWith(compressPath.string(), ".png"))
    {
        pngs.push_back(compressPath);
    }
}