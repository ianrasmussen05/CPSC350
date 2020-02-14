#include "DNA.h"

DNA::DNA()
{

}

DNA::~DNA()
{
  cout << "Deleted object" << endl;
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

double DNA::getVariance(int charCount, int lineNumber, double mean)
{
  int total = 0;

  for (int i = 0; i < lineNumber; ++i)
  {
    total += (charCount - mean) * (charCount - mean);
  }

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
