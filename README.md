
# Assignment: C-- Interpreter Project

This is the C-- Interpreter Project which was assigned to the batch of IM.tech 2022 in our 3rd Semester by Prof. Vivek Yadav in programming-2 course to familiarize us with low level programming in C and C++.

## Features
- This interpreter is written in C programming language and is capable of reading your dynamic code which you can write in the main.c file and pass it to the interpreter. Your code is passed as a character array to the interpreter.

- This is a basic interpreter which supports all basic arithmetic operations like +, /, *, -

- This interpreter also supports upto 2000 different variables in a single program. The variable array size is also made dynamic using the realloc function available in C which reallocates the memory to a bigger array if the given array is full.
- The interpreter can also evaluate basic true and false conditions like >, <, <=, >=
- The interpreter also supports print statment with a default new line feature.
- This project contains a Makefile which will help you to run and compile the project easily.


## Run Locally

Clone the project

```bash
  git clone https://github.com/varnit-mittal/Cmm.git
```

Go to the project directory

```bash
  cd Cmm
```

Actiavte your linux terminal or WSL and use Makefile to make an executable

```bash
  make
```

Run the program

```bash
  ./my_program
```


## Authors

- [@varnit-mittal](https://github.com/varnit-mittal)


## License

[MIT](https://choosealicense.com/licenses/mit/)

