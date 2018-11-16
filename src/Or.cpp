#include "Or.h"
#include <string>

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
//    delete left;
//    left = nullptr;
//    delete right;
//    right = nullptr;

}
bool Or::execute()
{
    if(!right)
    {
        const std::string error = "Error : -bash: syntax error near unexpected token || \n";
        throw error;
    }
    return (left->execute() || right->execute());
}
