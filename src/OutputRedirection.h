#ifndef OUTPUTREDIRECTION_H
#define OUTPUTREDIRECTION_H

#include "Connector.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


class OutputRedirection : public Connector
{
  public:
  OutputRedirection();
  OutputRedirection(CMDLine* left, CMDLine* right);
  ~OutputRedirection();
  bool execute(int inputFile, int outputFile);
   
};


#endif


