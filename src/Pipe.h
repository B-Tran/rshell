#ifndef PIPE_H
#define PIPE_H

#include "Connector.h"


class Pipe: public Connector
{
  public:
  Pipe();
  ~Pipe();
  bool execute();
  private:
    
 
};


#endif 