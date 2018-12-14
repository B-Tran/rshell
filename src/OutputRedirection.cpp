#include "OutputRedirection.h"
#include <iostream>

//bool OutputRedirection::has_started = false;

OutputRedirection::OutputRedirection()
{
//    OutputRedirection::has_started = false;
    Connector::output_has_started = false;
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
//    std::cout << "left " << left->is_a_output() << "has started: " <<
    if((left->is_a_output() || left->is_a_double_output()) && Connector::output_has_started)
    {
        open(right->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    }
    else if((left->is_a_output() || left->is_a_double_output()) && !Connector::output_has_started)
    {
        outputFile = open(right->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        Connector::output_has_started = true;
    }
    else if(!(left->is_a_output() && left->is_a_double_output()) && !Connector::output_has_started)
    {
        outputFile = open(right->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        Connector::output_has_started = false;
    }
    else
    {
        open(right->getFilename(),O_WRONLY| O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        Connector::output_has_started = false;
    }
    //	}
    return left->execute(inputFile,outputFile);

}

bool OutputRedirection::is_a_output()
{
    return true;
}
