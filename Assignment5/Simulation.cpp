// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// Simulation.cpp

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "BinarySearchTree.h"
#include "LinkedList.h"
#include "Student.h"
#include "Faculty.h"
#include "Simulation.h"

Simulation::Simulation()
{
  studentFile = "\0";
  facultyFile = "\0";
  studentTree = new BinarySearchTree<Student*>();
  facultyTree = new BinarySearchTree<Faculty*>();
}

Simulation::~Simulation()
{
  delete studentTree;
  delete facultyTree;
}

void Simulation::readStudentFile()
{
  string file = getStudentFile();

  ifstream inFS;

  inFS.open(file);

  if (!inFS.is_open())
  {
    cout << "ERROR: Could not open file " << file << endl;
    exit(0);
  }
  else
  {
    string line = "\0";
    int commaCounter = 0; // counts how many commas are on the line
    int lineCounter = 1; // This will be used for error check

    while (getline(inFS, line))
    {
      // This will be error checking to make sure there are enough content to add a student
      for (int i = 0; i < line.size(); ++i)
      {
        if (line[i] == ',')
        {
          commaCounter++;
        }
      }

      if (commaCounter != 5) // 5 is the correct number of commas that should be in each line
      {
        cout << "Error: In line " << lineCounter << ", there isn't the right amount of parameters for the student" << endl;
        exit(0);
      }

      commaCounter = 0;

      // All the variables needed to create a new student
      int studentID = 0;
      string stringID = "\0";
      string name = "\0";
      string level = "\0";
      string major = "\0";
      double gpa = 0.0;
      string stringGPA = "\0";
      int advisor = 0;
      string stringAdvisor = "\0";

      for (int i = 0; i < line.size(); ++i)
      {
        if (line[i] != ',')
        {
          if (commaCounter == 0)
          {
            stringID += line[i];
          }

          if (commaCounter == 1)
          {
            if (line[i+1] != ',')
            {
              name += line[i+1];
            }
          }

          if (commaCounter == 2)
          {
            if (line[i+1] != ',')
            {
              level += line[i+1];
            }
          }

          if (commaCounter == 3)
          {
            if (line[i+1] != ',')
            {
              major += line[i+1];
            }
          }

          if (commaCounter == 4)
          {
            stringGPA += line[i];
          }

          if (commaCounter == 5)
          {
            stringAdvisor += line[i];
          }
        }
        else
        {
          commaCounter++;
          continue;
        }
      }

      studentID = stoi(stringID);
      gpa = stod(stringGPA);
      advisor = stoi(stringAdvisor);


      Student *stud = new Student(studentID, name, level, major, gpa, advisor);
      studentTree->insert(stud);

      lineCounter++;
      commaCounter = 0;
    }

    inFS.close();
  }
}

void Simulation::readFacultyFile()
{
  string file = getFacultyFile();

  ifstream inFS;

  inFS.open(file);

  if (!inFS.is_open())
  {
    cout << "ERROR: Could not open file " << file << endl;
    exit(0);
  }
  else
  {
    string line = "\0";
    int commaCounter = 0; // counts how many commas are on the line
    int lineCounter = 1; // Used for error checking

    while (getline(inFS, line))
    {
      // This will be error checking to make sure there are enough content to add a faculty
      for (int i = 0; i < line.size(); ++i)
      {
        if (line[i] == ',')
        {
          commaCounter++;
        }
      }

      if (commaCounter < 4) // 4 or greater is the correct number of commas that should be in each line
      {
        cout << "Error: In line " << lineCounter << ", there isn't the right amount of parameters for the student" << endl;
        exit(0);
      }

      commaCounter = 0;


      int facultyID = 0;
      string stringID = "\0";
      string name = "\0";
      string level = "\0";
      string department = "\0";
      int adviseeID = 0;
      string stringAdvisee = "\0";
      LinkedList<Student*> *advisees = new LinkedList<Student*>();

      for (int i = 0; i < line.size(); ++i)
      {
        if (line[i] != ',')
        {
          if (commaCounter == 0)
          {
            stringID += line[i];
          }

          if (commaCounter == 1)
          {
            if (line[i+1] != ',')
            {
              name += line[i+1];
            }
          }

          if (commaCounter == 2)
          {
            if (line[i+1] != ',')
            {
              level += line[i+1];
            }
          }

          if (commaCounter == 3)
          {
            if (line[i+1] != ',')
            {
              department += line[i+1];
            }
          }

          if (commaCounter >= 4)
          {
            stringAdvisee += line[i];
          }
        }
        else
        {
          if (commaCounter >= 4)
          {
            adviseeID = stoi(stringAdvisee);
            stringAdvisee = "\0";

            TreeNode<Student*> *temp = studentTree->getRoot();

            while (temp != NULL)
            {
              if (adviseeID < temp->key->getID())
              {
                temp = temp->left;
              }
              else if (adviseeID > temp->key->getID())
              {
                temp = temp->right;
              }
              else
              {
                advisees->insertFront(temp->key);
                break;
              }

              if (temp == NULL)
              {
                cout << "The student does not exist" << endl;
                exit(0);
              }
            }
          }

          commaCounter++;
          continue;
        }
      }

      facultyID = stoi(stringID);


      Faculty *fact = new Faculty(facultyID, name, level, department, advisees);
      facultyTree->insert(fact);


      lineCounter++;
      commaCounter = 0;
    }

    inFS.close();
  }
}

void Simulation::printAllStudents(TreeNode<Student*> *n)
{
  if (n != NULL)
  {
    printAllStudents(n->left);
    cout << "ID: " << n->key->getID() << ", Name: " << n->key->getName();
    cout << ", Level: " << n->key->getLevel() << ", Major: " << n->key->getMajor();
    cout << ", GPA: " << n->key->getGPA() << ", Advisor ID: " << n->key->getAdvisor() << endl;
    printAllStudents(n->right);
  }

  cout << endl;
}

void Simulation::printAllFaculty(TreeNode<Faculty*> *n)
{
  if (n != NULL)
  {
    printAllFaculty(n->left);
    cout << "ID: " << n->key->getID() << ", Name: " << n->key->getName();
    cout << ", Level: " << n->key->getLevel() << ", Major: " << n->key->getDepartment();
    cout << ", List of Advisees: ";

    ListNode<Student*> *curr = n->key->getListOfStudents()->getFront();
    while(curr != NULL)
    {
      cout << curr->data->getID() << " ";
      curr = curr->next;
    }

    printAllFaculty(n->right);
  }

  cout << endl;
}

void Simulation::findStudent(int id)
{
  getStudentTree();

  TreeNode<Student*> *temp = studentTree->getRoot();

  while (temp != NULL)
  {
    if (id < temp->key->getID())
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID())
    {
      temp = temp->right;
    }
    else
    {
      cout << "ID: " << temp->key->getID() << ", Name: " << temp->key->getName();
      cout << ", Level: " << temp->key->getLevel() << ", Major: " << temp->key->getMajor();
      cout << ", GPA: " << temp->key->getGPA() << ", Advisor ID: " << temp->key->getAdvisor() << endl;
      cout << endl;

      runProgram();
    }

    if (temp == NULL)
    {
      cout << "The student does not exist" << endl;
      exit(0);
    }
  }
}

void Simulation::findFaculty(int id)
{
  getFacultyTree();

  TreeNode<Faculty*> *temp = facultyTree->getRoot();

  while (temp != NULL)
  {
    if (id < temp->key->getID())
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID())
    {
      temp = temp->right;
    }
    else
    {
      cout << "ID: " << temp->key->getID() << ", Name: " << temp->key->getName();
      cout << ", Level: " << temp->key->getLevel() << ", Major: " << temp->key->getDepartment();
      cout << ", List of Advisees: ";

      ListNode<Student*> *curr = temp->key->getListOfStudents()->getFront();
      while(curr != NULL)
      {
        cout << curr->data->getID() << " ";
        curr = curr->next;
      }

      cout << endl;

      runProgram();
    }


    if (temp == NULL)
    {
      cout << "The student does not exist" << endl;
      exit(0);
    }
  }
}

void Simulation::printAdvisor(int id)
{
  getStudentTree();

  TreeNode<Student*> *temp = studentTree->getRoot();

  while (temp != NULL)
  {
    if (id < temp->key->getID())
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID())
    {
      temp = temp->right;
    }
    else
    {
      cout << "Advisor ID: " << temp->key->getAdvisor() << endl;
      cout << endl;

      runProgram();
    }

    if (temp == NULL)
    {
      cout << "The student does not exist" << endl;
      exit(0);
    }
  }
}

void Simulation::printAdvisees(int id)
{
  getFacultyTree();

  TreeNode<Faculty*> *temp = facultyTree->getRoot();

  while (temp != NULL)
  {
    if (id < temp->key->getID())
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID())
    {
      temp = temp->right;
    }
    else
    {
      cout << "List of Advisees: ";

      ListNode<Student*> *curr = temp->key->getListOfStudents()->getFront();
      while(curr != NULL)
      {
        cout << curr->data->getID() << " ";
        curr = curr->next;
      }

      cout << endl;
      cout << endl;

      runProgram();
    }


    if (temp == NULL)
    {
      cout << "The student does not exist" << endl;
      exit(0);
    }
  }
}

void Simulation::addStudent()
{

}

void Simulation::deleteStudent(int id)
{

}

void Simulation::addFaculty()
{

}

void Simulation::deleteFaculty(int id)
{

}

void Simulation::changeAdvisor(int studentID, int facultyID)
{

}

void Simulation::removeAdvisee(int studentID, int facultyID)
{

}

void Simulation::rollBack()
{

}


// This is where all the functions are put into one method
void Simulation::runProgram()
{
  readStudentFile();
  readFacultyFile();

  cout << "---------------Welcome to the School Database---------------" << endl;

  int userInput = 0;

  while (true)
  {
    cout << endl;
    cout << "1. Print all students in the database" << endl;
    cout << "2. Print all faculty in the database" << endl;
    cout << "3. Find student" << endl;
    cout << "4. Find faculty" << endl;
    cout << "5. Find advisor given the student ID" << endl;
    cout << "6. Find the advisees given the faculty ID" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor" << endl;
    cout << "12. Remove an advisee from a faculty member" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << endl;

    cout << "Enter a number: " << endl;
    cin >> userInput; // Put a try catch statement
    cout << endl;

    if (userInput == 1)
    {
      getStudentTree();

      TreeNode<Student*> *temp = studentTree->getRoot();

      printAllStudents(temp);
    }
    else if (userInput == 2)
    {
      getFacultyTree();

      TreeNode<Faculty*> *temp = facultyTree->getRoot();

      printAllFaculty(temp);
    }
    else if (userInput == 3)
    {
      cout << "Student ID number: ";
      cin >> userInput; // Try catch here

      findStudent(userInput);
    }
    else if (userInput == 4)
    {
      cout << "Faculty ID number: ";
      cin >> userInput; // Try catch here

      findFaculty(userInput);
    }
    else if (userInput == 5)
    {
      cout << "Student ID number: ";
      cin >> userInput; // Try catch here

      printAdvisor(userInput);
    }
    else if (userInput == 6)
    {
      cout << "Faculty ID number: ";
      cin >> userInput; // Try catch here

      printAdvisees(userInput);
    }
    else if (userInput == 7)
    {
      addStudent();
    }
    else if (userInput == 8)
    {
      cout << "Student ID number: ";
      cin >> userInput; // Try catch here

      deleteStudent(userInput);
    }
    else if (userInput == 9)
    {
      addFaculty();
    }
    else if (userInput == 10)
    {
      cout << "Faculty ID number: ";
      cin >> userInput; // Try catch here

      deleteFaculty(userInput);
    }
    else if (userInput == 11)
    {
      int userStudent = 0;
      int userFaculty = 0;

      cout << "Student ID number: ";
      cin >> userStudent; // Try catch here

      cout << "Faculty ID number: ";
      cin >> userFaculty; // Try catch here

      changeAdvisor(userStudent, userFaculty);
    }
    else if (userInput == 12)
    {
      int userStudent = 0;
      int userFaculty = 0;

      cout << "Student ID number: ";
      cin >> userStudent; // Try catch here

      cout << "Faculty ID number: ";
      cin >> userFaculty; // Try catch here

      removeAdvisee(userStudent, userFaculty);
    }
    else if (userInput == 13)
    {
      rollBack();
    }
    else if (userInput == 14)
    {
      cout << "Exiting program..." << endl;
      exit(0);
    }
    else
    {
      cout << "ERROR: Enter a valid input..." << endl;
    }

    userInput = 0;
  }
}


// Getters
string Simulation::getStudentFile()
{
  return studentFile;
}

string Simulation::getFacultyFile()
{
  return facultyFile;
}

BinarySearchTree<Student*> *Simulation::getStudentTree()
{
  return studentTree;
}

BinarySearchTree<Faculty*> *Simulation::getFacultyTree()
{
  return facultyTree;
}

// Setters
void Simulation::setStudentFile(string studentFile)
{
  this->studentFile = studentFile;
}

void Simulation::setFacultyFile(string facultyFile)
{
  this->facultyFile = facultyFile;
}
