#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
#include "../src/stringParser.h"
#include "../src/CMD.h"
#include "../src/cmdTranslator.h"
#include "../src/Semicolon.h"
#include "../src/And.h"
#include "../src/Or.h"
#include "../src/Pipe.h"
#include "../src/InputRedirection.h"
#include "../src/OutputRedirection.h"
#include "../src/DoubleOutputRed.h"

TEST(REDIRECTIONTEST, PIPE)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    CMD *command = new CMD(arguement);
    std::vector<std::string> argument2;
    argument2.push_back("sort");
    CMD *command2 = new CMD(argument2);
    CMDLine *command3 = new Pipe(command,command2);

    EXPECT_EQ(command3->execute(0,1),1);
    delete command;
    delete command2;
    delete command3;
}

TEST(REDIRECTIONTEST, MULTIPIPE)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    CMD *command = new CMD(arguement);
    std::vector<std::string> argument2;
    argument2.push_back("cat");
    CMD *command2 = new CMD(argument2);
    CMDLine *command3 = new Pipe(command,command2);
    std::vector<std::string> argument3;
    argument3.push_back("sort");
    CMD *command4 = new CMD(argument3);
    CMDLine *command5 = new Pipe(command3,command4);
    EXPECT_EQ(command5->execute(0,1),1);

    delete command;
    delete command2;
    delete command3;
    delete command4;
    delete command5;
}

TEST(REDIRECTIONTEST, INPUTREDIRECTION)
{
    std::vector<std::string> arguement;
    arguement.push_back("sort");
    CMD *command = new CMD(arguement);
    std::vector<std::string> argument2;
    argument2.push_back("CMakeLists.txt");
    CMD *command2 = new CMD(argument2);
    CMDLine *command3 = new InputRedirection(command,command2);

    EXPECT_EQ(command3->execute(0,1),1);
    delete command;
    delete command2;
    delete command3;
}

TEST(REDIRECTIONTEST, OUTPUTREDIRECTION)
{
    std::vector<std::string> arguement;
    arguement.push_back("ls");
    CMD *command = new CMD(arguement);
    std::vector<std::string> argument2;
    argument2.push_back("testfile.txt");
    CMD *command2 = new CMD(argument2);
    CMDLine *command3 = new OutputRedirection(command,command2);
    std::vector<std::string> arguement3;
    arguement3.push_back("rm");
    arguement3.push_back("testfile.txt");
    CMD *command4 = new CMD(arguement3);
    std::vector<std::string> arguement4;
    arguement4.push_back("cat");
    arguement4.push_back("testfile.txt");
    CMD *command5 = new CMD(arguement4);

    EXPECT_EQ(command3->execute(0,1),1);
    EXPECT_EQ(command5->execute(0,1),1);
    EXPECT_EQ(command4->execute(0,1),1);
    delete command;
    delete command2;
    delete command3;
    delete command4;
    delete command5;
}

TEST(REDIRECTIONTEST, MULTIREDIRECTION)
{
    std::vector<std::string> arguement;
    arguement.push_back("cat");
    CMD *command1 = new CMD(arguement);
    std::vector<std::string> arguement2;
    arguement2.push_back("CMakeLists.txt");
    CMD *command2 = new CMD(arguement2);
    std::vector<std::string> arguement3;
    arguement3.push_back("tr");
    arguement3.push_back("A-Z");
    arguement3.push_back("a-z");
    CMD *command3 = new CMD(arguement3);
    std::vector<std::string> arguement4;
    arguement4.push_back("tee");
    arguement4.push_back("newOutputFile1");
    CMD *command4 = new CMD(arguement4);
    std::vector<std::string> arguement5;
    arguement5.push_back("tr");
    arguement5.push_back("a-z");
    arguement5.push_back("A-Z");
    CMD *command5 = new CMD(arguement5);
    std::vector<std::string> arguement6;
    arguement6.push_back("newOutputFile2");
    CMD *command6 = new CMD(arguement6);
    std::vector<std::string> arguement7;
    arguement7.push_back("cat");
    arguement7.push_back("newOutputFile1");
    CMD *command7 = new CMD(arguement7);
    std::vector<std::string> arguement8;
    arguement8.push_back("cat");
    arguement8.push_back("newOutputFile2");
    CMD *command8 = new CMD(arguement8);
    std::vector<std::string> arguement9;
    arguement9.push_back("rm");
    arguement9.push_back("newOutputFile1");
    arguement9.push_back("newOutputFile2");
    CMD *command9 = new CMD(arguement9);

    Connector *connector1 = new InputRedirection(command1,command2);
    Connector *connector2 = new Pipe(connector1,command3);
    Connector *connector3 = new Pipe(connector2,command4);
    Connector *connector4 = new Pipe(connector3,command5);
    Connector *connector5 = new OutputRedirection(connector4,command6);


    EXPECT_EQ(connector5->execute(0,1),1);
    EXPECT_EQ(command7->execute(0,1),1);
    EXPECT_EQ(command8->execute(0,1),1);
    EXPECT_EQ(command9->execute(0,1),1);

    delete command1;
    delete command2;
    delete command3;
    delete command4;
    delete command5;
    delete command6;
    delete command7;
    delete command8;
    delete connector1;
    delete connector2;
    delete connector3;
    delete connector4;
    delete connector5;
}
