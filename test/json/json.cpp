#include <iostream>
#include <string>
#include <filesystem>
#include "json11.hpp"

using Json = json11::Json;
using namespace std;
namespace fs = std::filesystem;

//第一个参数 argv[0] 是程序的名称，后续的参数 argv[1]、argv[2] 等是传递进来的参数。
int main(int argc, char* argv[])
{
    string str = R"({"msg":"","data":[{"progress":100,"uid":"user1000001"},{"progress":100,"uid":"ai1617"}],"code":0})";
    cout << str << endl;
    string err;
    auto json = Json::parse(str, err);
    std::string dump = json.dump();

    cout << "dump : " << dump << "  err : " << err << endl;
    
    Json::array data = json["data"].array_items();
    cout << "data : " << data[0].dump() << endl;

    system("pause");
}