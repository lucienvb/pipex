# pipex

pipex is a command-line program written in C that handles pipes to redirect input and output between shell commands. It allows the user to execute a series of shell commands with their parameters and redirect the input from a file and output to another file.

##

**Installation** <br/>
To compile the pipex program, use the provided Makefile by running the following command in the terminal:
make

This will generate the executable file named pipex. If you want to remove the object files and the executable, you can run:
make clean

##

**Usage** <br/>
The pipex program is executed with the following format:
./pipex file1 cmd1 cmd2 file2

Where:
- file1 and file2 are the input and output file names, respectively.
- cmd1 and cmd2 are the shell commands with their parameters.

The behavior of pipex is identical to the shell command:
< file1 cmd1 | cmd2 > file2

##

**Examples** <br/>
Here are a couple of examples to illustrate the usage of pipex:

$ ./pipex infile "ls -l" "wc -l" outfile

This is equivalent to the shell command:

< infile ls -l | wc -l > outfile

##

$ ./pipex infile "grep a1" "wc -w" outfile

This is equivalent to the shell command:

< infile grep a1 | wc -w > outfile
