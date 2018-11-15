#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"


class Semicolon: public Connector
{
  public:
  Semicolon();
  Semicolon(CMDLine* left, CMDLine* right);
  ~Semicolon();
  bool execute();
};


#endif 
