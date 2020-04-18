#include <iostream>
#include <string>

using namespace std;

#include "Student.h"

Student::Student()
{
  timeNeeded = 0;
  timeArrived = 0;
}

Student::Student(int needed, int arrived)
{
  timeNeeded = needed;
  timeArrived = arrived;
}

Student::~Student()
{

}
