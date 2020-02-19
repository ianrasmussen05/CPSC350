// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 1
// DNA.h

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class DNA
{
public:
  // Constructor and Destructor
  DNA();
  ~DNA();

  // Funcions used to find all statistics
  int getSum(int& size);
  double getMean(int sumNumber, int lineNumber);
  double getVariance(int charCount, double mean);
  double getStandardDeviation(double variance);
  double getRelativeProbabilitySingle(int charNucleotide, int totalChars);
  double getRelativeProbabilityPair(int pair, int totalChars);
private:
  // Nothing to use for private variables
};
