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
#include "TestCmd.h"
#include <map>

class CMDTranslator
{
  private:
  std::map<std::string,int> precedenceMap;
	std::vector<std::string> connectors; //connectors list
	//removes the tokens that are after a # sign
	void remove_comment(std::vector<std::string> &tokenList);
	//removes the literals from a token
	void remove_literals(std::string &token);
	//makes a CMD object
	CMD *make_CMD(std::vector<std::string> &tokenList);
	//making the connector object
//	Connector *make_connector(std::vector<std::string> &tokenList);
	//checks if the token is a connector
	bool is_Connector(const std::string &item);

  //makes a test object
  //needs to change later to return a test object
  TestCmd *make_Test(std::vector<std::string> &tokenList);
  //checks if the token is a beginning parentheses
  bool is_begin_para(const std::string & token);
  //checks if the token is an ending parentheses
  bool is_end_para(const std::string & token);
  //check if operand is valid
  bool is_valid_operand(const bool & isStart,
                        const bool & isConnector,
                        const bool & isBeginPara);
  //check if operator is is valid
  bool is_valid_operator(const bool & isStart,
                         const bool & isConnector,
                         const bool & isBeginPara);
  //check if begining parentheses is valid
  bool is_valid_begin_para(const bool & isStart,
                           const bool & isConnector,
                           const bool & isBeginPara);
  //check if ending parentheses is valid
  bool is_valid_end_para(const bool & isStart, const bool & isConnector,
                         const bool & isBeginPara);
  //adding an operand object to the output(RPN)
  //gets the infixed input
  //gets the output
  //gets the items made
  void add_operand(std::vector<std::string> & infix,
                   std::vector<CMDLine *> & output,
                   std::vector<CMDLine *> & toReturn);
  //adding an operator object to the operatorStack if possible from the input
  void add_operator(std::vector<std::string> & infix,
                    std::vector<CMDLine *> & output,
                    std::vector<CMDLine *> & toReturn,
                    std::vector<std::string> & operatorStack);
  //adding a beginning parentheses object to the operatorStack if possible
  void add_begin_para(std::vector<std::string> & infix,
                      std::vector<std::string> & operatorStack);
  //adding and ending parentheses object to the operatorStack if possible
  void add_end_para(std::vector<std::string> & infix,
                    std::vector<CMDLine *> & output,
                    std::vector<CMDLine *> & toReturn,
                    std::vector<std::string> & operatorStack);
  //makes a connector object from the token given
  Connector *make_connector(const std::string & token);
  public:
	CMDTranslator();

	~CMDTranslator();

	//translates the token list into command objects
	//gives back a CMDLine to execute
	//takes in a vector of CMDLine to deallocate at a later time
	//returns a nullptr if
	CMDLine *translate(std::vector<std::string> tokenList,
					   std::vector<CMDLine *> &returnList);

};

#endif
