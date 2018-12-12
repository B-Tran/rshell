#include "Exit.h"

Exit::Exit()
{
}
Exit::~Exit()
{
}
char* Exit::getFilename()
{
 return nullptr;
}
bool Exit::execute(int inputFile, int outputFile)
{
    exit(0);
}
