// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 1
// DNA.cpp

#include "DNA.h"

// Constructor
DNA::DNA()
{

}

// Destructor
DNA::~DNA()
{
  cout << "Program Successful!" << endl;
}

// This function just changes the sum and updates it into an address to a variable
int DNA::getSum(int& size)
{
  return size;
}

// This gets a parameter of the sum of all characters and divides it by the number of lines
double DNA::getMean(int sumNumber, int lineNumber)
{
  double total = (double)sumNumber / lineNumber;

  return total;
}

// Gets the variance by having a parameter of characters in a line minus the mean. Which is
// then squared.
double DNA::getVariance(int charCount, double mean)
{
  double total = 0;

  total = (charCount - mean) * (charCount - mean);

  return total;
}

// This function gets the variance as a parameter and returns the square root of variance.
double DNA::getStandardDeviation(double variance)
{
  double standardDeviation = 0;

  standardDeviation = sqrt(variance);

  return standardDeviation;
}

// Gets the number of single nucleotide and divides it by the total nucleotides in the file
// Which then returns the percentage in decimal form
double DNA::getRelativeProbabilitySingle(int charNucleotide, int totalChars)
{
  double total = 0;

  total = (double)charNucleotide / totalChars;

  return total;
}

// Gets the number of pair nucleotides and divides it by the total nucleotides in the file
// Which then returns the percentage in decimal form
double DNA::getRelativeProbabilityPair(int pair, int totalChars)
{
  double total = 0;

  total = (pair * 2) / (double)(totalChars); // I multiplied by 2 to represent a pair of characters

  return total;
}
