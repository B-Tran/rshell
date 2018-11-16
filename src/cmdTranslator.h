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
// class CMDLine
// {
// 	public:
// 			CMDLine(){}
// 			~CMDLine(){}
// 			virtual void execute() = 0;
// };

// class CMD : public CMDLine
// {
// 	private:
// 			std::vector<std::string> arglist;
// 	public:
// 			CMD(){}
// 			CMD(std::vector<std::string> argList)
// 			{
// 				this->arglist = argList;
// 			}
// 			~CMD(){}
// 			void add_arg(std::vector<std::string> argList)
// 			{
// 				this->arglist = argList;
// 			}
// 			void execute()
//             {
// //                std::cout << "in cmd\n";
// 				for(size_t i = 0; i < arglist.size(); ++i)
// 				{
// 					std::cout << arglist.at(i) << " ";
// 				}
// 			}
// };

// class Connector : public CMDLine
// {
//     protected:
// 			CMDLine * left;
// 			CMDLine * right;
// 	public:
// 			Connector()
// 			{
// 				left = nullptr;
// 				right = nullptr;
// 			}
// 			Connector(CMDLine * left, CMDLine * right)
// 			{
// 				this->left = left;
// 				this->right = right;
// 			}
// 			~Connector(){}
// 			void set_left(CMDLine * left)
// 			{
// 				this->left = left;
// 			}
// 			void set_right(CMDLine * right)
// 			{
// 				this->right = right;
// 			}
// 			virtual void execute() = 0;
// };


// class And : public Connector
// {
// 	public:
// 			And() : Connector(){}
// 			And(CMDLine * left, CMDLine * right) : 
// 			Connector(left,right)
// 			{}
// 			~And(){}
// 			void execute()
// 			{
//                 if(this->left)
// 				{
// 					left->execute();
// 				}
// 				else
// 				{
// 					std::cout << "Err ";
// 				}
// 				std::cout << "&& ";
// 				if(right)
// 				{
// 					right->execute();
// 				}
// 				else
// 				{
// 					std::cout << "Err ";
// 				}
// 			}
// };

// class Or : public Connector
// {
// 	public:
// 			Or() : Connector(){}
// 			Or(CMDLine * left, CMDLine * right) : 
// 			Connector(left,right)
// 			{}
// 			~Or(){}
// 			void execute()
// 			{
// 				if(left)
// 				{
// 					left->execute();
// 				}
// 				else
// 				{
// 					std::cout << "Err ";
// 				}
// 				std::cout << "|| ";
// 				if(right)
// 				{
// 					right->execute();
// 				}
// 				else
// 				{
// 					std::cout << "Err ";
// 				}
// 			}
	
// };

// class Semicolon : public Connector
// {
// 	public:
// 			Semicolon() : Connector(){}
// 			Semicolon(CMDLine * left, CMDLine * right) : 
// 			Connector(left,right)
// 			{}
// 			~Semicolon(){}
// 			void execute()
// 			{
// 				if(left)
// 				{
// 					left->execute();
// 				}
// 				else
// 				{
// 					std::cout << "Err ";
// 				}
// 				std::cout << "; ";
// 				if(right)
// 				{
//                     right->execute();
// 				}
// 			}
// };

// class Exit : public CMD
// {
//     public:
//             Exit(){}
//             ~Exit(){}
//             void execute()
//             {
//                 std::cout << "EXITING!\n";
//             }
// };

// class CMDTranslator
// {
// 	private:
// 			std::vector<std::string> connectors;	//connectors list
// //			std::string comment;					//comment list
			
// 			//removes the tokens that are after a # sign
// 			void remove_comment(std::vector<std::string> & tokenList);
// 			//makes a CMD object
//             CMD *make_CMD(std::vector<std::string> & tokenList);
//             //making the connector object
//             Connector * make_connector(std::vector<std::string> & tokenList);
// 			//checks if the token is a connector
// 			bool is_Connector(const std::string& item);
// 	public:
// 			CMDTranslator();
// 			~CMDTranslator();
			
// 			//translates the token list into command objects
// 			//gives back a CMDLine to execute
// 			//takes in a vector of CMDLine to deallocate at a later time
// 			//returns a nullptr if
// 			CMDLine * translate(std::vector<std::string> tokenList,
// 							std::vector<CMDLine*> & returnList);
// };

#endif
