#include "CMDLine.h" // Base class
#include "CMD.h"
#include "unistd.h"
#include "stringParser.h"
#include <sys/types.h>
#include <sys/wait.h> // wait
#include "limits.h"   // HOST_Name_MAX
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
    std::string theLogin = std::string();
    char theHost[HOST_NAME_MAX]; // HOST_NAME_MAX is a predefined value defined in limits.h
    bool run = true;

    // try to getlogin() //returns a pointer to the username when successful, and NULL on failure
    if (getlogin() == NULL)
    {
        perror("Could not get login");
    }
    else
        theLogin = getlogin();

    // try getHostName // On success, zero is returned.  On error, -1 is returned,
    if (gethostname(theHost, HOST_NAME_MAX) == -1)
    {
        perror("Could not get hostname");
    }

    CMD *theTest = new CMD();

    while (run)
    {
        if (getlogin() != NULL)
        {
            std::cout << theLogin << "@" << theHost;
        }

        std::cout << "$: ";
        std::getline(std::cin, input);
        tokens = parsing.parse_string(input);
        theTest->addArguments(tokens);
        run = theTest->execute();

    } // end of while loop

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        std::cout << tokens.at(i) << "\n";
    }
}
