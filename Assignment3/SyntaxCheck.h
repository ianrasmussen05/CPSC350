// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 3
// SyntaxCheck.h

// It is bad practice to have the includes inside the header files, so I went with
// the 'if not defined' and 'define' operations to check if the file is defined previous
// to it being compiled
// https://www.cprogramming.com/reference/preprocessor/ifndef.html
#ifndef _SYNTAXCHECK_H
#define _SYNTAXCHECK_H


class SyntaxCheck
{
  private:
    string fileName; // The name of the file that will be used
    GenStack<char> *stack; // A stack that is set to a char value, to be used as an array

  public:
    SyntaxCheck(); // Default constructor
    ~SyntaxCheck(); // Destructor

    void inputFile(); // This is used to get the users input on a file
    void readFile(string fileName); // Function that reads from a file and checks syntax

    string getFile(); // The getter of the file
    void setFile(string fileName); // The setter of the file
};

// This is how you end the #define operation above to let the compiler know the
// class has ended
#endif
