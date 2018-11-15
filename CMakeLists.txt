CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(RShell 
	"src/main.cpp" 
	"src/stringParser.cpp"
	"src/CMD.cpp"
	 "src/cmdTranslator.cpp"
	 "src/stringParser.cpp"
         "src/CMD.cpp"
	 "src/Connector.cpp"
	 "src/Or.cpp"
	 "src/And.cpp"
	 "src/Semicolon.cpp"
	 "src/Exit.cpp"
	)

ADD_EXECUTABLE(stringParseTest
	"tests/stringParseTest.cpp"
	"src/stringParser.cpp"
)

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
	
)

TARGET_LINK_LIBRARIES(stringParseTest gmock)
TARGET_LINK_LIBRARIES(stringParseTest gtest)
TARGET_COMPILE_DEFINITIONS(stringParseTest PRIVATE gtest_disable_pthreads=ON)
