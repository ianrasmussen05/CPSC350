#include "quiz1.h"

int main(int argc, char** argv)
{
  // Checks to see if there are more than 1 command argument to run the following code
  if (argc > 1)
  {
    string userInput = argv[1]; // Uses the second value from the command line

    //Quiz1 q1; // Stored on the stack
    Quiz1 *q1 = new Quiz1(); // Stored on the heap

    // This gets user input
    /*
    cout << "Enter a string: ";
    cin >> userInput;
    */

    cout << "Number of command line arguments: " << argc << endl;

    // int count = q1.countVowels(userInput); // uses the memory on the stack
    int count = q1->countVowels(userInput); // uses memory on the heap

    cout << "There are " << count << " vowels in " << userInput << endl;

    delete q1;
  }
  else
  {
    cout << "Invalid number of commands" << endl;
    cout << "Please add another command" << endl;
  }

  return 0;
}
