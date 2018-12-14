#include "Or.h"
#include <string>
#include <cstdlib>

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
}
char* Or::getFilename()
{
    return nullptr;
}
bool Or::execute(int inputFile, int outputFile)
{
    if (!right) // if there is no right base pointer
    {
        const std::string error = "Error : -bash: syntax error near "
                                  "unexpected token || \n";
        throw error;
    }
    return (left->execute(inputFile,outputFile) || right->execute(inputFile,outputFile));
}
