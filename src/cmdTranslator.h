#ifndef CMD_TRANSLATOR_H
#define CMD_TRANSLATOR_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "CMDLine.h"
#include "CMD.h"
#include "Connector.h"

class CMDTranslator
{
	private:
			std::vector<std::string> connectors;	//connectors list
//			std::string comment;					//comment list
			
			//removes the tokens that are after a # sign
			void remove_comment(std::vector<std::string> & tokenList);
            //removes the literals from a token
            void remove_literals(std::string & token);
            //makes a CMD object
            CMD *make_CMD(std::vector<std::string> & tokenList);
            //making the connector object
            Connector * make_connector(std::vector<std::string> & tokenList);
			//checks if the token is a connector
			bool is_Connector(const std::string& item);
	public:
			CMDTranslator();
			~CMDTranslator();
			
			//translates the token list into command objects
			//gives back a CMDLine to execute
			//takes in a vector of CMDLine to deallocate at a later time
			//returns a nullptr if
			CMDLine * translate(std::vector<std::string> tokenList,
							std::vector<CMDLine*> & returnList);
};


#endif
