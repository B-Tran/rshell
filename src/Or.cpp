#include "Or.h"

Or::Or()
{
    left = nullptr;
    right = nullptr;
}
Or::Or(CMDLine *left, CMDLine *right) : Connector(left, right)
{
}
Or::~Or()
{
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;

}
bool Or::execute()
{   
    return (left->execute() || right->execute());
}