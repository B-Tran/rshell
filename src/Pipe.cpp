#include "Pipe.h"

 Pipe::Pipe()
 {
 
 }
Pipe::Pipe(CMDLine *left, CMDLine *right)
{
  
}
Pipe::~Pipe()
{

}
bool Pipe::execute()
{
     //NOTES: pfd[0] is set up for reading, fd[1] is set up for writing
     //To create a simple pipe with C, we make use of the pipe() system call. It takes a single argument, 
     //which is an array of two integers, and if successful, the array will contain two new file 
     //descriptors to be used for the pipeline. After creating a pipe, the process typically spawns a 
     //new process (remember the child inherits open file descriptors).
 
  

    //pipe() creates a pair of file descriptors, pointing to a pipe inode, 
    //and places them in the 
    //On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
    //array pointed to by filedes. filedes[0] is for reading, filedes[1] is for writing.


   int pfd[2];  
   pid_t   childpid; // 
  
 // pfd[0] 
 

}