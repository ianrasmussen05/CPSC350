// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Simulation.h

#ifndef _SIMULATION_H
#define _SIMULATION_H

class Simulation
{
  private:
    string fileName;
    int windowsOpen;
    int time;
    int studentsArrive;
    int minAtWindow;

    Queue<Student*> *queue;
    LinkedList<Student*> *list;
    LinkedList<Student*> *finalList;
    Window *window;

  public:
    Simulation(); // Consturctor
    Simulation(string file); // Overloaded Consturctor
    ~Simulation(); // Destructor

    void readFromFile(); // Function to read from a file
    void runProgram(); // Function that runs the simulation with the specific tasks
    void statistics(); // Function that prints out statistics from runProgram()

    bool allWindowsOpen(); // Checks to see if all the windows are open
    bool allWindowsClosed(); // Checks to see if all windows are closed

    // Setters for private variables
    void setFileName(string fileName);
    void setWindowsOpen(int windowsOpen);
    void setTime(int time);
    void setStudentsArrive(int studentsArrive);
    void setMinAtWindow(int minAtWindow);

    // Getters for private variables
    string getFileName();
    int getWindowsOpen();
    int getTime();
    int getStudentsArrive();
    int getMinAtWindow();
    Queue<Student*> *getQueue();
    LinkedList<Student*> *getList();
};

#endif
