#include <iostream>
#include <string>
#include <filesystem>
#include "png_compress.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    try{
        fs::path curPath = fs::current_path();
        cout << "Current path : " << curPath << endl;
        pngCompress(curPath);
        
        system("pause");
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}