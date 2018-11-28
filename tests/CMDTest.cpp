#include <iostream>
#include "../src/stringParser.h"
#include "../src/CMD.h"
#include "../src/cmdTranslator.h"
#include "../src/Semicolon.h"
#include "../src/And.h"
#include "../src/Or.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h> // wait
#include <limits.h>   // HOST_Name_MAX
#include <cstdlib>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(CMDTEST, OneCommand)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    CMD *command = new CMD(arguement);
    EXPECT_EQ(command->execute(), 1);
}

TEST(CMDTEST, OneCommandOneArg)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);
    EXPECT_EQ(command->execute(), 1);
}

TEST(CMDTEST, semicolon_connector)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);
    std::vector<std::string> arguement2;
    arguement2.push_back("echo");
    arguement2.push_back("hello");
    CMD *command2 = new CMD(arguement2);
    Semicolon *S = new Semicolon(command, command2);
    EXPECT_EQ(S->execute(), 1);
}

TEST(CMDTEST, and_connector)
{

    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);

    std::vector<std::string> arguement2;
    arguement2.push_back("echo");
    arguement2.push_back("hello");
    CMD *command2 = new CMD(arguement2);

    std::vector<std::string> arguement3;
    arguement3.push_back("pwd");
    CMD *command3 = new CMD(arguement3);

    Semicolon *S = new Semicolon(command, command2);
    And *A = new And(S, command3);
    EXPECT_EQ(A->execute(), 1);
}

TEST(CMDTEST, or_connector)
{

    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);

    std::vector<std::string> arguement2;
    arguement2.push_back("echo");
    arguement2.push_back("hello");
    CMD *command2 = new CMD(arguement2);

    std::vector<std::string> arguement3;
    arguement3.push_back("pwd");
    CMD *command3 = new CMD(arguement3);

    std::vector<std::string> arguement4;
    arguement4.push_back("echo");
    arguement4.push_back("world");
    CMD *command4 = new CMD(arguement4);

    Semicolon *S = new Semicolon(command, command2);
    And *A = new And(S, command3);
    Or *O = new Or(A, command4);

    EXPECT_EQ(O->execute(), 1);
}

TEST(CMDTEST, semicolon_connector2)
{

    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);

    std::vector<std::string> arguement2;
    arguement2.push_back("echo");
    arguement2.push_back("hello");
    CMD *command2 = new CMD(arguement2);

    std::vector<std::string> arguement3;
    arguement3.push_back("pwd");
    CMD *command3 = new CMD(arguement3);

    std::vector<std::string> arguement4;
    arguement4.push_back("echo");
    arguement4.push_back("world");
    CMD *command4 = new CMD(arguement4);

    std::vector<std::string> arguement5;
    arguement5.push_back("git");
    arguement5.push_back("status");

    CMD *command5 = new CMD(arguement5);
    Semicolon *S = new Semicolon(command, command2);
    And *A = new And(S, command3);
    Or *O = new Or(A, command4);
    Semicolon *S2 = new Semicolon(O, command5);

    EXPECT_EQ(S2->execute(), 1);
}

TEST(CMDTEST, one_command_no_argument)
{
    std::vector<std::string> argument;
    CMD *command = new CMD(argument);

    EXPECT_EQ(command->execute(), 1);
}

TEST(CMDTEST, one_command_bad_argument)
{
    std::vector<std::string> arguement;
    arguement.push_back("invalid");
    CMD *command = new CMD(arguement);
    EXPECT_EQ(command->execute(), 0);
}

TEST(CMDTEST, semicolon_connector_bad_argument)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);
    std::vector<std::string> arguement2;
    arguement2.push_back("invalid");
    arguement2.push_back("hello");
    CMD *command2 = new CMD(arguement2);
    Semicolon *S = new Semicolon(command, command2);
    EXPECT_EQ(S->execute(), 0);
}

TEST(CMDTEST, and_connector_bad_argument)
{

    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);

    std::vector<std::string> arguement2;
    arguement2.push_back("invalid");
    arguement2.push_back("hello");
    CMD *command2 = new CMD(arguement2);

    std::vector<std::string> arguement3;
    arguement3.push_back("pwd");
    CMD *command3 = new CMD(arguement3);

    Semicolon *S = new Semicolon(command, command2);
    And *A = new And(S, command3);
    EXPECT_EQ(A->execute(), 0);
}

TEST(CMDTEST, or_connector_bad_arguement)
{

    std::vector<std::string> arguement;
    arguement.push_back("ls");
    arguement.push_back("-a");
    CMD *command = new CMD(arguement);

    std::vector<std::string> arguement2;
    arguement2.push_back("invalid");
    arguement2.push_back("hello");
    CMD *command2 = new CMD(arguement2);

    std::vector<std::string> arguement3;
    arguement3.push_back("pwd");
    CMD *command3 = new CMD(arguement3);

    std::vector<std::string> arguement4;
    arguement4.push_back("echo");
    arguement4.push_back("world");
    CMD *command4 = new CMD(arguement4);

    Semicolon *S = new Semicolon(command, command2);
    And *A = new And(S, command3);
    Or *O = new Or(A, command4);

    EXPECT_EQ(O->execute(), 1);
}