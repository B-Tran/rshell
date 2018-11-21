#include "CMD.h"
#include <cstdlib>
#include <cerrno>
#include <stdlib.h>

CMD::CMD()
{
   argumentList = NULL;
   argumentCount = 0;
}

CMD::CMD(CMDLine *commandArg)
{
    this->commandArg = commandArg;
}
 CMD::CMD(std::vector<std::string>theArugments)
 {
    argumentList = NULL;
    argumentCount = 0;
    this->addArguments(theArugments);
 }
CMD::~CMD()
{

    for (int i=0; i < argumentCount ; i++)
    {
        delete [] argumentList[i];
    }
    delete [] argumentList;

    argumentCount = 0;
}
void CMD::addArguments(std::vector<std::string> theArugments)
{
   //if there was a agrument list that was already created
   //delete the current argumetn list
   if(argumentList)
   {
//      std::cout << "in here!\n";
      for (int i=0; i < argumentCount ; i++)
      {
         delete [] argumentList[i];
      }
      delete [] argumentList;
      argumentCount = 0;
   }

    argumentList = new char*[theArugments.size()+1];
            argumentCount = theArugments.size()+1;

//    std::cout << "Argument size: " << theArugments.size() << std::endl;

    for(size_t i = 0; i < theArugments.size(); i++)
    {
       argumentList[i] = new char [theArugments.at(i).size()+1];
       strcpy(argumentList[i],theArugments.at(i).c_str());
    }
    argumentList[theArugments.size()] = NULL; // Indicates the end of arguments
    
  

// for(int i = 0; i < theArugments.size(); i++)
// {
//     std:: cout << "char [" << i << "] : ";
//     std::cout <<  argumentList[i] << std::endl;
// }
   
}
bool CMD::execute()
{   
//          std::cout << "CMD::execute function" << std::endl;

    bool theExecuted = true;
//    clear the errno value
//   errno = 0;
   // Create a child process of datatype of process id           
   pid_t pid = fork();  
   int status = 0;
   int old_errno = errno;
if(pid == 0)
 {
    // std::cout << "Child pid:" << getpid() << std::endl;
    if(execvp(argumentList[0],argumentList) == -1)
    {
//       std::cout << "kiilling the process\n";
       perror("Command not found");
       //kill the function if the child fails
       _exit(errno);
//       theExecuted = false;
//       std::cout << "killed the child process\n";
//       return false;
    }
 }
else if(pid == -1)   // if fork fails 
   {
       perror("problem forking"); // run error checking
      return false;
   }

//else if(pid > 0) 
else
   {  // parent process id 
  // std::cout << "Parent pid:" << getpid() << std::endl;
      if(waitpid(pid,&status,0) == -1)
      {
           perror("wait");
//           return false;
      }
   } 

//    std::cout << "errno value: " << errno << "\n";
//    std::cout << "status: " << status << "\n";
//    if(WIFEXITED(status))
//    {
//	    std::cout << "exit success\n";
//    }
//    else
//    {
//	    std::cout << "exit failed\n";
//    }
//    std::cout << "at end of process: "<< theExecuted <<" \n";
//    return theExecuted;
//    return (errno == 0);
    theExecuted = (errno == 0);
    errno = old_errno;
//    std::cout << "theExecuted: " << theExecuted << "\n";
    return theExecuted;
}
// 
