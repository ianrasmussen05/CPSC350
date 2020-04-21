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

    Queue<Student*> *list;
    Window *window;

  public:
    Simulation();
    Simulation(string file);
    ~Simulation();

    void readFromFile();
    void runProgram();
    void statistics();

    // Setters for private variables
    void setFileName(string fileName);
    void setWindowsOpen(int windowsOpen);
    void setTime(int time);
    void setStudentsArrive(int studentsArrive);
    void setMinAtWindow(int minAtWindow);
    void *setList(Queue<Student*> *list);

    // Getters for private variables
    string getFileName();
    int getWindowsOpen();
    int getTime();
    int getStudentsArrive();
    int getMinAtWindow();
    Queue<Student*> *getList();
};

#endif
