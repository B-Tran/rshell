#include "../src/stringParser.h"
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(StringParseTest, OneItem)
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    
    std::string input = "ls";
	std::vector<std::string> tokens;
	tokens = parsing.parse_string(input);
	
	std::vector<std::string> ansTokens;
	ansTokens.push_back("ls");
	
	EXPECT_EQ(tokens,ansTokens);
}

TEST(StringParseTest, TwoItems)
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    
    std::string ls = "ls -a";
	std::vector<std::string> tokens;
	tokens = parsing.parse_string(ls);
	
	std::vector<std::string> ansTokens;
	ansTokens.push_back("ls");
	ansTokens.push_back("-a");
	
	EXPECT_EQ(tokens,ansTokens);
}

TEST(StringParseTest, FiveItems)
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    
    std::string ls = "ls -a; echo hello";
	std::vector<std::string> tokens;
	tokens = parsing.parse_string(ls);
	
	std::vector<std::string> ansTokens;
	ansTokens.push_back("ls");
	ansTokens.push_back("-a");
	ansTokens.push_back(";");
	ansTokens.push_back("echo");
	ansTokens.push_back("hello");
	
	EXPECT_EQ(tokens,ansTokens);
}

TEST(StringParseTest, SevenItems)
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    
    std::string ls = "ls -a; echo hello || echo world";
	std::vector<std::string> tokens;
	tokens = parsing.parse_string(ls);
	
	std::vector<std::string> ansTokens;
	ansTokens.push_back("ls");
	ansTokens.push_back("-a");
	ansTokens.push_back(";");
	ansTokens.push_back("echo");
	ansTokens.push_back("hello");
	ansTokens.push_back("||");
	ansTokens.push_back("echo");
	ansTokens.push_back("world");
	
	EXPECT_EQ(tokens,ansTokens);
}

TEST(StringParseTest, NineItems)
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    
    std::string ls = "ls -a; echo hello || echo world; git status";
	std::vector<std::string> tokens;
	tokens = parsing.parse_string(ls);
	
	std::vector<std::string> ansTokens;
	ansTokens.push_back("ls");
	ansTokens.push_back("-a");
	ansTokens.push_back(";");
	ansTokens.push_back("echo");
	ansTokens.push_back("hello");
	ansTokens.push_back("||");
	ansTokens.push_back("echo");
	ansTokens.push_back("world");
	ansTokens.push_back(";");
	ansTokens.push_back("git");
	ansTokens.push_back("status");
	
	EXPECT_EQ(tokens,ansTokens);
}

TEST(StringParseTest, NineItemsNoSpaces)
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    
    std::string ls = "ls -a;echo hello||echo world;git status";
	std::vector<std::string> tokens;
	tokens = parsing.parse_string(ls);
	
	std::vector<std::string> ansTokens;
	ansTokens.push_back("ls");
	ansTokens.push_back("-a");
	ansTokens.push_back(";");
	ansTokens.push_back("echo");
	ansTokens.push_back("hello");
	ansTokens.push_back("||");
	ansTokens.push_back("echo");
	ansTokens.push_back("world");
	ansTokens.push_back(";");
	ansTokens.push_back("git");
	ansTokens.push_back("status");
	
	EXPECT_EQ(tokens,ansTokens);
}

TEST(StringParseTest, NineItemsAllSpaces)
{
    std::vector<std::string> dList;
    std::vector<std::string> dIList;
    std::vector<std::string> limiters;
    dList.push_back(" ");
    dList.push_back("||");
    dList.push_back("&&");
    dList.push_back(";");
    dIList.push_back(" ");
    limiters.push_back("\"");
    limiters.push_back("\'");
    StringParser parsing(dList,dIList,limiters);
    
    std::string ls = "ls -a ; echo hello || echo world ; git status";
	std::vector<std::string> tokens;
	tokens = parsing.parse_string(ls);
	
	std::vector<std::string> ansTokens;
	ansTokens.push_back("ls");
	ansTokens.push_back("-a");
	ansTokens.push_back(";");
	ansTokens.push_back("echo");
	ansTokens.push_back("hello");
	ansTokens.push_back("||");
	ansTokens.push_back("echo");
	ansTokens.push_back("world");
	ansTokens.push_back(";");
	ansTokens.push_back("git");
	ansTokens.push_back("status");
	
	EXPECT_EQ(tokens,ansTokens);
}

//int main(int argc, char ** argv)
//{
//	::testing::InitGoogleTest(&argc,argv);
//	return RUN_ALL_TESTS();
//}
