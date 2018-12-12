#include "OutputRedirection.h"

OutputRedirection::OutputRedirection()
{

}
OutputRedirection::OutputRedirection(CMDLine* left, CMDLine* right): Connector(left,right)
{

}
OutputRedirection::~OutputRedirection()
{

}
bool OutputRedirectionexecute(int inputFile, int outputFile)
{

    //    outputFile = open(,O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    //    return;

}