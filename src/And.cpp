#include "And.h"
#include <string>
#include <cstdlib>

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
}
bool And::execute()
{
    if (!right) // if there no right base pointer
    {
        const std::string error = "Error : -bash: syntax error "
                                  "near unexpected token && \n";
        throw error;
    }
    return (left->execute() && right->execute());
}
