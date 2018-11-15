#include "stringParser.h"

std::string StringParser::get_token(std::string & input)
{
    std::string token;
    size_t pos = input.size();
    size_t notFound = 0;

    //getting the first token in the list by looking for the first delimiter
    for(size_t i = 0; i < delimList.size(); ++i)
    {
//        std::cout << "finding delim list: " << input.find(delimList.at(i)) << "\n";
        if((input.find(delimList.at(i)) < input.size()) &&
                (input.find(delimList.at(i)) < pos))
        {
            pos = input.find(delimList.at(i));
        }

        if(input.find(delimList.at(i)) >= input.size())
        {
            ++notFound;
        }
    }

    //if no delimiters were found, then the rest of the parsed input is a
    // token
    if(notFound == delimList.size())
    {
        token = input;
        input.erase();
    }
    //if there was a delimiter found, then extract the token from the input
    else
    {
//        std::cout << "pos: " << pos << "\n";
//        std::cout << "delimiter: -" << input.at(pos) << "-\n";
        token = input.substr(0,pos);
        input.erase(0,pos);
    }
    //else return that there was no token

    return token;
}

void StringParser::get_delim(std::vector<std::string>& tokenList, std::string& input)
{
    size_t pos;
    //looks for all delimiters that are at the beginning of the parsed input
    //and either removes them from the parsed input or adds them as a token
    pos = found_begin_delim(input);
//    std::cout << "pos in geting delim: " << pos << "\n";
    while (pos < delimList.size())
    {
        if(not_a_ign_delim(delimList.at(pos)))
        {
            tokenList.push_back(delimList.at(pos));
            input.erase(0,delimList.at(pos).size());
        }
        else
        {
            input.erase(0,delimList.at(pos).size());
        }
        pos = found_begin_delim(input);
    }
}

size_t StringParser::found_begin_delim(const std::string & input)
{
    size_t pos = delimList.size();

    for(size_t i = 0; i < delimList.size(); ++i)
    {
//        std::cout << "checking for finding: " << (input.find(delimList.at(i))) << "\n";
        if(input.find(delimList.at(i)) == 0)
        {
//            std::cout << "found delim: " << i << "\n";
            pos = i;
        }
//        std::cin.get();
    }

    return pos;
}

bool StringParser::not_a_ign_delim(const std::string & delim)
{
    for(size_t i = 0; i < delimIgnList.size(); ++i)
    {
        if(delim == delimIgnList.at(i))
        {
            return false;
        }
    }
    return true;
}

StringParser::StringParser()
{

}

StringParser::StringParser(std::vector<std::string> dList, std::vector<std::string> dIList)
{
    delimList = dList;
    delimIgnList = dIList;
}

StringParser::~StringParser()
{

}

void StringParser::add_delim_item(std::string delimItem)
{
    delimList.push_back(delimItem);
}


void StringParser::add_delim_ign_item(std::string delimIgnItem)
{
    delimIgnList.push_back(delimIgnItem);
}


std::vector<std::string> StringParser::parse_string(std::string input)
{
    std::vector<std::string> tokenList;     //storage of tokens
    std::string token;                      //storage of a single token

//    std::cout << "in parse string\n";
    //while I have not completely parsed the input
    while (!input.empty())
    {
        //see if I am able to get a token that is not a delimiter
        token = get_token(input);

//        std::cout << "token: " << token << "\n";
//        std::cout << "input: " << input << "\n";
//        std::cin.get();

        //then add that token into the list
        if(!token.empty())
        {
            tokenList.push_back(token);
        }
        //else move on

        //then check for tokens that are delimitters and are also tokens.
        //if so put them into the list
        get_delim(tokenList,input);
    }

    return tokenList;
}