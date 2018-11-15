#include <iostream>
#include <vector>
#include "stringParser.h"
#include "CMDLine.h" // Base class
#include "CMD.h" 
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>  // wait  
#include <limits.h> // HOST_Name_MAX


using namespace std;

int main()
{
    vector<string> dList;
    vector<string> dIList;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    StringParser parsing(dList,dIList);
    string input;
    vector<string> tokens;
     string theLogin = string();
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
            cout << theLogin << "@" << theHost;
        }

        cout << "$: ";
        getline(cin, input);
        tokens = parsing.parse_string(input);
        theTest->addArguments(tokens);
           run = theTest->execute();

    } // end of while loop


    for(size_t i = 0 ; i < tokens.size(); ++i)
    {
        cout << tokens.at(i) << "\n";
    }






  return 0;
}
