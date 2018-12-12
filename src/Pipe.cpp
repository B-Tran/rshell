#include "Pipe.h"

 Pipe::Pipe()
 {
     std::cout << "pipe constructor\n";
 }
Pipe::Pipe(CMDLine *left, CMDLine *right) : Connector(left,right)
{
  
}
Pipe::~Pipe()
{

}
bool Pipe::execute(int inputFile, int outputFile)
{
     //NOTES: pfd[0] is set up for reading, fd[1] is set up for writing
     //To create a simple pipe with C, we make use of the pipe() system call. It takes a single argument, 
     //which is an array of two integers, and if successful, the array will contain two new file 
     //descriptors to be used for the pipeline. After creating a pipe, the process typically spawns a 
     //new process (remember the child inherits open file descriptors).
 

    
    // Integer 0 : Stdin // file descriptor // Ex. cin >> name;
    // The system writes the string to file descriptor std in
    // Integer 1 : Stdout // file descriptor // Ex. cout << "hello";
    // The system places the hello to the stdout then its place to the buffer then display to the screen
    // Integer 2 : stderr



//Redirection is a feature in Linux such that when executing a command, you can change the standard input/output devices.
// The basic workflow of any Linux command is that it takes an input and give an output.

//The standard input (stdin) device is the keyboard.
//The standard output (stdout) device is the screen.


    //pipe() creates a pair of file descriptors, pointing to a pipe inode, 
    //On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
    //array pointed to by filedes. filedes[0] is for reading, filedes[1] is for writing.


   int pfd[2];  
   pid_t childpid;  

   std::cout << " in : " << inputFile << std::endl;
    std::cout << " out : " << outputFile << std::endl;

    if(pipe(pfd) == -1) 
    {
        perror("Pipe");
        return false;
    }


    if(!left->execute(inputFile,pfd[1])) 
    {
        return false;
    }

    close(pfd[1]);

    if(!right->execute(pfd[0],outputFile)) 
    {
        return false;
    }
    close(pfd[0]);

    return true;

  
 

}