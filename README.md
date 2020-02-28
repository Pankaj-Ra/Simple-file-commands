# Simple-file-commands

Alice is writing a program that performs the following terminal commands:

    crt file_name
        Create a file named 

.
If
is already in use, then append (x) to it where
is the lowest positive integer such that the file doesn't already exist. For example, crt a creates file a(2) if a and a(1) already exist.
Print + new_file on a new line, where

    is the new file's name.

del file_name

    Delete the file named 

.
Print - file_name on a new line, where

    is the deleted file's name.

rnm file_name1 file_name2

    Find the file called 

and change the name to (Follow point
of crt command in case of conflict). For the purpose of simplification, you can think this operation as deleting the first file and creating the second file.
Print r file_name1 -> new_file on a new line, where

        is the new file's name.

Assume that the user won't attempt to create a file which contains anything other than lowercase English letters.

Given

commands, execute each command in order.

Input Format

The first line contains an integer,
, denoting the number of commands.
Each of the

subsequent lines contains a command in the format defined above.

Constraints

The given name string for any file to be created consists of a maximum of

    lowercase English letters.
    It's guaranteed that the del and rnm operations will only attempt to delete or rename files that exist.

Subtasks

for
of the maximum score.
for

    of the maximum score.

Output Format

For each command, print the appropriate output per the instructions above.

Sample Input 0

11
crt phonebook
crt phonebook
crt phonebook
crt todo
crt phonebook
del phonebook
del phonebook(2)
crt phonebook
crt phonebook
crt phonebook
rnm phonebook(2) todo

Sample Output 0

+ phonebook
+ phonebook(1)
+ phonebook(2)
+ todo
+ phonebook(3)
- phonebook
- phonebook(2)
+ phonebook
+ phonebook(2)
+ phonebook(4)
r phonebook(2) -> todo(1)

