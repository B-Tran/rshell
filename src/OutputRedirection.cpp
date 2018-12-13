#include "OutputRedirection.h"
#include <iostream>

OutputRedirection::OutputRedirection()
{

}
OutputRedirection::OutputRedirection(CMDLine* left, CMDLine* right): Connector(left,right)
{

}
OutputRedirection::~OutputRedirection()
{

}
char* OutputRedirection::getFilename()
{
    return nullptr;
}
bool OutputRedirection::execute(int inputFile, int outputFile)
{
    if(right->getFilename() == nullptr)
    {
        std::cout << "Error: Expected a file\n";
        return false;
    }
    //	else
    //	{
    outputFile = open(right->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    //	}
    return left->execute(inputFile,outputFile);

}
