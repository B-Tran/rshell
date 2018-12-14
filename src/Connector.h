#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "CMDLine.h"

/*  Composite Class */
class Connector : public CMDLine
{
protected:
	CMDLine *left;
	CMDLine *right;
    static bool output_has_started;

public:
	Connector();
	Connector(CMDLine *left, CMDLine *right);
	~Connector();
	virtual bool execute(int inputFile, int outputFile) = 0;
	void setLeft(CMDLine *left);
	void setRight(CMDLine *right);
	virtual char* getFilename() = 0;
};

#endif
