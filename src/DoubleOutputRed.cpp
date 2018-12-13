#include "Connector.h"
#include "DoubleOutputRed.h"
#include <iostream>
DoubleOutputRed::DoubleOutputRed()
{

}
DoubleOutputRed::DoubleOutputRed(CMDLine* left, CMDLine* right): Connector(left, right)
{

}
DoubleOutputRed::~DoubleOutputRed()
{

}
char* DoubleOutputRed::getFilename()
{
 return nullptr;
}
bool DoubleOutputRed::execute(int inputFile, int outputFile)
{
    	if(right->getFilename() == nullptr)
	{
		std::cout << "Error: expected filename\n";
		return false;
	}

    outputFile = open(right->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    return left->execute(inputFile,outputFile);
}
