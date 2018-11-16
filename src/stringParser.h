#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

class StringParser
{
private:
    std::vector<std::string> delimList;         //list of all delimiters
    std::vector<std::string> delimIgnList;      //list of ignored delimiters
    std::vector<std::string> literalList;       //list of exceptions due to literals

    //gets the tokens that are split by the delimiters
    std::string get_token(std::string & input);

    //gets the literals in the string
    std::string get_literal(std::string & input);

    //gets the other tokens that are the delimiters that are needed
    void get_delim(std::vector<std::string>& tokenList, std::string& input);

    //finds if a delimiter is at the begining of the parsed input
    size_t found_begin_delim(const std::string & input);

    //checks of delimiter is not a ignored delimiter
    bool not_a_ign_delim(const std::string & delim);

    //checks if there is a literal at the beginning of the input
    size_t found_begin_literal(const std::string & input);

public:
    StringParser();
    StringParser(std::vector<std::string> dList,
            std::vector<std::string> dIList, std::vector<std::string> literals);
    ~StringParser();

    //adds a delimiter that we will use to parse
    void add_delim_item(std::string delimItem);

    //adds a delimiter that we will ignore during tokenization
    void add_delim_ign_item(std::string delimIgnItem);

    //adds a litteral item
    void add_literal_item(std::string literal);

    //gets a string and parses it into a vector of tokens
    std::vector<std::string> parse_string(std::string input);
};


#endif // STRINGPARSER_H
