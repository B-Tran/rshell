#include "Semicolon.h"
#include <cstdlib>
Semicolon::Semicolon()
{
     left = NULL;
    right = NULL;
}
Semicolon::Semicolon(CMDLine *left, CMDLine *right) : Connector(left, right)
{
}
Semicolon::~Semicolon()
{
    
}
bool Semicolon::execute()
{ 
    left->execute();
    if(right)
    { 
        return right->execute(); 
    }
    else
    {
        return true;
    }
}
