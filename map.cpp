#include <iostream>
#include <map>
#include <string>

int main(void)
{
    std::map<std::string, int> myMap1; //the first way to initialize the map
    myMap1["Mark"] = 123;
    myMap1["Tom"] = 21;
    myMap1["any"] = 33;

    std::map<std::string, int> myMap2 = 
    {
        {"Mark", 123},
        {"Tom", 21},
        {"Any", 33}
    }; //another way of initializing

    int val1 = myMap1.at("Mark");
    int val2 = myMap1["Tom"];

    myMap1.insert({"John", 23});
    myMap1.emplace("Jose", 11);

    myMap1.erase("Mark");

    for(const auto& element : myMap1)
    {
        std::cout << element.first << ": " << element.second << std::endl;
    }
    
    auto it = myMap1.find("any");
    if (it == myMap1.end())
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << "Found" << std::endl;
    }

    return 0;
}