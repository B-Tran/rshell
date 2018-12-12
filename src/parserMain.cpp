#include "stringParser.h"
#include <iostream>

int main()
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dList.push_back("[ ");
    dList.push_back(" ]");
    dList.push_back("(");
    dList.push_back(")");
    dList.push_back(" ");
    dList.push_back(">>");
    dList.push_back(">");
    dList.push_back("<");
    dList.push_back("|");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    std::string input;
    std::vector<std::string> tokens;

    std::cout << "$ ";
    getline(std::cin,input);
    tokens = parsing.parse_string(input);
    std::cout << "token list\n";
    for(size_t i = 0 ; i < tokens.size(); ++i)
    {
	    std::cout << tokens.at(i) << "\n";
    }
    std::cout << "\n";
}
