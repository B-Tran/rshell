#include <iostream>
#include "stringParser.h"
#include "CMD.h"
#include "cmdTranslator.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>  // wait  
#include <limits.h> // HOST_Name_MAX


int main()
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
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
    
    std::cout << "executeing\n";
    std::vector<CMDLine *> allocatedCommands;
    CMDLine * toExecute = nullptr;
    CMDTranslator translator;
    try 
    {
        toExecute = translator.translate(tokens,allocatedCommands);
    } 
    catch (const std::string e) 
    {
        std::cout << e;
    }
    if(toExecute)
        toExecute->execute();
    else
        std::cout << "to execute failed\n";

    std::cout << "\n";
    while (!allocatedCommands.empty()) 
    {
        delete allocatedCommands.back();
        allocatedCommands.back() = nullptr;
        allocatedCommands.pop_back();
    }
}

