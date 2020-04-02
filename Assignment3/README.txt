Ian Rasmussen
2317200
irasmussen@chapman.edu
CPSC 350-01
Assignment 3

Source Files:
GenStack.h, GenStack.cpp, SyntaxCheck.h, SyntaxCheck.cpp, main.cpp

Challenges:
The entire assignment runs and works on any file. I thought by creating a new makefile that
compiled each pair of .h and .cpp would help with the linking between the template classes. However,
I was just missing a single line of code at the end of my GenStack.cpp. In resources, I go more into
detail about my challenges.

Resources:
I used the textbook and the first [1] link below to get a better understanding of template classes. I used the
third [3] link to use a better makefile that gets a .o for each .cpp file. I was getting an error
that said undefined reference, however I used the second [2] link to put all my implementations onto the header
file rather than a .cpp. After further work and researching, I realized I could have my template functions
inside a .cpp file. In my GenStack.cpp, looking at the very last line, I figured out that my template
header file wasn't linking with my .cpp file was because I needed one line of code [5] and got it from this
website.

Textbook: Data Structures & Algorithms in C++ by Michael T. Goodrich
[1]http://users.cis.fiu.edu/~weiss/Deltoid/vcstl/templates
[2]https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
[3]https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
[4]https://www.cprogramming.com/reference/preprocessor/ifndef.html
[5]https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file
