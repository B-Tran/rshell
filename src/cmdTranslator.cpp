#include "cmdTranslator.h"
#include "Exit.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Pipe.h"
#include "InputRedirection.h"
#include "OutputRedirection.h"
#include "DoubleOutputRed.h"
#include <cstdlib>
#include <algorithm>

CMDTranslator::CMDTranslator()
{
    connectors.push_back("&&");
    connectors.push_back("||");
    connectors.push_back(";");
    connectors.push_back("|");
    connectors.push_back("<");
    connectors.push_back(">");
    connectors.push_back(">>");

    precedenceMap["&&"] = 3;
    precedenceMap["||"] = 3;
    precedenceMap[";"] = 3;
    precedenceMap["|"] = 4;
    precedenceMap["<"] = 4;
    precedenceMap[">"] = 4;
    precedenceMap[">>"] = 4;
}

CMDTranslator::~CMDTranslator()
{
}

void CMDTranslator::remove_comment(std::vector<std::string> &tokenList)
{
    tokenList.erase(tokenList.begin(), tokenList.end());
}

void ::CMDTranslator::remove_literals(std::string &token)
{
    bool done = false;
    size_t pos;
    while (!done)
    {
        if ((pos = token.find("\"")) < token.size())
        {
            token.erase(pos, 1);
        }
        else if ((pos = token.find("\'")) < token.size())
        {
            token.erase(pos, 1);
        }
        else
        {
            done = true;
        }
    }
}

CMD *CMDTranslator::make_CMD(std::vector<std::string> &tokenList)
{
    std::vector<std::string> arguments;
    CMD *cmd = nullptr;

    //while the token list is not empty and is is not a connector,
    //and is not a comment
    // then pushes the token into the argument list
    while (!tokenList.empty() && !is_Connector(tokenList.front())
           && !(tokenList.front().find("#") == 0) &&
           !is_begin_para(tokenList.front()) && !is_end_para(tokenList.front()))
    {
        if(tokenList.front() == "[ " || tokenList.front() == " ]")
        {
            tokenList.front().erase(tokenList.front().find(" "),1);
        }
        remove_literals(tokenList.front());
        arguments.push_back(tokenList.front());
        tokenList.erase(tokenList.begin());
    }

    //if the argument is only exit
    if (arguments.front() == "exit")
    {
        cmd = new Exit();
    }
    //give the argumentlist to the newly created command object if
    //it is not a exit command
    else
    {
        cmd = new CMD(arguments);
    }

    return cmd;
}

// Connector *CMDTranslator::make_connector(std::vector<std::string> &tokenList)
// {
//     Connector *newConnector = nullptr;
//     if (tokenList.front() == connectors.at(0))
//     {
//         std::cout << "making and!\n";
//         newConnector = new And();
//     }
//     else if (tokenList.front() == connectors.at(1))
//     {
//         std::cout << "making or!\n";
//         newConnector = new Or();
//     }
//     // else if (tokenList.front() == connectors.at(3))
//     // {
//     //     std::cout << "making pipe!\n";
//     //     newConnector = new Pipe();
//     // }
//     else
//     {
//         std::cout << "making semicolon\n";
//         newConnector = new Semicolon();
//     }

//     tokenList.erase(tokenList.begin());
//     return newConnector;
// }

bool CMDTranslator::is_Connector(const std::string &item)
{
    return (std::find(connectors.begin(), connectors.end(), item) !=
            connectors.end());
}

TestCmd *CMDTranslator::make_Test(std::vector<std::string> &tokenList)
{
    TestCmd * testvar = nullptr;
    std::vector<std::string> argumentList;
    //if the first token is the word test
    if(tokenList.at(0) == "test" )
    {
        //erase the first token in the list
        tokenList.erase(tokenList.begin());
        //while the tokenlist is not empty and that
        // the token at the beginning is not a connector or parentheses
        while (!tokenList.empty() && !is_Connector(tokenList.front()) &&
               !is_begin_para(tokenList.front()) &&
               !is_end_para(tokenList.front()))
        {
            //removing literals
            remove_literals(tokenList.front());
            //add the token to the argument list
            argumentList.push_back(tokenList.front());
            //then remove the token from the token list
            tokenList.erase(tokenList.begin());
        }

        //if the argument size is greater than two, throw an error
        if(argumentList.size() > 2)
        {
            std::string error = "rshell: test: too many arguments\n";
            throw error;
        }
        //if the size is 2 and that the first items size is 2 or the size
        // is less than or equal to one
        if((argumentList.size() == 2 && argumentList.at(0).size() == 2) ||
                (argumentList.size() <= 1))
        {
            //make the new test command
            testvar = new TestCmd(argumentList);
        }
        else
        {
            //there was no flag so
            //insert the last token of the argument list back to the token list
            tokenList.insert(tokenList.begin(),argumentList.back());
            //remove the last argument from the argument list
            argumentList.pop_back();
            //make the new test command
            testvar = new TestCmd(argumentList);
        }

    }
    else
    {
        //this is for the baracketed version of the test function
        //remove the beginning bracket
        tokenList.erase(tokenList.begin());

        //if there are special cases
        if(tokenList.size() >= 2 && ((tokenList.at(0) == "]" &&
                 tokenList.at(1) == " ]" ) || (tokenList.at(0) == "[ " &&
                                               tokenList.at(1) == "]")))
        {
            if(tokenList.at(0) == "[ ")
            {
                tokenList.at(0).erase(1,1);
            }
            argumentList.push_back(tokenList.front());
            tokenList.erase(tokenList.begin());
            tokenList.erase(tokenList.begin());
            testvar = new TestCmd(argumentList);
        }
        else if(tokenList.size() == 1 && tokenList.front() == "]")
        {
            tokenList.erase(tokenList.begin());
            testvar = new TestCmd(argumentList);
        }
        //look for the ending bracked and throw and error if not found
        else if(std::find(tokenList.begin(),tokenList.end()," ]") ==
                tokenList.end())
        {
            std::string error = "rshell: [: missing ']'\n";
            throw error;
        }
        else
        {
            //if my token list is not empty, and that it is not reached the
            // ending bracket
            while (!tokenList.empty() && tokenList.front() != " ]")
            {
                //if there is a connector or parentheses in between the test
                // brackets,
                //then throw an error
                if(is_Connector(tokenList.front()) ||
                        is_begin_para(tokenList.front()) ||
                        is_end_para(tokenList.front()))
                {
                    std::string error = "rshell: [: missing ']'\n";
                    throw error;
                }
                else
                {
                    //removing literals
                    remove_literals(tokenList.front());
                    //add the token to the argument list
                    argumentList.push_back(tokenList.front());
                    //then remove the token from the token list
                    tokenList.erase(tokenList.begin());
                }
            }

            //eraseing the " ]" token from the list
            tokenList.erase(tokenList.begin());

            //if the argument size is greater than two, throw an error
            if(argumentList.size() > 2)
            {
                std::string error = "rshell: test: too many arguments\n";
                throw error;
            }
            //if the size is 2 and that the first items size is 2 or the
            // size is less than or equal to one
            if((argumentList.size() == 2 && argumentList.at(0).size() == 2
                && argumentList.at(0).find("-") == 0)
                    || (argumentList.size() <= 1))
            {
                //make the new test command
                testvar = new TestCmd(argumentList);
            }
            else
            {
                std::string error = "Error : -rshell: [: "
                        + argumentList.front() + " unary operator expected\n";
                throw error;

            }

        }
    }

    return testvar;
}

//checks if the token is a beginning parentheses
bool CMDTranslator::is_begin_para(const std::string & token)
{
    return (token == "(");
}
//checks if the token is an ending parentheses
bool CMDTranslator::is_end_para(const std::string & token)
{
    return (token == ")");
}

bool CMDTranslator::is_valid_operand(const bool & isStart,
                                     const bool & isConnector,
                                     const bool & isBeginPara)
{
    //an operand is valid if and only if that the item that came before it is a
    //  connector, a beginning parentheses, or that it is the starting item
    return (isStart || isConnector || isBeginPara);
}

bool CMDTranslator::is_valid_operator(const bool & isStart,
                                      const bool & isConnector,
                                      const bool & isBeginPara)
{
    //an operator is valid if and only if that the item that came before it is
    // not another connector, not a beginning parentheses, and is not starting
    // at the beginning
    return (!isStart && !isConnector && !isBeginPara);
}

bool CMDTranslator::is_valid_begin_para(const bool & isStart,
                                        const bool & isConnector,
                                        const bool & isBeginPara)
{
    //a beginning parentheses is valid if and only if that the item that came
    // before it is an operator, another begining parentheses, or is the
    // starting item
    return (isStart || isConnector || isBeginPara);
}

bool CMDTranslator::is_valid_end_para(const bool & isStart,
                                      const bool & isConnector,
                                      const bool & isBeginPara)
{
    //an ending parentheses is valid if and only if that the item that came
    // before it is not a connector, not a beginning parentheses, and is not
    // the starting item
    return (!isStart && !isConnector && !isBeginPara);
}

void CMDTranslator::add_operand(std::vector<std::string> & infix,
                                std::vector<CMDLine *> & output,
                                std::vector<CMDLine *> & toReturn)
{
    CMDLine * operand = nullptr;
    //if the first token is test or the "[ ", then make a test object
    if(infix.at(0) == "test" || infix.at(0) == "[ ")
    {
        operand = make_Test(infix);
    }
    //else make a command object
    else
    {
        operand = make_CMD(infix);
    }
    //add the item to the output and toReturn
    output.push_back(operand);
    toReturn.push_back(operand);
}

void CMDTranslator::add_operator(std::vector<std::string> & infix,
                                 std::vector<CMDLine *> & output,
                                 std::vector<CMDLine *> & toReturn,
                                 std::vector<std::string> & operatorStack)
{
    std::string Operator = infix.at(0);
    infix.erase(infix.begin());
    std::string OperatorTemp;
    Connector * temp = nullptr;
    //if
    //  the operatorStack is empty, then add the operator to the operatorStack
    // and remove it from the infix
    if(operatorStack.empty())
    {
        operatorStack.push_back(Operator);
    }
    //else if
    //  the new operator token has a precedence greater than that of the
    // operator that is on the top of the stack or that the top of the
    // operatorStack is the beginning parentheses, then add it to the
    // operatorStack and remove it from the infix
    else if(((precedenceMap.count(Operator) &&
              precedenceMap.count(operatorStack.back())) &&
             precedenceMap.at(Operator) >
             precedenceMap.at(operatorStack.back()))
            || is_begin_para(operatorStack.back()))
    {
        operatorStack.push_back(Operator);
    }
    //else
    else
    {
        //while
        // the new operator's precedence is less than or equal to the precedence
        // of the top of the stack and that the top of the stack is not a
        // beginning parentheses and that the operatorStack is not empty,
        while(!operatorStack.empty() &&
              ((precedenceMap.count(Operator) &&
                precedenceMap.count(operatorStack.back()) &&
                precedenceMap.at(Operator) <= precedenceMap.at(Operator)) ||
               !is_begin_para(operatorStack.back())))
        {
            //create a operator object from the top of the stack
            temp = make_connector(operatorStack.back());
            // with the last two items added to the output as its children,
            if(output.size() >= 2)
            {
                temp->setRight(output.back());
                output.pop_back();
                temp->setLeft(output.back());
                output.pop_back();
            }
            else
            {
                std::string error = "Error : -rshell: syntax error near"
                                    " unexpected token "
                        + operatorStack.back() + "\n";
                throw error;
            }

            // pop the top operator from the stack and
            operatorStack.pop_back();

            // then add newly made object into the output and toReturn.
            output.push_back(temp);
            toReturn.push_back(temp);
            temp = nullptr;

        }
        //
        //Then add the new operator
        // to the operatorStack and remove it from the infix
        operatorStack.push_back(Operator);
    }

}

void CMDTranslator::add_begin_para(std::vector<std::string> & infix,
                                   std::vector<std::string> & operatorStack)
{
    //adds a beginning parentheses token to the operatorStack
    operatorStack.push_back(infix.at(0));
    //removes it from the infix
    infix.erase(infix.begin());
}

void CMDTranslator::add_end_para(std::vector<std::string> & infix,
                                 std::vector<CMDLine *> & output,
                                 std::vector<CMDLine *> &toReturn,
                                 std::vector<std::string> & operatorStack)
{
    Connector * temp = nullptr;
    //while the operatorStack is not empty and that the top of the stack is
    // not a begining parentheses,
    while(!operatorStack.empty() && !is_begin_para(operatorStack.back()))
    {
        //create a operator object from the top of the stack
        temp = make_connector(operatorStack.back());
        // with the last two items added to the output as its children,
        if(output.size() >= 2)
        {
            temp->setRight(output.back());
            output.pop_back();
            temp->setLeft(output.back());
            output.pop_back();
        }
        else
        {
            std::string error = "Error : -rshell: syntax error near"
                                " unexpected token "
                    + operatorStack.back() + "\n";
            throw error;
        }

        // pop the top operator from the stack and
        operatorStack.pop_back();

        // then add the newly made object into the output and toReturn.
        output.push_back(temp);
        toReturn.push_back(temp);
        temp = nullptr;
    }

    //then
    //if
    // the operatorStack is empty, then throw an error, as the user did not
    // enter the correct number of beginning and ending parentheses
    if(operatorStack.empty())
    {
        std::string error = "rshell: syntax error near unexpected token ')'\n";
        throw error;
    }
    //else
    else
    {
        // pop the top of the operatorStack for the beginning parentheses and
        // remove the ending parentheses from the infix
        operatorStack.pop_back();
        infix.erase(infix.begin());
    }
}

Connector *CMDTranslator::make_connector(const std::string & token)
{
    Connector *newConnector = nullptr;
    if (token == connectors.at(0))
    {
        newConnector = new And();
    }
    else if (token == connectors.at(1))
    {
        newConnector = new Or();
    }
    else if(token == connectors.at(2))
    {
        newConnector = new Semicolon();
    }
    else if (token == connectors.at(3))
    {
        std::cout << "making pipe!\n";
        newConnector = new Pipe();
    }
    else if (token == connectors.at(4))
    {
        std::cout << "making InputRed!\n";
        newConnector = new InputRedirection();
    }
    else if (token == connectors.at(5))
    {
        std::cout << "making OutputRed!\n";
        newConnector = new OutputRedirection();
    }
     else if (token == connectors.at(6))
    {
        std::cout << "making DoubleOutputRed!\n";
        newConnector = new DoubleOutputRed();
    }


    return newConnector;
}

CMDLine *CMDTranslator::translate(std::vector<std::string> tokenList,
                                  std::vector<CMDLine *> &returnList)
{
    CMDLine *toReturn = nullptr;
    std::vector<CMDLine *> output;
    std::vector<std::string> operatorStack;
    Connector *temp = nullptr;

    bool isStart = true;        //at the beginning of the infix input
    bool isConnector = false;   //if the lst item was a connector
    bool isBeginPara = false;   //if the last item was a beginning parentheses

    while (!tokenList.empty())
    {
        //if it is a comment at the front
        //then erase all the tokens in the list
        if (tokenList.front().find("#") == 0)
        {
            remove_comment(tokenList);
        }
        //else if the token is a valid beginning parentheses
        else if(is_begin_para(tokenList.at(0)) &&
                is_valid_begin_para(isStart,isConnector,isBeginPara))
        {
            add_begin_para(tokenList,operatorStack);
            isStart = false;
            isConnector = false;
            isBeginPara = true;
        }
        //else if the token is a valid ending parentheses
        else if (is_end_para(tokenList.at(0)) &&
                 is_valid_end_para(isStart,isConnector,isBeginPara))
        {
            add_end_para(tokenList,output, returnList,operatorStack);
            isStart = false;
            isConnector = false;
            isBeginPara = false;
        }
        //else if the token is a valid connector
        else if (is_Connector(tokenList.at(0)) &&
                 is_valid_operator(isStart,isConnector,isBeginPara))
        {
            add_operator(tokenList,output,returnList,operatorStack);
            isStart = false;
            isConnector = true;
            isBeginPara = false;
        }
        //else if the token is a valid operand/command
        else if(!is_begin_para(tokenList.at(0)) &&
                !is_end_para(tokenList.at(0)) &&
                !is_Connector(tokenList.at(0)) &&
                is_valid_operand(isStart,isConnector,isBeginPara))
        {
            add_operand(tokenList,output,returnList);
            isStart = false;
            isConnector = false;
            isBeginPara = false;
        }
        else
        {
            std::cout << "here in error\n";
            const std::string error2 =
                    "Error : -rshell: syntax error near unexpected token "
                    + tokenList.front() + "\n";
            throw error2;
        }
    }

    while (!operatorStack.empty())
    {
        //if there is there is more than one item in the operand stack and
        // that the output size >=2
        if((operatorStack.size() >= 1 && output.size() >= 2))
        {
            //create a operator object from the top of the stack
            temp = make_connector(operatorStack.back());

            // with the last two items added to the output as its children,
            temp->setRight(output.back());
            output.pop_back();
            temp->setLeft(output.back());
            output.pop_back();

            // pop the top operator from the stack and
            operatorStack.pop_back();

            //add the newly made object into the output and toReturn.
            output.push_back(temp);
            returnList.push_back(temp);
            temp = nullptr;
        }
        else if (operatorStack.size() == 1 && output.size() == 1)
        {
            if(operatorStack.back() == ";")
            {
                //create a operator object from the top of the stack
                temp = make_connector(operatorStack.back());

                temp->setLeft(output.back());
                output.pop_back();

                // pop the top operator from the stack and
                operatorStack.pop_back();

                // newly made object into the output and toReturn.
                output.push_back(temp);
                returnList.push_back(temp);
                temp = nullptr;
            }
            else
            {
                const std::string error2 =
                        "Error : -rshell: syntax error near unexpected token "
                        + operatorStack.front() + "\n";
                throw error2;
            }
        }
        else
        {
            const std::string error2 =
                    "Error : -rshell: syntax error near unexpected token "
                    + operatorStack.front() + "\n";
            throw error2;
        }
    }

    if(output.size() > 1)
    {
        const std::string error2 =
                "Error : -rshell: syntax error\n";
        throw error2;
    }
    else if(output.size() < 1)
    {
        std::vector<std::string> emptyArg;
        toReturn = new CMD(emptyArg);
        returnList.push_back(toReturn);
    }
    else
    {
        toReturn = output.back();
    }
    return toReturn;
}

