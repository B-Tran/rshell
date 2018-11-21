Assignment 2 -- Writing a Basic Command Shell
===
## Rshell - Installation
```bash
$ git clone https://github.com/cs100/assignment-1-failing-unit-testers.git

$ cd assignment-1-failing-unit-testers

$ cmake .

$ make

$  ./rshell
```


## Introduction 
The main task of assignment 2 is to create a R shell for the user to enter valid commands , arguments, and connectors in one line. The commands and connectors will be implemented as hierarchy tree structure. It has the some functionality as a bash terminal, it is able to perform the three sytem calls execvp,waitpid,and fork. 
The program will output an error if the user enters a incorrect error. 


## UML Diagram 
 During the assignment 2 project, we made adjustments on the UML diagram. We added an another class called cmdTranslator. The main goal for the cmdTranslator is to convert tokens into objects. With this conversion, we can use the token objects to call the connector's children (And, Or, Semicolon) to execute the the boolean condition. As the following the diagram demonstrates:

![assignment 1](https://user-images.githubusercontent.com/43591097/48861992-d37fe480-ed79-11e8-8033-6dc0a29ee0e6.png)

## Output/Testing point
 If the user entered invalid command in the command line then our R Shell program will throw an error exception to inform the user's incorrect command.For example:

 

An another error checking , we considered is the connectors. 
 

 
## Known Bugs

There were several problems we encountered  in the command input.

1. The program won't able to handle string literals in the command input. 
 
2. Cd is not part of bin file diectory so cd won't work as a command.  

3. The command input does not handle Parenthesis 

4. 



## Note
We were only able to test the parser in the program. We are aware there are more testing that need to done in the R Shell because there are many potential bugs in the program. The rest of tests will be implemented in the next assignment. 
Further, we added perror for every syscall.

## Authors & Contributor List

* Brandon Tran - https://github.com/B-Tran

* Christian Campos - https://github.com/ccamp032

All other known bugs and fixes can be sent to btran054@ucr.edu and ccamp032@ucr.edu 

Reported bugs and fixes will be submitted to correction


