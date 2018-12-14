#ifndef CMDLINE_H
#define CMDLINE_H

/* Base Class */
class CMDLine
{
public:
  CMDLine();
  virtual ~CMDLine() = 0;
  virtual bool execute(int inputFile, int outputFile) = 0;
  virtual char* getFilename() = 0;
  virtual bool is_a_output();
  virtual bool is_a_double_output();
  virtual bool is_a_input();
};

#endif
