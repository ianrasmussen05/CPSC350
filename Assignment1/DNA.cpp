// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 1
// DNA.cpp

#include "DNA.h"

DNA::DNA()
{

}

DNA::~DNA()
{

}

int DNA::getSum(int& size)
{
  return size;
}

double DNA::getMean(int sumNumber, int lineNumber)
{
  double total = (double)sumNumber/lineNumber;

  return total;
}

double DNA::getVariance(int charCount, double mean)
{
  double total = 0;

  total = (charCount - mean) * (charCount - mean);

  return total;
}

double DNA::getStandardDeviation(double variance)
{
  double standardDeviation = 0;

  standardDeviation = sqrt(variance);

  return standardDeviation;
}

int DNA::getRelativeProbability()
{
  return 0;
}
