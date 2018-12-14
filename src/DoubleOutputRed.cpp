#include "Connector.h"
#include "DoubleOutputRed.h"
#include <iostream>

//bool DoubleOutputRed::has_started = false;

DoubleOutputRed::DoubleOutputRed()
{
//    DoubleOutputRed::has_started = false;
    Connector::output_has_started = false;
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

    if((left->is_a_output() || left->is_a_double_output()) && Connector::output_has_started)
    {
        open(right->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    }
    else if((left->is_a_output() || left->is_a_double_output()) && !Connector::output_has_started)
    {
        outputFile = open(right->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        Connector::output_has_started = true;
    }
    else if(!(left->is_a_output() && left->is_a_double_output()) && !Connector::output_has_started)
    {
        outputFile = open(right->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        Connector::output_has_started = false;
    }
    else
    {
        open(right->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        Connector::output_has_started = false;
    }
//    outputFile = open(right->getFilename(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    return left->execute(inputFile,outputFile);
}
bool DoubleOutputRed::is_a_double_output()
{
    return true;
}
