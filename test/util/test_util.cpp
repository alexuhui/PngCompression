#include <iostream>
#include <string>
#include <filesystem>
#include "util.h" 

using namespace std;
namespace fs = std::filesystem;

//第一个参数 argv[0] 是程序的名称，后续的参数 argv[1]、argv[2] 等是传递进来的参数。
int main(int argc, char* argv[])
{
    if(argc < 2) 
    {
        cout << "please appoint a png path" << endl;
    }else
    {
        fs::path curPath = fs::current_path();
        for(int i = 1; i < argc; i ++)
        {
            char* png = argv[i];
            fs::path pngPath = curPath / png;
            int size = getPngSize(pngPath);

            cout << "pngPath : " << pngPath.string() << " size : " << size << endl << endl;
        }
    }

     
    system("pause");
}