#ifndef OR_H
#define OR_H 

#include "Connector.h"


class Or : public Connector
{
 public:
 Or();
 Or(CMDLine* left,CMDLine* right);
 ~Or();
 bool execute();
};


#endif