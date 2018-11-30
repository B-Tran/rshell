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
 Our program uses C++ to imitate the Linux terminal by running programs in the `/bin/` directory. It is designed to run any number of commands given the valid commands. For instance : `ls -a; echo hello; mkdir test`. Our R shell will execute valid connectors such as `||` , `&&`,`;` , and handle special commands such as `exit`,`#`,`(` , `)` , and `cd` based on their specifications. We implemented a `test` command to check specific linux flags ( `-e `, `-f`,`-d` ) if the file or directory exist or both. Further, It is able execute the appropriate four linux syscalls commands ;  `execvp()`,`waitpid()` ,`fork()`, and `stat()`. 
 A set of tests are included in `/tests` to test the functionality of the program.


We used the composite design pattern to implemented the program as hierarchy tree structure.The top of the hierarchy is CMDLine abstract class. The CMDLine base class will have virtual bool executed function for all the subclasses to inherit. The next layers of the trees are CMD and Connectors and then children of the CMD and Connectors are Exit,And, Or, and Semicolon. During the assignment 2 sprint, we made new adjustments on the UML diagram. We added an another class called cmdTranslator. The main goal for the cmdTranslator is to convert string tokens into objects. With this conversion, we can use the token objects to call the connector's children (And, Or, Semicolon) to execute the boolean condition. In the assignment 3 sprint,  we modified our CmdTranslator to handle parentheses and created a testCmd class to check if a flag or directory or both exists. If the user wants to add parentheses with valid commands then our R shell will execute the commands based its precedence. 

As the following diagram demonstrates:

## UML Diagram 

![assignment 3](https://user-images.githubusercontent.com/43591097/49252229-4cb1b400-f3d8-11e8-8ad7-cdd03313c0c6.png)

 
## Known Bugs

There were several problems we encountered  in the command input

1. The program might not be able to handle string literals in the command input 
 
2. Cd is not part of bin file diectory so cd won't work as a command  

3. Nested parentheses may not parse correctly 

4. Nested Bracket displays a different error message than the bash error message 

5. File name sizes that are too long may not work in the TestCmd class

6. It doesn't work on file names that have spaces in the file name

7. Error with brackets when used in some situations  


## Authors & Contributor List

* Brandon Tran - https://github.com/B-Tran

* Christian Campos - https://github.com/ccamp032

All other known bugs and fixes can be sent to btran054@ucr.edu and ccamp032@ucr.edu 

Reported bugs and fixes will be submitted to correction
