#include <iostream>
#include "stringParser.h"

int main()
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dList.push_back("#");
    dIList.push_back(" ");
    StringParser parsing(dList,dIList);
    std::string input;
    std::vector<std::string> tokens;

    std::cout << "$ ";
    getline(std::cin,input);
    tokens = parsing.parse_string(input);
    for(size_t i = 0 ; i < tokens.size(); ++i)
    {
	    std::cout << tokens.at(i) << "\n";
    }
    
    
}
