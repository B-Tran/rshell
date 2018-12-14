#ifndef DOUBLEOUTPUTRED_H
#define DOUBLEOUTPUTRED_H


#include "Connector.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class DoubleOutputRed : public Connector
{
  private:
//  static bool has_started;
  public:
   DoubleOutputRed();
   DoubleOutputRed(CMDLine* left, CMDLine* right);
  ~DoubleOutputRed();
  bool execute(int inputFile, int outputFile);
  char* getFilename();
  bool is_a_double_output();
};


#endif
