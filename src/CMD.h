#ifndef CMD_H
#define CMD_H

#include <iostream>
#include "CMDLine.h"
#include "unistd.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <string>
#include <cstring>

/* Command composite derived class */
class CMD : public CMDLine
{
  public:
    CMD();
    CMD(CMDLine *commandArg);
    CMD(std::vector<std::string> theArugments);
    ~CMD();
    void addArguments(std::vector<std::string> theArugments);
    bool execute(int inputFile, int outputFile);

  private:
    CMDLine *commandArg;
    char **argumentList;
    int argumentCount;
};

#endif
