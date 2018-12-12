#include "Connector.h"
#include "DoubleOutputRed.h"

DoubleOutputRed::DoubleOutputRed()
{

}
DoubleOutputRed::DoubleOutputRed(CMDLine* left, CMDLine* right): Connector(left, right)
{

}
DoubleOutputRed::~DoubleOutputRed()
{

}
bool DoubleOutputRed::execute(int inputFile, int outputFile)
{

}