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