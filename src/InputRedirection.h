#ifndef INPUTREDIRECTION_H
#define INPUTREDIRECTION_H

#include "Connector.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <fstream>



class InputRedirection : public Connector
{
  public:
  InputRedirection();
  InputRedirection(CMDLine* left, CMDLine* right);
  ~InputRedirection();
  bool execute(int inputFile, int outputFile);
  char* getFilename();
  bool is_a_input();
};


#endif


