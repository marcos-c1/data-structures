# Data-Structures

All the data structures implementation in C. Some of them I implemented in University and some others in the Internship. They will help me along the journey to become a great programmer.

# Why should we know how to implement them?

Data structures are abstract types of data that will be needed to perform operations on a large amount of data, that is, to store, fetch and delete information in an application, it is necessary to wrap it in a structure that can have an index that points to the specific data, for example.

# Motivation

My goal with this project is to learn how to implement them in the best way possible, using concepts of clean code and refactoring. There will be a lot of changes throughout the creation, and this is the fun part of the project.

# Commands

Make sure to have the make tool installed on your system and them use the "make run" command to compile the code objects and the main file which will be generated. 

# Things you have to know

If you want to test the HashMap algorithm, make sure that you insert into main function the code below:

```c
srand(time(NULL));
```

This will ensure the random generator value inside the hash function, i.e., the seed will be set randomly everytime you build a new node.

There is also a MakeFile and if you do not have the make tool installed in your O.S, make sure to install and them execute the following CLI to compilate the hashlist and hashmap file:

```
$ make run
$ ./hs
```


