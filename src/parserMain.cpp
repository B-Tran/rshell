#include "stringParser.h"
#include <iostream>

int main()
{
    std::pair<std::string,std::string> pairing;
//    std::vector<std::string> dList;
//    std::vector<std::string> dIList;
//    std::vector<std::string> limiters;
//    dList.push_back(" ");
//    dList.push_back("||");
//    dList.push_back("&&");
//    dList.push_back(";");
//    dList.push_back("[ ");
//    dList.push_back(" ]");
//    dList.push_back("(");
//    dList.push_back(")");
//    dList.push_back(" ");
//    limiters.push_back("\"");
//    limiters.push_back("\'");
    StringParser parsing;
    std::string input;
    parsing.add_delim_item(" ");
    parsing.add_delim_item("||");
    parsing.add_delim_item("&&");
    parsing.add_delim_item(";");
    parsing.add_delim_item("(");
    parsing.add_delim_item(")");
    parsing.add_delim_ign_item(" ");
    pairing.first = "\"";
    pairing.second = "\"";
    parsing.add_literal_item(pairing);
    pairing.first = "\'";
    pairing.second = "\'";
    parsing.add_literal_item(pairing);
    pairing.first = "[ ";
    pairing.second = " ]";
    parsing.add_literal_item(pairing);

    std::vector<std::string> tokens;

    std::cout << "$ ";
    getline(std::cin,input);
    try
    {
        tokens = parsing.parse_string(input);
    }
    catch (std::string e)
    {
        std::cout << e;
    }
    std::cout << "token list\n";
    for(size_t i = 0 ; i < tokens.size(); ++i)
    {
	    std::cout << tokens.at(i) << "\n";
    }
    std::cout << "\n";
}
