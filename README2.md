#Assignment 2 -- Writing a Basic Command Shell

## Introduction 
The main task of assignment 2 is to create a R shell for the user to enter valid commands , arguments, and connectors in one line. The commands and connectors will be implemented as hierarchy tree structure. It has the some functionality as a bash terminal, it is able to perform the three sytem calls execvp,waitpid,and fork. 
The program will output an error if the user enters a incorrect error. 


## UML Diagram 
 During the assignment 2 project, we made adjustments on the UML diagram. We added an another class called cmdTranslator. The main goal for the cmdTranslator is to convert tokens into objects. With this conversion, we can use the token objects to use call the connector's children (And, Or, Semicolon) to execute the . As the following the diagram shows:


      
      ![](https://github.com/cs100/assignment-1-failing-unit-testers/src/Assignment_1.png)

     ![](https://i.imgur.com/Assignment_1.png)
      
      
## Input
 


## Output/Testing point
 If the user entered invalid command in the command line then our R Shell program will throw an error execpetion to inform the user's incorrect command. For example:
 // add the code here
 An another error checking , we considered is the connectors. An error 
 

 
##Problems/Limitations 

There were several problems we ecountred in the command input. 
1) The program won't able to handle string literals in the command input. 
 
2) Cd is not part of bin file diectory so cd won't work as a command.However, the cd error will be implemented in the next assigment.  


##Note
We were only able to test the parser in the program. We are aware there are more testing that need to done in the R Shell. The rest of tests will be implemented in the next assignment. 
Further, we added perror for every syscall.

