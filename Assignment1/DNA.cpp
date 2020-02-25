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
  // Nothing to declare in the Constructor
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

// This is the box muller method that takes two random numbers from [0,1) and returns the total
// for the equation. Uses the '&' operator to update the variable assigned to this function.
double DNA::getBoxMuller(double &rand1, double &rand2)
{
  double c = 0.0;
  double pi = 3.14159;

  c = (sqrt(-2 * log(rand1))) * (cos(2 * pi * rand2));

  return c;
}

// This is the gaussian method that takes the box muller total, mean, and standard deviation
// as input and returns the product of the three. Makes sure there is no negative numbers.
double DNA::getGaussian(double boxMuller, double mean, double standardDeviation)
{
  double d = 0.0;

  d = (standardDeviation * boxMuller) + mean;

  // This makes sure the value is always positive
  if (d < 0)
  {
    d *= -1;
  }

  return d;
}
