#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int ground[10][20];



int main()
{
    auto a = "中" "国";
    std::cout << a << std::endl;

    json j = "{\"name\": \"兆秋\", \"age\": 27}"_json;

    std::cout << j << std::endl;
    
    return 0;
}