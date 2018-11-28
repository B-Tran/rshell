#include <iostream>
#include "stringParser.h"
#include "CMD.h"
#include "cmdTranslator.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h> // wait
#include <limits.h>   // HOST_Name_MAX
#include <cstdlib>

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
    StringParser parsing(dList, dIList, limiters);
    std::string input;
    std::vector<std::string> tokens;
    std::vector<CMDLine *> allocatedCommands;

    std::string theLogin = std::string();
    char theHost[HOST_NAME_MAX]; // HOST_NAME_MAX is a predefined value
    //defined in limits.h
    bool run = true;
      
    // try to getlogin() //returns a pointer to the username when successful,
    //and NULL on failure
    if (getlogin() == NULL)
    {
        perror("Could not get login");
    }
    else
        theLogin = getlogin();

    // try getHostName // On success, zero is returned.
    //On error, -1 is returned,
    if (gethostname(theHost, HOST_NAME_MAX) == -1)
    {
        perror("Could not get hostname");
    }
    else
    {
        while (1)
        {
            try
            {
                std::cout << theLogin << "@" << theHost << "$ ";
                getline(std::cin, input);
                tokens = parsing.parse_string(input);
           
                CMDLine *toExecute = NULL;
                CMDTranslator translator;
                toExecute = translator.translate(tokens, allocatedCommands);

                if (toExecute)
                { 
                    toExecute->execute();
                }
                else
                {
                    std::cout << "to execute failed\n";
                }
            }
            catch (const std::string e)
            {
                std::cout << e;
            }

            while (!allocatedCommands.empty())
            {
                delete allocatedCommands.back();
                allocatedCommands.back() = NULL;
                allocatedCommands.pop_back();
            }

        } // end of while(1)
    }
}
