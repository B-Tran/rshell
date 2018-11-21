Rshell
===
## Installation
```bash
$ git clone https://github.com/cs100/assignment-1-failing-unit-testers.git

$ cd assignment-1-failing-unit-testers

$ cmake .

$ make

$  ./rshell
```

## Introduction 
 Our program uses C++ to imitate the Linux terminal by running programs in the `/bin/` directory. It is designed to run any number of commands given the valid commands. For instance : `ls -a; echo hello; mkdir test` Further, our R shell will execute valid connectors such as `||` , `&&`,`;` , and handle special commands such as `exit`,`#`, and `cd` based on their specifications. It is able execute the appropriate three linux syscalls commands ;  `execvp()`,`waitpid()` ,and `fork()`.  A set of tests are included in `/tests` to test the functionality of the program.

We used the composite design pattern to implemented the program as hierarchy tree structure.The top of the hierarchy is CMDLine abstract class. The CMDLine base class will have virtual bool executed function for all the subclasses to inherit. The next layers of the trees are CMD and Connectors and then children of the CMD and Connectors are Exit,And, Or, and Semicolon. During the assignment 2 sprint, we made new adjustments on the UML diagram. We added an another class called cmdTranslator. The main goal for the cmdTranslator is to convert string tokens into objects. With this conversion, we can use the token objects to call the connector's children (And, Or, Semicolon) to execute the boolean condition. As the following diagram demonstrates:

## UML Diagram 
![assignment 1](https://user-images.githubusercontent.com/43591097/48861992-d37fe480-ed79-11e8-8033-6dc0a29ee0e6.png)

## Output
 If the user entered invalid command in the command line then our R Shell program will throw an error exception to inform the user's incorrect command. For example:

 

An another error checking , we considered is the connectors. 
 

 
## Known Bugs

There were several problems we encountered  in the command input.

1. The program won't able to handle string literals in the command input. 
 
2. Cd is not part of bin file diectory so cd won't work as a command.  

3. The command input does not handle Parenthesis 

4. 


## Authors & Contributor List

* Brandon Tran - https://github.com/B-Tran

* Christian Campos - https://github.com/ccamp032

All other known bugs and fixes can be sent to btran054@ucr.edu and ccamp032@ucr.edu 

Reported bugs and fixes will be submitted to correction
