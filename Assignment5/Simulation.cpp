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


// Constructor
Simulation::Simulation()
{
  studentFile = "\0";
  facultyFile = "\0";
  studentTree = new BinarySearchTree<Student*>();
  facultyTree = new BinarySearchTree<Faculty*>();
}

// Destructor
Simulation::~Simulation()
{
  delete studentTree;
  delete facultyTree;
}

// This function reads from the file "studentTable.txt" and goes by each line and
// inputs the values into a student which then goes into the student tree
void Simulation::readStudentFile()
{
  string file = getStudentFile(); // Get name of file

  ifstream inFS;

  inFS.open(file);

  if (!inFS.is_open()) // Check if file opens properly
  {
    cout << "ERROR: Could not open file " << file << endl;
    exit(0);
  }
  else // File is good
  {
    string line = "\0";
    int commaCounter = 0; // counts how many commas are on the line
    int lineCounter = 1; // This will be used for error check

    while (getline(inFS, line)) // Iterates through each line in file
    {
      // This will be error checking to make sure there are enough content to add a student
      for (unsigned int i = 0; i < line.size(); ++i)
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

      for (unsigned int i = 0; i < line.size(); ++i) // Goes through entire line
      {
        if (line[i] != ',')
        {
          if (commaCounter == 0) // Gets the id
          {
            stringID += line[i];
          }

          if (commaCounter == 1) // Gets the name of student
          {
            if (line[i+1] != ',')
            {
              name += line[i+1];
            }
          }

          if (commaCounter == 2) // Gets the Level of student
          {
            if (line[i+1] != ',')
            {
              level += line[i+1];
            }
          }

          if (commaCounter == 3) // Gets the major of student
          {
            if (line[i+1] != ',')
            {
              major += line[i+1];
            }
          }

          if (commaCounter == 4) // Gets the gpa of student
          {
            stringGPA += line[i];
          }

          if (commaCounter == 5) // Gets the advisors ID
          {
            stringAdvisor += line[i];
          }
        }
        else
        {
          commaCounter++; // Counts number of commas
          continue;
        }
      }

      // Must change the strings to integers or doubles for new student
      studentID = stoi(stringID);
      gpa = stod(stringGPA);
      advisor = stoi(stringAdvisor);

      // Create instance of new student
      Student *stud = new Student(studentID, name, level, major, gpa, advisor);
      studentTree->insert(stud); // Insert new student into tree

      lineCounter++;
      commaCounter = 0;
    }

    inFS.close(); // Must close file
  }
}

// This function reads from the file "facultyTable.txt" and iterates through each
// line in the file to add to a faculty member. Which then goes into the faculty tree.
void Simulation::readFacultyFile()
{
  string file = getFacultyFile(); // Get the faculty file

  ifstream inFS;

  inFS.open(file);

  if (!inFS.is_open()) // Checks if the file opens properly
  {
    cout << "ERROR: Could not open file " << file << endl;
    exit(0);
  }
  else // The file opens
  {
    string line = "\0";
    int commaCounter = 0; // counts how many commas are on the line
    int lineCounter = 1; // Used for error checking

    while (getline(inFS, line)) // Goes through each line
    {
      // This will be error checking to make sure there are enough content to add a faculty
      for (unsigned int i = 0; i < line.size(); ++i)
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

      commaCounter = 0; // Sets it back to 0


      int facultyID = 0;
      string stringID = "\0";
      string name = "\0";
      string level = "\0";
      string department = "\0";
      int adviseeID = 0;
      string stringAdvisee = "\0";
      LinkedList<Student*> *advisees = new LinkedList<Student*>();

      for (unsigned int i = 0; i < line.size(); ++i) // Goes through the entire line
      {
        if (line[i] != ',')
        {
          if (commaCounter == 0) // Gets the id of faculty
          {
            stringID += line[i];
          }

          if (commaCounter == 1) // Gets the name of the faculty member
          {
            if (line[i+1] != ',')
            {
              name += line[i+1];
            }
          }

          if (commaCounter == 2) // Gets the level of the faculty member
          {
            if (line[i+1] != ',')
            {
              level += line[i+1];
            }
          }

          if (commaCounter == 3) // Gets the faculty members department
          {
            if (line[i+1] != ',')
            {
              department += line[i+1];
            }
          }

          if (commaCounter >= 4) // Gets the advisees
          {
            stringAdvisee += line[i];
          }
        }
        else // If the character is a comma
        {
          if (commaCounter >= 4) // Checks to see if there are more than one advisee
          {
            adviseeID = stoi(stringAdvisee);
            stringAdvisee = "\0";

            int adviseeCounter = 0;

            TreeNode<Student*> *temp = studentTree->getRoot();

            while (temp != NULL) // Goes through to see if the advisee exists
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
                advisees->insertFront(temp->key); // Once found, insert into the list
                break;
              }

              if (temp == NULL && adviseeCounter == 0)
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

      // Create a faculty member
      Faculty *fact = new Faculty(facultyID, name, level, department, advisees);
      facultyTree->insert(fact); // Insert faculty into faculty tree


      lineCounter++;
      commaCounter = 0;
    }

    inFS.close(); // Close file
  }
}

// Prints all the students in-order, from least to greatest ID
void Simulation::printAllStudents(TreeNode<Student*> *n)
{
  if (n != NULL) // Checks if the tree is empty
  {
    printAllStudents(n->left);
    cout << "ID: " << n->key->getID() << ", Name: " << n->key->getName();
    cout << ", Level: " << n->key->getLevel() << ", Major: " << n->key->getMajor();
    cout << ", GPA: " << n->key->getGPA() << ", Advisor ID: " << n->key->getAdvisor() << endl;
    printAllStudents(n->right);
  }
}

// Prints all the faculty in-order, from least to greatest ID
void Simulation::printAllFaculty(TreeNode<Faculty*> *n)
{
  if (n != NULL) // Checks if the tree is empty
  {
    printAllFaculty(n->left);
    cout << "ID: " << n->key->getID() << ", Name: " << n->key->getName();
    cout << ", Level: " << n->key->getLevel() << ", Major: " << n->key->getDepartment();
    cout << ", List of Advisees: ";

    ListNode<Student*> *curr = n->key->getListOfStudents()->getFront();
    while(curr != NULL) // This prints the list of advisees
    {
      cout << curr->data->getID() << " ";
      curr = curr->next;
    }

    cout << endl;

    printAllFaculty(n->right);
  }
}

// Find a student in the tree given the ID
void Simulation::findStudent(int id)
{
  getStudentTree(); // Get the student tree

  TreeNode<Student*> *temp = studentTree->getRoot();

  while (temp != NULL) // Iterate through the tree to find the student with same ID
  {
    if (id < temp->key->getID()) // Goes to left child node
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID()) // Goes to right child node
    {
      temp = temp->right;
    }
    else // Print out the students info
    {
      cout << "ID: " << temp->key->getID() << ", Name: " << temp->key->getName();
      cout << ", Level: " << temp->key->getLevel() << ", Major: " << temp->key->getMajor();
      cout << ", GPA: " << temp->key->getGPA() << ", Advisor ID: " << temp->key->getAdvisor() << endl;
      cout << endl;

      break;
    }

    if (temp == NULL) // If the student doesn't exist
    {
      cout << "The student does not exist" << endl;
      exit(0);
    }
  }
}

// Finds the faculty member given the ID of the faculty, then prints out their info
void Simulation::findFaculty(int id)
{
  getFacultyTree(); // Gets the faculty tree

  TreeNode<Faculty*> *temp = facultyTree->getRoot();

  while (temp != NULL) // Iterate through each node to find the matching one
  {
    if (id < temp->key->getID()) // Goes to left child node
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID()) // Goes to right child node
    {
      temp = temp->right;
    }
    else // Finds the corresponding faculty memeber and prints info
    {
      cout << "ID: " << temp->key->getID() << ", Name: " << temp->key->getName();
      cout << ", Level: " << temp->key->getLevel() << ", Major: " << temp->key->getDepartment();
      cout << ", List of Advisees: ";

      ListNode<Student*> *curr = temp->key->getListOfStudents()->getFront();
      while(curr != NULL) // Print the advisees in the list
      {
        cout << curr->data->getID() << " ";
        curr = curr->next;
      }

      cout << endl;

      break;
    }


    if (temp == NULL) // If the faculty member doesn't exist
    {
      cout << "The student does not exist" << endl;
      runProgram();
    }
  }
}

// This function prints the students advisor's info given the id of the student
void Simulation::printAdvisor(int id)
{
  getStudentTree(); // Must get the student tree

  TreeNode<Student*> *temp = studentTree->getRoot();

  while (temp != NULL) // Must find student
  {
    if (id < temp->key->getID()) // Goes to the left
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID()) // Goes to the right
    {
      temp = temp->right;
    }
    else // Found the student, prints advisor
    {
      cout << "Advisor ID: " << temp->key->getAdvisor() << endl;
      cout << endl;

      runProgram();
    }

    if (temp == NULL) // Doesn't find student
    {
      cout << "The student does not exist" << endl;
      runProgram();
    }
  }
}

// This function prints the faculty's advisees info given the faculty's id
void Simulation::printAdvisees(int id)
{
  getFacultyTree(); // Must get faculty tree

  TreeNode<Faculty*> *temp = facultyTree->getRoot();

  while (temp != NULL) // Find the corresponding faculty member
  {
    if (id < temp->key->getID()) // Go left
    {
      temp = temp->left;
    }
    else if (id > temp->key->getID()) // Go right
    {
      temp = temp->right;
    }
    else // Found the faculty
    {
      cout << "List of Advisees: ";

      ListNode<Student*> *curr = temp->key->getListOfStudents()->getFront();
      while(curr != NULL) // Prints all advisees
      {
        cout << curr->data->getID() << " ";
        curr = curr->next;
      }

      cout << endl;
      cout << endl;

      runProgram();
    }


    if (temp == NULL) // If the faculty member doesn't exist in database
    {
      cout << "The student does not exist" << endl;
      runProgram();
    }
  }
}

// Add a student to the database, asks for all info needed to create a new student
// then adds it into the student tree
void Simulation::addStudent()
{
  getStudentTree(); // Must get student tree

  // All member variables for the student
  int studentID = 0;
  string sID = "\0";
  string fullName = "\0"; // For the full name of the studen
  string studentNameFirst = "\0";
  string studentNameLast = "\0";
  string studentLevel = "\0";
  string studentMajor = "\0";
  double studentGPA = 0.0;
  int studentAdvisor = 0;

  cout << "Adding a Student..." << endl;
  cout << endl;

  cout << "Enter the ID of the student: ";
  cin >> sID;

  try
  {
    studentID = stoi(sID);
  }
  catch (invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl;
    cout << endl;
    runProgram();
  }
  catch (out_of_range const &e)
  {
    cout << "Error: value out of range" << endl;
    cout << endl;
    runProgram();
  }


  cout << "Enter the students name (first and last name): ";
  cin >> studentNameFirst;
  cin >> studentNameLast;

  fullName = studentNameFirst + " " + studentNameLast;

  cout << "Enter the level of the student (Freshman, Sophomore, etc): ";
  cin >> studentLevel; // Error chekcing here

  cout << "Enter the students major: ";
  cin >> studentMajor; // Error checking here

  cout << "Enter the students GPA: ";
  cin >> studentGPA;

  cout << "Enter the students advisor ID: ";
  cin >> studentAdvisor;

  // Create new instance of student
  Student *addStudent = new Student(studentID, fullName, studentLevel, studentMajor, studentGPA, studentAdvisor);

  studentTree->insert(addStudent); // Add the student to the tree in real time

  // This adds the student to the database or file
  ofstream outFS;
  string file = getStudentFile();

  outFS.open(file, ios::app); // This appends to the file

  if (!outFS.is_open()) // Checks if file opens properly
  {
    cout << "ERROR: Could not open file " << file << endl;
    exit(0);
  }
  else // File opens, so it prints to file
  {
    outFS << studentID << ", " << fullName << ", "
          << studentLevel << ", " << studentMajor << ", "
          << studentGPA << ", " << studentAdvisor << "\n";
  }

  outFS.close(); // Close file

  cout << "Student Successfully Added to Database" << endl;
  cout << endl;
}

// This function deletes a student given the students id
void Simulation::deleteStudent(int id)
{

}

// Adds a faculty to the database, asks the user for the users needed inputs
// and outputs it to a file
void Simulation::addFaculty()
{
  getFacultyTree(); // Must get faculty tree

  // All member variables for the faculty
  int facultyID = 0;
  string fID = "\0";
  string fullName = "\0";
  string firstName = "\0";
  string lastName = "\0";
  string facultyLevel = "\0";
  string facultyDepartment = "\0";
  string facultyAdvisees = "\0";
  int adviseeID = 0;
  LinkedList<Student*> *addList = new LinkedList<Student*>();


  cout << "Adding a Faculty..." << endl;
  cout << endl;

  cout << "Enter the ID of the faculty member: ";
  cin >> fID;

  try
  {
    facultyID = stoi(fID);
  }
  catch (invalid_argument const &e)
  {
    cout << "Error: invalid argument" << endl;
    cout << endl;
    runProgram();
  }
  catch (out_of_range const &e)
  {
    cout << "Error: value out of range" << endl;
    cout << endl;
    runProgram();
  }


  cout << "Enter the faculty's name (first and last name): ";
  cin >> firstName; // Error checking here
  cin >> lastName;
  fullName = firstName + " " + lastName;

  cout << "Enter the faculty's level (lecturer, assistant professor, etc.): ";
  cin >> facultyLevel; // Error checking here

  cout << "Enter the faculty's department: ";
  cin >> facultyDepartment; // Error checking here

  cout << "Does the faculty member have any advisees? (y/n): ";
  cin >> facultyAdvisees;

  // This will keep iterating if the faculty has advisees
  while (facultyAdvisees[0] == 'y')
  {
    cout << "What is the advisee ID: ";
    cin >> adviseeID; // Error checking


    TreeNode<Student*> *temp = studentTree->getRoot();

    while (temp != NULL) // Iterates to check if the student exists
    {
      if (adviseeID < temp->key->getID()) // Goes left
      {
        temp = temp->left;
      }
      else if (adviseeID > temp->key->getID()) // Goes right
      {
        temp = temp->right;
      }
      else // Finds student
      {
        addList->insertFront(temp->key); // Adds the student to the list
        break;
      }

      if (temp == NULL) // If the student doesn't exist
      {
        cout << "The student does not exist" << endl;
      }
    }


    cout << "Would you like to add another student? (y/n)";
    cin >> facultyAdvisees;
    cout << endl;
  }

  // Create new instance of faculty member
  Faculty *newFaculty = new Faculty(facultyID, fullName, facultyLevel, facultyDepartment, addList);
  facultyTree->insert(newFaculty); // Add it to the faculty tree

  // Now must append to text file
  string file = getFacultyFile();
  ofstream outFS;

  outFS.open(file, ios::app); // How you append to a file

  if (!outFS.is_open()) // Checks if the file opened correcly
  {
    cout << "ERROR: Could not open file " << file << endl;
    exit(0);
  }
  else // File opened successfully, outputs data to the file
  {
    outFS << facultyID << ", " << fullName << ", "
          << facultyLevel << ", " << facultyDepartment << ", ";

    ListNode<Student*> *curr = addList->getFront();
    while (curr != NULL) // Prints list to the file
    {
      outFS << curr->data->getID() << ", ";

      curr = curr->next;
    }

  }

  outFS.close(); // Close file

  cout << "Student Successfully Added to Database" << endl;
  cout << endl;
}

// This deletes the faculty member given the id
void Simulation::deleteFaculty(int id)
{

}

// This changes the students advisor, given the student ID and the new faculty ID
void Simulation::changeAdvisor(int studentID, int facultyID)
{

}

// Removes the student from the advisors list of students, given the student ID and faculty ID
void Simulation::removeAdvisee(int studentID, int facultyID)
{

}

// This function will undo any task that happened previously, by 5 steps
void Simulation::rollBack()
{

}


// This is where all the functions are put into one method
void Simulation::runProgram()
{
  readStudentFile();
  readFacultyFile();

  cout << "---------------Welcome to the School Database---------------" << endl;

  string userInput = "\0";
  int intInput = 0;

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
    cin >> userInput;

    try
    {
      intInput = stoi(userInput); // Converts a string to int
    }
    catch (invalid_argument const &e)
    {
      cout << "Error: invalid argument" << endl;
      cout << endl;
      userInput = "\0";
      runProgram();
    }
    catch (out_of_range const &e)
    {
      cout << "Error: value out of range" << endl;
      cout << endl;
      userInput = "\0";
      runProgram();
    }

    cout << endl;

    if (intInput == 1) // Print all students and information
    {
      getStudentTree();

      TreeNode<Student*> *temp = studentTree->getRoot();

      printAllStudents(temp);
    }
    else if (intInput == 2) // Print all faculty and their information
    {
      getFacultyTree();

      TreeNode<Faculty*> *temp = facultyTree->getRoot();

      printAllFaculty(temp);
    }
    else if (intInput == 3) // Find a student and print their information
    {
      cout << "Student ID number: ";
      cin >> userInput;

      try
      {
        intInput = stoi(userInput); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        userInput = "\0";
        runProgram();
      }


      findStudent(intInput);
    }
    else if (intInput == 4) // Find a faculty memeber and print info
    {
      cout << "Faculty ID number: ";
      cin >> userInput;

      try
      {
        intInput = stoi(userInput); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }

      findFaculty(intInput);
    }
    else if (intInput == 5) // Given student ID, print the students advisor and his/her info
    {
      cout << "Student ID number: ";
      cin >> userInput;

      try
      {
        intInput = stoi(userInput); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }

      printAdvisor(intInput);
    }
    else if (intInput == 6) // Given faculty ID, print the facultys advisees and their info
    {
      cout << "Faculty ID number: ";
      cin >> userInput;

      try
      {
        intInput = stoi(userInput); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }

      printAdvisees(intInput);
    }
    else if (intInput == 7) // Add a new student to database
    {
      addStudent();
    }
    else if (intInput == 8) // Delete a student from the database
    {
      cout << "Student ID number: ";
      cin >> userInput;

      try
      {
        intInput = stoi(userInput); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }

      deleteStudent(intInput);
    }
    else if (intInput == 9) // Add a faculty to the database
    {
      addFaculty();
    }
    else if (intInput == 10) // Delete a faculty member from database given ID
    {
      cout << "Faculty ID number: ";
      cin >> userInput;

      try
      {
        intInput = stoi(userInput); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }

      deleteFaculty(intInput);
    }
    else if (intInput == 11) // Change a students advisor given student ID and new faculty ID
    {
      string userStudent = "\0";
      string userFaculty = "\0";
      int intStudent = 0;
      int intFaculty = 0;

      cout << "Student ID number: ";
      cin >> userStudent;

      try
      {
        intStudent = stoi(userStudent); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }



      cout << "Faculty ID number: ";
      cin >> userFaculty;

      try
      {
        intFaculty = stoi(userFaculty); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }

      changeAdvisor(intStudent, intFaculty);
    }
    else if (intInput == 12) // Remove advisee from Faculty given both ID's
    {
      string userStudent = "\0";
      string userFaculty = "\0";
      int intStudent = 0;
      int intFaculty = 0;


      cout << "Student ID number: ";
      cin >> userStudent;

      try
      {
        intStudent = stoi(userStudent); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }



      cout << "Faculty ID number: ";
      cin >> userFaculty;

      try
      {
        intFaculty = stoi(userInput); // Converts a string to int
      }
      catch (invalid_argument const &e)
      {
        cout << "Error: invalid argument" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }
      catch (out_of_range const &e)
      {
        cout << "Error: value out of range" << endl;
        cout << endl;
        userInput = "\0";
        runProgram();
      }

      removeAdvisee(intStudent, intFaculty);
    }
    else if (intInput == 13) // Rollback function, to undo
    {
      rollBack();
    }
    else if (intInput == 14)
    {
      cout << "Exiting program..." << endl;
      exit(0);
    }
    else
    {
      cout << "ERROR: Enter a valid input..." << endl;
    }

    userInput = "\0";
    intInput = 0;
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
