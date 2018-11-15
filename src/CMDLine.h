#ifndef CMDLINE_H
#define CMDLINE_H


/* Base Class */
class CMDLine
{
  public:
    CMDLine() {}
    ~CMDLine() {}
    virtual bool execute() = 0;
};

#endif
