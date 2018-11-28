#include <iostream>
#include "../src/stringParser.h"
#include "../src/CMD.h"
#include "../src/cmdTranslator.h"
#include "../src/TestCmd.h"

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

TEST(TESTCMDCLASS, NOFlagTest1)
{
  
    std::vector<std::string> theNoFlagTest1;
    theNoFlagTest1.push_back("CMakeLists.txt");

   TestCmd testCommand(theNoFlagTest1);

     EXPECT_EQ(testCommand.execute(),1) ;
}
TEST(TESTCMDCLASS, NOFlagTest2)
{
  
    
    std::vector<std::string> theNoFlagTest2;
    theNoFlagTest2.push_back("src/");

   TestCmd testCommand(theNoFlagTest2);

     EXPECT_EQ(testCommand.execute(),1) ;
}

TEST(TESTCMDCLASS, EFlagTest1)
{
  
    
    std::vector<std::string> theEFlagTest1;
    theEFlagTest1.push_back("-e");
    theEFlagTest1.push_back("src/");

   TestCmd testCommand(theEFlagTest1);

     EXPECT_EQ(testCommand.execute(),1) ;
}
TEST(TESTCMDCLASS, EFlagTest2)
{
  
    
    std::vector<std::string> theEFlagTest2;
    theEFlagTest2.push_back("-e");
    theEFlagTest2.push_back("CMakeLists.txt");

   TestCmd testCommand(theEFlagTest2);

     EXPECT_EQ(testCommand.execute(),1) ;
}
TEST(TESTCMDCLASS, DirectoryFlagTest)
{
  
    std::vector<std::string> theDirectoryTest;
    theDirectoryTest.push_back("-d");
    theDirectoryTest.push_back("src/"); 

   TestCmd testCommand(theDirectoryTest);

     EXPECT_EQ(testCommand.execute(),1) ;
}
TEST(TESTCMDCLASS, FileFlagTest)
{
  
    std::vector<std::string> theTest;
    theTest.push_back("-f");
    theTest.push_back("CMakeLists.txt"); 

   TestCmd testCommand(theTest);

     EXPECT_EQ(testCommand.execute(),1) ;
}
TEST(TESTCMDCLASS, DefaultFlagTest)
{
  
    std::vector<std::string> theDefaultFlagTest;
    theDefaultFlagTest.push_back("-e");
    theDefaultFlagTest.push_back("CMakeLists.txt");

    TestCmd testCommand(theDefaultFlagTest);

    EXPECT_EQ(testCommand.execute(),1) ;
}
///Expected Errors////
TEST(TESTCMDCLASS, InvalidFlagTest1)
{
  
    std::vector<std::string> theTest;
    theTest.push_back("-e");
    theTest.push_back("jfk;ldsn;kfjsk;f");

    TestCmd testCommand(theTest);

    EXPECT_EQ(testCommand.execute(),0) ;
}
TEST(TESTCMDCLASS, InvaildFlagTest2)
{
  
    std::vector<std::string> theTest;
    theTest.push_back("-e");

    TestCmd testCommand(theTest);

    EXPECT_EQ(testCommand.execute(),0) ;
}
TEST(TESTCMDCLASS, InvaildFlagTest3)
{
  
    std::vector<std::string> theTest;
    theTest.push_back("-e");
    theTest.push_back(";knflkndln");


    TestCmd testCommand(theTest);

    EXPECT_EQ(testCommand.execute(),0) ;
}
TEST(TESTCMDCLASS, InvaildFlagTest4)
{
  
    std::vector<std::string> theTest;
    theTest.push_back("-d");
    theTest.push_back("dannk;n;kfanf;kn");


    TestCmd testCommand(theTest);

    EXPECT_EQ(testCommand.execute(),0) ;
}
// TEST(TESTCMDCLASS, InvaildFlagTest3)
// {
    // This TEST case has a issue if the user entered invalid input in 
    // the beginning vector  
//     std::vector<std::string> theTest;
//     theTest.push_back("d;nnvm;lamfl;smd;lasmd;lk");

//     TestCmd testCommand(theTest);

//     EXPECT_EQ(testCommand.execute(),0) ;
// }
