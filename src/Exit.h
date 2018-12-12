#ifndef EXIT_H
#define EXIT_H

#include "CMD.h"
#include <cstdlib>

class Exit : public CMD
{
public:
	Exit();
	~Exit();
	bool execute(int inputFile, int outputFile);
};

#endif
