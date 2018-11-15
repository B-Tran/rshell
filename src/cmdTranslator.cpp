#include "cmdTranslator.h"
#include "Exit.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"


CMDTranslator::CMDTranslator()
{
	connectors.push_back("&&");
	connectors.push_back("||");
	connectors.push_back(";");
//	comment = "#";
}

CMDTranslator::~CMDTranslator()
{
	
}

void CMDTranslator::remove_comment(std::vector<std::string> & tokenList)
{
//	std::vector<std::string>::iterator it;
//	it = std::find(tokenList.begin(),tokenList.end(),"#");
	
	//if # found in tokenList,erase the rest of the tokens
//	if(it != tokenList.end())
//	{
        tokenList.erase(tokenList.begin(),tokenList.end());
//	}
}

CMD * CMDTranslator::make_CMD(std::vector<std::string> & tokenList)
{
	std::vector<std::string> arguments;
	CMD * cmd = nullptr;

    //while the token list is not empty and is is not a connector, and is not a comment
    // then pushes the token into the argument list
    while(!tokenList.empty() && !is_Connector(tokenList.front()) && !(tokenList.front().find("#") == 0))
    {
        arguments.push_back(tokenList.front());
        tokenList.erase(tokenList.begin());
    }

    //if the argument is only exit
    if(arguments.front() == "exit")
    {
        cmd = new Exit();
    }
    //give the argumentlist to the newly created command object if it is not a exit command
    else
    {
        cmd = new CMD(arguments);
    }
	
	return cmd;
}

Connector * CMDTranslator::make_connector(std::vector<std::string> & tokenList)
{
    Connector * newConnector = nullptr;
    if(tokenList.front() == connectors.at(0))
    {
        newConnector = new And();
    }
    else if(tokenList.front() == connectors.at(1))
    {
        newConnector = new Or();
    }
    else
    {
        newConnector = new Semicolon();
    }

    tokenList.erase(tokenList.begin());
    return newConnector;
}


bool CMDTranslator::is_Connector(const std::string& item)
{
//    std::cout << "finding connector: " <<
//                 (std::find(connectors.begin(), connectors.end(), item) !=
//            connectors.end()) <<
//                 "\n";

    return (std::find(connectors.begin(), connectors.end(), item) !=
            connectors.end());
}

CMDLine * CMDTranslator::translate(std::vector<std::string> tokenList,
							std::vector<CMDLine*> & returnList)
{
    CMDLine * toReturn = nullptr;
    std::vector<CMDLine *> items;
    Connector * temp = nullptr;
	
//	bool isAConnector = false;			//checks if the last item was a
										//connector
										
	//while there are still tokens
	while(!tokenList.empty())
	{
//        std::cout << "front: " << tokenList.front() << "\n";
        //if there is less than 2 items to connect
        if(items.size() < 2)
        {
            //if it is a comment at the front
            //then erase all the tokens in the list
            if(tokenList.front().find("#") == 0)
            {
                remove_comment(tokenList);
            }
            //else if the token is a connector and the previous item is not a connector
            //then make a new connector item
            else if(temp == nullptr && is_Connector(tokenList.front()))
            {
                temp = make_connector(tokenList);
                returnList.push_back(temp);
            }
            //else if the token not a connector, then create a command
            else if(!is_Connector(tokenList.front()))
            {
                items.push_back(make_CMD(tokenList));
                returnList.push_back(items.back());
            }
            //else it is an invalid statement and should throw and error
            else
            {
//                std::cout << "in throw\n";
                throw "Error: invalid command statement\n";
            }
        }
        else
        {
            //settting the left and right children of the connector
            //and add it to the item list
            temp->setRight(items.back());
            items.pop_back();
            temp->setLeft(items.back());
            items.pop_back();
            items.push_back(temp);
            temp = nullptr;
        }
	}

    //if there is still a connector and one item left
    if(temp && (items.size() == 1))
    {
        temp->setLeft(items.back());
        items.pop_back();
        toReturn = temp;
    }
    //if there is still a connector and two itms left
    else if(temp && (items.size() == 2))
    {
        temp->setRight(items.back());
        items.pop_back();
        temp->setLeft(items.back());
        items.pop_back();
        toReturn = temp;
    }
    //if there was only a command
    else if(!temp && (items.size() == 1))
    {
        toReturn = items.back();
        items.pop_back();
    }
    //the line had nothing in the first place
    else
    {
        std::vector<std::string> emptyArg;
        toReturn = new CMD(emptyArg);
        returnList.push_back(toReturn);
    }

    return toReturn;
}								
