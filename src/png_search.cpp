#include "png_search.h"
#include "util.h"

void checkPngs(vector<fs::path>& pngs, const fs::path& path, bool no_log)
{
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_directory(entry)) {
            checkPngs(pngs, entry.path(), no_log); // 递归遍历子文件夹
        } else if (fs::is_regular_file(entry) && entry.path().extension() == ".png") {
            fs::path png = entry.path();
            if (!no_log)
            {
                std::cout << "PNG File: " << png << std::endl;
            }
            
            pngs.push_back(png);
        }
    }
}

vector<fs::path> getPngs(const fs::path& path, bool no_log)
{
    vector<fs::path> pngs;
    // 同级目录查找 res 目录
    fs::path res = getResPath(path);
    checkPngs(pngs, res, no_log);
    return pngs;
}