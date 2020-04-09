#ifndef _STATISTICS_H
#define _STATISTICS_H

class Statistics
{
  private:
    double mean;
    int median;
    int longestWait;
    int numOfStudentsTen;
    double meanWindow;
    int windowIdle;
    int numOfWindowFive;

  public:
    double getMean();
    int getMedian();

    double getMeanWindow();
}

#endif
