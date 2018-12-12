#ifndef DOUBLEOUTPUTRED_H
#define DOUBLEOUTPUTRED_H


#include "Connector.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class DoubleOutputRed : public Connector
{
  public:
   DoubleOutputRed();
   DoubleOutputRed(CMDLine* left, CMDLine* right);
  ~DoubleOutputRed();
  bool execute(int inputFile, int outputFile);
   
};


#endif