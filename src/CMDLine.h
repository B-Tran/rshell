#ifndef CMDLINE_H
#define CMDLINE_H

/* Base Class */
class CMDLine
{
public:
  CMDLine();
  virtual ~CMDLine() = 0;
  virtual bool execute(int inputFile, int outputFile) = 0;
};

#endif
