#include <iostream>
#include <string>
#include <filesystem>
#include "png_compress.h"
#include "util.h"

using namespace std;
namespace fs = std::filesystem;


/*
    [-nolog]  only print main log
    [conf dir]  conf path 
*/
int main(int argc, char* argv[])
{
    try{
        fs::path curPath = fs::current_path();
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Current path : " << curPath.string() << endl;

        // TODO 把参数封装成结构体
        string conf = "conf.json";
        bool nolog = false;
        if (argc > 1)
        {
            for (size_t i = 1; i < argc; i++)
            {
                string param = argv[i];
                if (param == "-nolog")
                {
                    nolog = true;
                    continue;
                }
                if (param == "-conf")
                {
                    if (i + 1 < argc)
                    {
                        i ++;
                        string file = argv[i];
                        if (endsWith(file, ".json"))
                        {
                            conf = file;
                        }else
                        {
                            conf = file + ".json";
                        }
                    }
                    continue;
                }
            }
        }

        pngCompress(curPath, conf, nolog);
        
        system("pause");
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}