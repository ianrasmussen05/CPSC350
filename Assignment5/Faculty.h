#ifndef _FACULTY_H
#define _FACULTY_H

class Faculty
{
  private:
    int id;
    string name;
    string level;
    string department;
    int numOfStudents;

  public:
    Faculty();
    Faculty(int id, string name, string level, string department, int numOfStudents);
    ~Faculty();

    // Getters
    int getID();
    string getName();
    string getLevel();
    string getDepartment();
    int getNumOfStudents();

    // Setters
    void setID(int id);
    void setName(string name);
    void setLevel(string level);
    void setDepartment(string department);
    void setNumOfStudents(int numOfStudents);
};

#endif
