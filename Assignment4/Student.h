#ifndef _STUDENT_H
#define _STUDENT_H

class Student
{
  private:
    // No private variables

  public:
    Student();
    Student(int needed, int arrived);
    ~Student();

    int timeNeeded;
    int timeArrived;
};

#endif
