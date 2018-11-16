#include <iostream>
#include "../src/stringParser.h"
#include "../src/CMD.h"
#include "../src/cmdTranslator.h"
#include "../src/Semicolon.h"
#include "../src/And.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>  // wait
#include <limits.h> // HOST_Name_MAX
#include <cstdlib>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(CMDTEST, OneCommand)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    CMD * command = new CMD(arguement);
    EXPECT_EQ(command->execute(),1);
}

TEST(CMDTEST, OneCommandOneArg)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD * command = new CMD(arguement);
    EXPECT_EQ(command->execute(),1);
}

TEST(CMDTEST, semicolon_connector)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD * command = new CMD(arguement);
    std::vector<std::string> arguement2;
    arguement2.push_back("echo");
    arguement2.push_back("hello");
    CMD * command2 = new CMD(arguement2);
    Semicolon * S = new Semicolon(command,command2);
    EXPECT_EQ(S->execute(),1);
}

int main(int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}