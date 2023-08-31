#include <iostream>
#include <string>
#include <filesystem>
#include "png_compress.h"
#include "util.h"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    try{
        fs::path curPath = fs::current_path();
        cout << "Current path : " << curPath << endl;

        string conf = "conf.json";
        if(argc > 1)
        {
            string param1 = argv[1];
            if (endsWith(param1, ".json"))
            {
                conf = param1;
            }else
            {
                conf = param1 + ".json";
            }
        }

        bool nolog = false;
        if(argc > 2)
        {
            string param2 = argv[2];
            if (param2 == "-nolog")
            {
                nolog = true;
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