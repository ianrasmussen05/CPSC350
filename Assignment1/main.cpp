#include "DNA.h"

int main(int argc, char** argv)
{
  DNA *dna = new DNA(); // Create an instance of DNA object

  // Checks to see if there was 2 parameters in the console. If not then it prompts
  // the user it was invalid and exits
  if (argc < 2)
  {
    cout << "Invalid command line parameters" << endl;

    return 1;
  }



  ifstream inFS; // input file
  string fName = argv[1]; // assign the file name to a variable from the console

  cout << "Opening file: " << fName << "..." << endl;
  inFS.open(fName); // Opens the file listed in the console

  // If the file does not open, it then prompts the user it didn't successfully open and exits
  if (!inFS.is_open())
  {
    cout << "Could not open file " << fName << "." << endl;
    return 1;
  }
  // If the file opens then it runs this block of code which reads the lines
  else
  {
    string line = "\0";

    int charCounter = 0;
    int lineCounter = 0;

    int totalSum = 0;
    double mean = 0;
    double variance = 0;


    // Calls a function that gets the files line, then stores it into the line variable
    // stored above and keeps going until there are no more lines.
    while (getline(inFS, line))
    {
      // Makes sure everything is upper case in the string
      for (int i = 0; i < line.size(); ++i)
      {
        line[i] = toupper(line[i]);

        if (line[i] == 'A')
        {
          charCounter++;
        }
        else if (line[i] == 'T')
        {
          charCounter++;
        }
        else if (line[i] == 'G')
        {
          charCounter++;
        }
        else if (line[i] == 'C')
        {
          charCounter++;
        }
        else
        {
          continue;
        }
      }
      lineCounter++;

      totalSum = dna->getSum(charCounter);

      cout << line << endl; // Prints out the values for now
    }

    mean = dna->getMean(totalSum, lineCounter);

    cout << "The sum is " << totalSum << endl;
    cout << "The mean is " << mean << endl;
    cout << "The variance is " << variance << endl;

    cout << "Closing file: " << fName << endl;

    // Done with file so close it
    inFS.close();
  }



  // The rest of the code is outputing to a file
  ofstream outFS; // output file
  string fileOutName = "IanRasmussen.out";

  outFS.open(fileOutName); // opens the file

  // Checks to see if the file opened successfully
  if (!outFS.is_open())
  {
    cout << "Could not open file " << fileOutName << "." << endl;
    return 1;
  }
  else
  {
    // Prints the following out onto the file listed above
    outFS << "Ian Rasmussen" << endl;
    outFS << "2317200" << endl;
    outFS << "irasmussen@chapman.edu" << endl;
    outFS << "CPSC 350-01" << endl;

    // The rest of the statistics will go here


    outFS.close();
  }

  delete dna; // Deletes the object in heap memory to not have memory leak

  return 0;
}
