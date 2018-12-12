#ifndef PIPE_H
#define PIPE_H

#include "Connector.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#include <iostream> 

class Pipe: public Connector
{
  public:
  Pipe();
  Pipe(CMDLine *left, CMDLine *right);
  ~Pipe();
  bool execute(int inputFile, int outputFile);
  private:
    
 
};


#endif 