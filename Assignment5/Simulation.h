// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// Simulation.h

#ifndef _SIMULATION_H
#define _SIMULATION_H

class Simulation
{
  private:
    string studentFile;
    string facultyFile;
    BinarySearchTree<Student*> *studentTree; // Student Tree
    BinarySearchTree<Faculty*> *facultyTree; // Faculty Tree

  public:
    Simulation(); // Constructor
    ~Simulation(); // Destructor

    void readStudentFile(); // Reads student file
    void readFacultyFile(); // Reads faculty file

    void printAllStudents(TreeNode<Student*> *n); // (1) printed out students in ascending order by ID
    void printAllFaculty(TreeNode<Faculty*> *n); // (2) prints out all faculty in ascending order by ID
    void findStudent(int id); // (3) finds a specific student given ID
    void findFaculty(int id); // (4) finds a specific faculty member given the ID
    void printAdvisor(int id); // (5) finds and prints the students advior given the ID
    void printAdvisees(int id); // (6) finds and prints all the students the advior has given the ID
    void addStudent(); // (7) Adds a student to the database
    void deleteStudent(int id); // (8) deletes a student given the ID
    void addFaculty(); // (9) Adds a faculty member to the database
    void deleteFaculty(int id); // (10) deletes a faculty member given the ID
    void changeAdvisor(int studentID, int facultyID); // (11) Change the students advisor id to the new
                                                      // faculty ID. Assigns a new advisor
    void removeAdvisee(int studentID, int facultyID); // (12) Removes a student from the advisors database
    void rollBack(); // (13) Allows the user to undo anything they have done
    // (14) is to exit the program

    void runProgram(); // This runs the entire program using the functions above
    void updateStudentFile(); // This will update and print all the data into the student file
    void updateFacultyFile();// This will update and print all the data into the student file

    string studentPreOrderPrint(TreeNode<Student*> *n, string &s);
    string facultyPreOrderPrint(TreeNode<Faculty*> *n, string &s);

    // Getters
    string getStudentFile();
    string getFacultyFile();
    BinarySearchTree<Student*> *getStudentTree();
    BinarySearchTree<Faculty*> *getFacultyTree();

    // Setters
    void setStudentFile(string studentFile);
    void setFacultyFile(string facultyFile);
};

#endif
