#ifndef OUTPUTREDIRECTION_H
#define OUTPUTREDIRECTION_H

#include "Connector.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class OutputRedirection : public Connector
{
  private:
//  static bool has_started;
  public:
  OutputRedirection();
  OutputRedirection(CMDLine* left, CMDLine* right);
  ~OutputRedirection();
  bool execute(int inputFile, int outputFile);
  char* getFilename();
  bool is_a_output();
};


#endif


