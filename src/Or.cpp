#include "Or.h"
#include <string>
#include <cstdlib>

Or::Or()
{
    left = NULL;
    right = NULL;
}
Or::Or(CMDLine *left, CMDLine *right) : Connector(left, right)
{
}
Or::~Or()
{
}
bool Or::execute()
{
    if (!right) // if there is no right base pointer 
    {
        const std::string error = "Error : -bash: syntax error near "
                                  "unexpected token || \n";
        throw error;
    }
    return (left->execute() || right->execute());
}
