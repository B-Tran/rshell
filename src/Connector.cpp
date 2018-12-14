#include "Connector.h"
#include <cstdlib>

bool Connector::output_has_started = false;

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
}
void Connector::setLeft(CMDLine *left)
{
    this->left = left;
}
void Connector::setRight(CMDLine *right)
{
    this->right = right;
}
