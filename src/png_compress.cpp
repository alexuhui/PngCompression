#include <algorithm>
#include "png_compress.h"
#include "compress_filter.h"
#include "util.h"
#include "conf.h"

void pngCompress(const fs::path& curPath, string& confFile, bool no_log)
{
    string op = getOp(no_log);
    // pngquant路径
    string exePath;
    if (!findFile(curPath, exePath, "pngquant.exe"))
    {
        throw runtime_error("can not find compress tool \"pngquant.exe\" in folder : " + curPath.string());
    }

    vector<fs::path> inc;
    vector<fs::path> skip;
    ParseConf(curPath / confFile, inc, skip, no_log);
    vector<fs::path> pngs = getCompressList(curPath, inc, skip, no_log);

    std::cout << endl << "============================== start compress ===========================" << endl;
    for (const fs::path& png : pngs) {
        string pngPath = png.string();
        int oriSize = getPngSize(png);
        string cmdLine (exePath + op + pngPath);
        cmdSystem(cmdLine);
        int newSize = getPngSize(png);
        float rate = (float)(oriSize - newSize) / oriSize;
        std::cout << "completed! ori size : " << oriSize << "kb    new size : " << newSize << "kb   rate : " << rate * 100 << "%" << endl << endl;
    }
    std::cout << "============================== end compress ===========================" << endl << endl;
}