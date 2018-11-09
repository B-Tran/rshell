#include <iostream>
#include "stringParser.h"
using namespace std;

int main()
{
    vector<string> dList;
    vector<string> dIList;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    StringParser parsing(dList,dIList);
    string input;
    vector<string> tokens;

    cout << "$ ";
    getline(cin,input);
    tokens = parsing.parse_string(input);
    for(size_t i = 0 ; i < tokens.size(); ++i)
    {
        cout << tokens.at(i) << "\n";
    }
}
