#include "Semicolon.h"

Semicolon::Semicolon()
{
     left = nullptr;
    right = nullptr;
}
Semicolon::Semicolon(CMDLine *left, CMDLine *right) : Connector(left, right)
{
}
Semicolon::~Semicolon()
{
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}
bool Semicolon::execute()
{ 
    left->execute();
    if(right){ return right->execute(); }
}
