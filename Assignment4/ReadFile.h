#ifndef _READFILE_H
#define _READFILE_H

class ReadFile
{
  private:
    string fileName;
    int windowsOpen;
    int time;
    int studentsArrive;
    int minAtWindow;

  public:
    ReadFile();
    ReadFile(string file);
    ~ReadFile();

    void readFromFile(string file);

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
};

#endif
