#include "DNA.h"

int main(int argc, char** argv)
{
  DNA *dna = new DNA(); // Create an instance of DNA object

  int totalSum = 0; // finds the sum of valid characters
  double mean = 0; // variable used for the mean
  double variance = 0; // variable used to calculate the variance
  double standardDeviation = 0; // variable for standard deviation

  // Checks to see if there was 2 parameters in the console. If not then it prompts
  // the user it was invalid and exits
  if (argc < 2)
  {
    cout << "Invalid command line parameters" << endl;

    return 1;
  }



  ifstream inFS; // input file
  string fName = argv[1]; // assign the file name to a variable from the console

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
    string line = "\0"; // The current line in the file
    string lineTotal = "\0"; // This will be used to see how many total characters are in each line

    int charCounter = 0; // counts the characters in each line inside the first upcoming for loop
    int lineCounter = 0; // counts the lines in the file


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
          lineTotal += "A"; // Adds an 'A' to the line total
        }
        else if (line[i] == 'T')
        {
          charCounter++;
          lineTotal += "T"; // Adds an 'T' to the line total
        }
        else if (line[i] == 'G')
        {
          charCounter++;
          lineTotal += "G"; // Adds an 'G' to the line total
        }
        else if (line[i] == 'C')
        {
          charCounter++;
          lineTotal += "C"; // Adds an 'C' to the line total
        }
        else
        {
          continue;
        }
      }
      lineCounter++;

      lineTotal += "o"; // I put an 'o' inside the string to separate each line of characters in each line

      totalSum = dna->getSum(charCounter); // gets the total sum of characters
    }

    mean = dna->getMean(totalSum, lineCounter); // calls onto the getMean function to calculate the mean


    int dnaLineCounter = 0; // Use this as a line counter when iterating through the lineTotal string
    for (int i = 0; i < lineTotal.size(); ++i)
    {
      // if an 'o' shows up in the string, it calls onto variance and adds the value
      if (lineTotal[i] == 'o')
      {
        variance += dna->getVariance(dnaLineCounter, mean);
        dnaLineCounter = 0; // it is set back to zero to represent a new line in the string
      }
      else
      {
        dnaLineCounter++;
      }
    }

    standardDeviation = dna->getStandardDeviation(variance);


    cout << "Program Successful!" << endl;

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
    outFS << endl;


    // The rest of the statistics will go here
    outFS << "Sum: " << totalSum << endl;
    outFS << "Mean: " << mean << endl;
    outFS << "Variance: " << variance << endl;
    outFS << "Standard Deviation: " << standardDeviation << endl;

    outFS.close();
  }

  delete dna; // Deletes the object in heap memory to not have memory leak

  return 0;
}
