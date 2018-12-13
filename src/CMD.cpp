#include "CMD.h"
#include <cstdlib>
#include <cerrno>
#include <stdlib.h>

CMD::CMD()
{
    argumentList = nullptr;
    argumentCount = 0;
}
CMD::CMD(CMDLine *commandArg)
{
    this->commandArg = commandArg;
}
CMD::CMD(std::vector<std::string> theArugments)
{
    argumentList = nullptr;
    argumentCount = 0;
    this->addArguments(theArugments);
}
CMD::~CMD()
{

    for (int i = 0; i < argumentCount; i++)
    {
        delete[] argumentList[i];
    }
    delete[] argumentList;

    argumentCount = 0;
}
void CMD::addArguments(std::vector<std::string> theArugments)
{
    //if there was a agrument list that was already created
    //delete the current argument list
    if (argumentList)
    {
        for (int i = 0; i < argumentCount; i++)
        {
            delete[] argumentList[i];
        }
        delete[] argumentList;
        argumentCount = 0;
    }

    argumentList = new char *[theArugments.size() + 1];
    argumentCount = theArugments.size() + 1;

    for (size_t i = 0; i < theArugments.size(); i++)
    {
        argumentList[i] = new char[theArugments.at(i).size() + 1];
        strcpy(argumentList[i], theArugments.at(i).c_str());
    }
    // Indicates the end of arguments
    argumentList[theArugments.size()] = nullptr;

}
char* CMD::getFilename()
{
    return argumentList[0];
}
// int CMD::getFilenameNumber()
// {
//   return 0;
// }

bool CMD::execute(int inputFile, int outputFile)
{  

    bool theExecuted = true;


    //  std::cout << " CMD in : " << inputFile << std::endl;
    //    std::cout << "CMD out : " << outputFile << std::endl;

    // Create a child process of datatype of process id
    pid_t pid = fork();

    //   std::cout << "here"  << std::endl;
    int status = 0;
    if (pid == 0)
    {

        if(dup2(inputFile,0) == -1)
        {
            perror("dup2");
            _exit(69);

        }
        if(dup2(outputFile,1) == -1)
        {
            perror("dup2");
            _exit(69);

        }

        if (execvp(argumentList[0], argumentList) == -1)
        {
            perror("Command not found");
            //kill the function if the child fails
            _exit(69);
        }

    }
    else if (pid == -1) // if fork fails
    {
        perror("problem forking"); // run error checking
        return false;
    }

    else
    {     // parent process id
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("wait");
        }
    }
    if (WEXITSTATUS(status) != 0)
    {
        theExecuted = false;
    }

    return theExecuted;
}
