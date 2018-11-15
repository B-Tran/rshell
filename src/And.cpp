#include "And.h"

And::And() 
{
   left = nullptr;
    right = nullptr;
}
And::And(CMDLine *left, CMDLine *right) : Connector(left, right)
{
}
And::~And()
{
  delete left;
  left = nullptr;
  delete right;
  right = nullptr;
}
bool And::execute()
{
  return (left->execute() && right->execute());
}

		
