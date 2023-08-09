#include "png_search.h"
#include "util.h"

void checkPngs(vector<fs::path>& pngs, const fs::path& path)
{
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_directory(entry)) {
            checkPngs(pngs, entry.path()); // 递归遍历子文件夹
        } else if (fs::is_regular_file(entry) && entry.path().extension() == ".plist") {
            fs::path plist = entry.path();
            plist.replace_extension(".png");
            if(fs::exists(plist))
            {
                std::cout << "PNG File: " << plist << std::endl;
                pngs.push_back(plist);
            }
        }
    }
}

vector<fs::path> getPngs(const fs::path& path)
{
    vector<fs::path> pngs;
    // 同级目录查找 res 目录
    fs::path res = getResPath(path);
    checkPngs(pngs, res);
    return pngs;
}