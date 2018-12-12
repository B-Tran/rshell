#include "InputRedirection.h"

InputRedirection::InputRedirection()
{

}
InputRedirection::InputRedirection(CMDLine* left, CMDLine* right) : Connector(left,right)
{

}
InputRedirection::~InputRedirection()
{

}
char* InputRedirection::getFilename()
{
 return nullptr;
}
bool InputRedirection::execute(int inputFile, int outputFile)
{
    inputFile = open( right->getFilename() ,O_RDONLY);
     return left->execute(inputFile,outputFile);

}