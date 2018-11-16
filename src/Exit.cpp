#include "Exit.h"

Exit::Exit()
{
}
Exit::~Exit()
{
}
bool Exit::execute()
{
//    std::cout << "EXITING!\n";
    exit(0); 
}
