#ifndef AND_H
#define AND_H

#include "Connector.h"

class And : public Connector
{
public:
  And();
  And(CMDLine *left, CMDLine *right);
  ~And();
  bool execute(int inputFile, int outputFile);
};

#endif
