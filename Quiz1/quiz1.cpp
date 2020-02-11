#include "quiz1.h"

Quiz1::Quiz1()
{

}

Quiz1::~Quiz1()
{
  cout << "Object Deleted" << endl;
}

int Quiz1::countVowels(string input)
{
  int counter = 0;

  for (int i = 0; i < input.size(); ++i)
  {
    char strInput = tolower(input[i]); // lower cases all characters

    if (strInput == 'a')
    {
      counter++;
    }
    else if (strInput == 'e')
    {
      counter++;
    }
    else if (strInput == 'i')
    {
      counter++;
    }
    else if (strInput == 'o')
    {
      counter++;
    }
    else if (strInput == 'u')
    {
      counter++;
    }
    else
    {
      continue;
    }
  }

  return counter;
}
