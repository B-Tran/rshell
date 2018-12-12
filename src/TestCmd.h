#ifndef TESTCMD_H
#define TESTCMD_H


#include "CMDLine.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


class TestCmd: public CMDLine
{
  public:
     TestCmd();
     TestCmd(std::vector<std::string> arugmentListVector);
     ~TestCmd();
     bool execute(int inputFile, int outputFile);
     char* getFilename();

  private:
  std::vector<CMDLine*> commandLine;
  std::vector<std::string> arugmentListVector;

};

#endif