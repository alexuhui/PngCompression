#include <iostream>
#include <string>
#include <filesystem>
#include "png_compress.h"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    try{
        fs::path curPath = fs::current_path();
        cout << "Current path : " << curPath << endl;

        bool nolog = false;
        string param1 = argv[1];
        if(argc > 1 && param1 == "-nolog")
        {
            nolog = true;
        }
        pngCompress(curPath, nolog);
        
        system("pause");
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}