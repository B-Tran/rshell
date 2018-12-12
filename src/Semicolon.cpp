#include "Semicolon.h"
#include <cstdlib>
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
}
char* Semicolon::getFilename()
{
 return nullptr;
}
bool Semicolon::execute(int inputFile, int outputFile)
{
    left->execute(inputFile,outputFile); 
    if (right)  // if the right base pointer exist
    {
        return right->execute(inputFile,outputFile);
    }
    else
    {
        return true;
    }
}
