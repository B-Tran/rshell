#include "CMD.h"
#include <cstdlib>

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
   
   // Create a child process of datatype of process id           
   pid_t pid = fork();  

if(pid == 0)
 {
    if(execvp(argumentList[0],argumentList) == -1)
    {
       theExecuted = false;
       perror("Command not found");
    }
 }
 else if(pid == -1)   // if fork fails 
   {
       perror("problem forking"); // run error checking
       theExecuted = false;
   }
else if(pid > 0) 
   {  // parent process id 
      int status;
      if(waitpid(pid,&status,0) == -1)
      {
           perror("wait");
           theExecuted = false;
       }
   } 
    

    return theExecuted;
}
// 
