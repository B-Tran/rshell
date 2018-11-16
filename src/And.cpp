#include "And.h"
#include <string>

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
//  delete left;
//  left = nullptr;
//  delete right;
//  right = nullptr;
}
bool And::execute()
{
    if(!right)
    {
        const std::string error = "Error : -bash: syntax error near unexpected token && \n";
        throw error;
    }
    return (left->execute() && right->execute());
}

		
