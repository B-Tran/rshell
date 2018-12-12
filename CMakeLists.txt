CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


set(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(rshell
	"src/rshell.cpp"
	"src/stringParser.cpp"
	"src/CMD.cpp"
	 "src/cmdTranslator.cpp"
	 "src/Connector.cpp"
	 "src/Or.cpp"
	 "src/And.cpp"
	 "src/Semicolon.cpp"
	 "src/Exit.cpp"
         "src/CMDLine.cpp"
         "src/TestCmd.cpp"
	)

#ADD_EXECUTABLE(stringParseTest
#	"tests/stringParseTest.cpp"
#	"src/stringParser.cpp"
#)

ADD_EXECUTABLE(translateMain
	"src/translateMain.cpp"
	"src/cmdTranslator.cpp"
	"src/stringParser.cpp"
         "src/CMD.cpp"
        "src/Connector.cpp"
	"src/Or.cpp"
        "src/And.cpp"
	"src/Semicolon.cpp"
	"src/Exit.cpp"
        "src/CMDLine.cpp"
        "src/TestCmd.cpp"
)
ADD_EXECUTABLE(test
	"tests/test.cpp"
	"tests/stringParseTest.cpp"
	"tests/CMDTest.cpp"
	"tests/testCmd.cpp"
	"src/stringParser.cpp"
	"src/stringParser.cpp"
	"src/CMD.cpp"
	 "src/cmdTranslator.cpp"
	 "src/Connector.cpp"
	 "src/Or.cpp"
	 "src/And.cpp"
	 "src/Semicolon.cpp"
	 "src/Exit.cpp"
     "src/CMDLine.cpp"
     "src/TestCmd.cpp"
)

#ADD_EXECUTABLE(CMDTest
#	"src/main.cpp"
#	"src/stringParser.cpp"
#	"src/CMD.cpp"
#	 "src/cmdTranslator.cpp"
#	 "src/stringParser.cpp"
#         "src/CMD.cpp"
#	 "src/Connector.cpp"
#	 "src/Or.cpp"
#	 "src/And.cpp"
#	 "src/Semicolon.cpp"
#	 "src/Exit.cpp"
#         "src/CMDLine.cpp"
#         "src/TestCmd.cpp"
#	)

#ADD_EXECUTABLE(testcmdMain
#"src/TestCmd.cpp"
#"src/testCmdMain.cpp"
#	"src/cmdTranslator.cpp"
#	"src/stringParser.cpp"
#         "src/CMD.cpp"
#        "src/Connector.cpp"
#	"src/Or.cpp"
#        "src/And.cpp"
#	"src/Semicolon.cpp"
#	"src/Exit.cpp"
#        "src/CMDLine.cpp"
#)
#ADD_EXECUTABLE(CommandsTest
#	"tests/CMDTest.cpp"
#	"src/stringParser.cpp"
#	"src/CMD.cpp"
#	 "src/cmdTranslator.cpp"
#	 "src/Connector.cpp"
#	 "src/Or.cpp"
#	 "src/And.cpp"
#	 "src/Semicolon.cpp"
#	 "src/Exit.cpp"
#         "src/CMDLine.cpp"
#)

#ADD_EXECUTABLE(ParserTest
#                "src/parserMain.cpp"
#                "src/stringParser.cpp"
#)

#TARGET_LINK_LIBRARIES(stringParseTest gmock)
#TARGET_LINK_LIBRARIES(stringParseTest gtest)
#TARGET_COMPILE_DEFINITIONS(stringParseTest PRIVATE gtest_disable_pthreads=ON)
#
#TARGET_LINK_LIBRARIES(CommandsTest gmock)
#TARGET_LINK_LIBRARIES(CommandsTest gtest)
#TARGET_COMPILE_DEFINITIONS(CommandsTest PRIVATE gtest_disable_pthreads=ON)
#
TARGET_LINK_LIBRARIES(test gmock)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
