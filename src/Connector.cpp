#include "Connector.h"


Connector::Connector()
{
    left = nullptr;
    right = nullptr;
}
Connector::Connector(CMDLine *left, CMDLine *right)
{
    this->left = left;
    this->right = right;
}
Connector::~Connector()
{
//    delete left;
//    left = nullptr;
//    delete right;
//    right = nullptr;
}
void Connector::setLeft(CMDLine *left)
{
    this->left = left;
}
void Connector::setRight(CMDLine *right)
{
    this->right = right;
}
bool Connector::execute()
{   
}
