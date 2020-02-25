// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 1
// main.cpp

#include "DNA.h"

int main(int argc, char** argv)
{
  DNA *dna = new DNA(); // Create an instance of DNA object

  string userInput = "\0";

  // Checks to see if there was 2 parameters in the console. If not then it prompts
  // the user it was invalid and exits
  if (argc < 2)
  {
    cout << "Invalid command line parameters" << endl;

    return 1;
  }

  string fName = argv[1]; // assign the file name to a variable from the console

  while (true)
  {
    int totalSum = 0; // finds the sum of valid characters
    double mean = 0; // variable used for the mean
    double variance = 0; // variable used to calculate the variance
    double standardDeviation = 0; // variable for standard deviation

    // These next few variables will represent the total probability for each nucleotide
    double aProbability = 0;
    double tProbability = 0;
    double gProbability = 0;
    double cProbability = 0;

    // These next variables will represent the total probability for each nucleotide pair
    double aaProbability = 0;
    double atProbability = 0;
    double agProbability = 0;
    double acProbability = 0;
    double ttProbability = 0;
    double taProbability = 0;
    double tgProbability = 0;
    double tcProbability = 0;
    double gaProbability = 0;
    double gtProbability = 0;
    double ggProbability = 0;
    double gcProbability = 0;
    double caProbability = 0;
    double ctProbability = 0;
    double cgProbability = 0;
    double ccProbability = 0;



    ifstream inFS; // input file
    //string fName = argv[1]; // assign the file name to a variable from the console

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

      // These single character counter variables count how many times each nucleotide appears
      int aCounter = 0;
      int tCounter = 0;
      int cCounter = 0;
      int gCounter = 0;

      // These double character counter variables count how many times each set of nuleotides appear
      int aaCounter = 0;
      int atCounter = 0;
      int agCounter = 0;
      int acCounter = 0;
      int ttCounter = 0;
      int taCounter = 0;
      int tgCounter = 0;
      int tcCounter = 0;
      int gaCounter = 0;
      int gtCounter = 0;
      int ggCounter = 0;
      int gcCounter = 0;
      int caCounter = 0;
      int ctCounter = 0;
      int cgCounter = 0;
      int ccCounter = 0;


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
            // These next if statements check to see if the following character in the string matches up
            // with one of the valid characters. Checks every two iterations of 'i'.
            if ((i % 2 == 0) && (line[i+1] == 'A'))
            {
              aaCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'T'))
            {
              atCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'G'))
            {
              agCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'C'))
            {
              acCounter++;
            }

            aCounter++; // Adds one to the counter when 'A' shows up
            charCounter++; // Adds one to the total number of characters
            lineTotal += "A"; // Adds an 'A' to the line total
          }
          else if (line[i] == 'T')
          {
            // These next if statements check to see if the following character in the string matches up
            // with one of the valid characters. Checks every two iterations of 'i'.
            if ((i % 2 == 0) && (line[i+1] == 'A'))
            {
              taCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'T'))
            {
              ttCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'G'))
            {
              tgCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'C'))
            {
              tcCounter++;
            }

            tCounter++; // Adds one to the counter when 'T' shows up
            charCounter++; // Adds one to the total number of characters
            lineTotal += "T"; // Adds an 'T' to the line total
          }
          else if (line[i] == 'G')
          {
            // These next if statements check to see if the following character in the string matches up
            // with one of the valid characters. Checks every two iterations of 'i'.
            if ((i % 2 == 0) && (line[i+1] == 'A'))
            {
              gaCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'T'))
            {
              gtCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'G'))
            {
              ggCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'C'))
            {
              gcCounter++;
            }

            gCounter++; // Adds one to the counter when 'G' shows up
            charCounter++; // Adds one to the total number of characters
            lineTotal += "G"; // Adds an 'G' to the line total
          }
          else if (line[i] == 'C')
          {
            // These next if statements check to see if the following character in the string matches up
            // with one of the valid characters. Checks every two iterations of 'i'.
            if ((i % 2 == 0) && (line[i+1] == 'A'))
            {
              caCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'T'))
            {
              ctCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'G'))
            {
              cgCounter++;
            }
            else if ((i % 2 == 0) && (line[i+1] == 'C'))
            {
              ccCounter++;
            }

            cCounter++; // Adds one to the counter when 'C' shows up
            charCounter++; // Adds one to the total number of characters
            lineTotal += "C"; // Adds an 'C' to the line total
          }
          else
          {
            continue;
          }
        }
        lineCounter++; // Adds one to the counter when the file moves onto the next file

        lineTotal += "o"; // I put an 'o' inside the string to separate each line of characters in each line

        totalSum = dna->getSum(charCounter); // gets the total sum of characters
      }

      mean = dna->getMean(totalSum, lineCounter); // calls onto the getMean function to calculate the mean


      int charInLine = 0; // Use this as a character counter when iterating through the lineTotal string
      for (int i = 0; i < lineTotal.size(); ++i)
      {
        // if an 'o' shows up in the string, it is the the end of the line and it calls onto variance and adds the value
        if (lineTotal[i] == 'o')
        {
          variance += dna->getVariance(charInLine, mean);
          charInLine = 0; // it is set back to zero to represent a new line in the string
        }
        else
        {
          charInLine++;
        }
      }

      variance /= (double)(lineCounter); // Divide the variance by how many lines are in the file

      standardDeviation = dna->getStandardDeviation(variance); // calls onto standard deviation function


      // The probability of each nucleotide calling onto the getRelativeProbability
      aProbability = dna->getRelativeProbabilitySingle(aCounter, charCounter);
      tProbability = dna->getRelativeProbabilitySingle(tCounter, charCounter);
      gProbability = dna->getRelativeProbabilitySingle(gCounter, charCounter);
      cProbability = dna->getRelativeProbabilitySingle(cCounter, charCounter);

      // These next lines are the probability for each nucleotide pair. Calling onto the
      // function that does the pair probability
      aaProbability = dna->getRelativeProbabilityPair(aaCounter, charCounter);
      atProbability = dna->getRelativeProbabilityPair(atCounter, charCounter);
      agProbability = dna->getRelativeProbabilityPair(agCounter, charCounter);
      acProbability = dna->getRelativeProbabilityPair(acCounter, charCounter);
      ttProbability = dna->getRelativeProbabilityPair(ttCounter, charCounter);
      taProbability = dna->getRelativeProbabilityPair(taCounter, charCounter);
      tgProbability = dna->getRelativeProbabilityPair(tgCounter, charCounter);
      tcProbability = dna->getRelativeProbabilityPair(tcCounter, charCounter);
      gaProbability = dna->getRelativeProbabilityPair(gaCounter, charCounter);
      gtProbability = dna->getRelativeProbabilityPair(gtCounter, charCounter);
      ggProbability = dna->getRelativeProbabilityPair(ggCounter, charCounter);
      gcProbability = dna->getRelativeProbabilityPair(gcCounter, charCounter);
      caProbability = dna->getRelativeProbabilityPair(caCounter, charCounter);
      ctProbability = dna->getRelativeProbabilityPair(ctCounter, charCounter);
      cgProbability = dna->getRelativeProbabilityPair(cgCounter, charCounter);
      ccProbability = dna->getRelativeProbabilityPair(ccCounter, charCounter);

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
      outFS << "Assignment 1" << endl;
      outFS << endl;


      // The rest of the statistics will go here
      outFS << "Sum: " << totalSum << endl;
      outFS << "Mean: " << mean << endl;
      outFS << "Variance: " << variance << endl;
      outFS << "Standard Deviation: " << standardDeviation << endl;
      outFS << endl;

      // The relative probability of each nucleotide
      outFS << "The relative probability of each nucleotide:" << endl;
      outFS << "A: " << aProbability << endl;
      outFS << "T: " << tProbability << endl;
      outFS << "G: " << gProbability << endl;
      outFS << "C: " << cProbability << endl;
      outFS << endl;

      // The relative probability of each nucleotide bigram
      outFS << "The relative probability of each nucleotide bigram:" << endl;
      outFS << "AA: " << aaProbability << endl;
      outFS << "AT: " << atProbability << endl;
      outFS << "AG: " << agProbability << endl;
      outFS << "AC: " << acProbability << endl;
      outFS << "TA: " << taProbability << endl;
      outFS << "TT: " << ttProbability << endl;
      outFS << "TG: " << tgProbability << endl;
      outFS << "TC: " << tcProbability << endl;
      outFS << "GA: " << gaProbability << endl;
      outFS << "GT: " << gtProbability << endl;
      outFS << "GG: " << ggProbability << endl;
      outFS << "GC: " << gcProbability << endl;
      outFS << "CA: " << caProbability << endl;
      outFS << "CT: " << ctProbability << endl;
      outFS << "CG: " << cgProbability << endl;
      outFS << "CC: " << ccProbability << endl;
      outFS << endl;

      // This is for the 1000 strings using gaussians distribution
      outFS << "The 1000 strings using Gaussians Distribution:" << endl;

      srand(time(NULL)); // To get less of a bias when seeding numbers I used this link:
                          // https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run

      for (int i = 0; i < 1000; ++i)
      {
        // Used this link to get the random integer from 0 to 1
        // https://stackoverflow.com/questions/48716109/generating-a-random-number-between-0-1-c/48716227
        double rand1 = (double)rand() / ((double)RAND_MAX + 1); // Generates a random number from [0,1)
        double rand2 = (double)rand() / ((double)RAND_MAX + 1); // Generates a random number from [0,1)

        double c = dna->getBoxMuller(rand1, rand2); // Calls onto the function that takes two random number as input
                                                    // gets the box muller equation and output. rand1 and rand2 update each
                                                    // time it is called onto the method
        double d = dna->getGaussian(c, mean, standardDeviation); // Calls onto the gaussian function to get the length of strings

        // Using the gaussian distribution to see how many characters should be on the line
        // The d variable rounds down from the double to an integer and uses it as the length of the string on the line
        for (int j = 0; j < d; ++j)
        {
          double randomNumber = rand() % 100; // Gets a random number from 1-100 and will be used for picking a nucleotide

          // Turn the 'A' probability to a percentage and checks to see if it is higher than the random number generated above
          if ((aProbability * 100) >= randomNumber)
          {
            outFS << "A";
          }
          // Turn the 'A' and 'T' probability to a percentage and checks to see if it is higher than the random number generated above
          else if (((aProbability * 100) + (tProbability * 100)) >= randomNumber)
          {
            outFS << "T";
          }
          // Turn the 'A', 'T' and 'G' probability to a percentage and checks to see if it is higher than the random number generated above
          else if (((aProbability * 100) + (tProbability * 100) + (gProbability * 100)) >= randomNumber)
          {
            outFS << "G";
          }
          // If the number generated above is higher than all of the nucleotide percentages, it prints a 'C'
          else
          {
            outFS << "C";
          }

        }
        outFS << endl; // End of the line
      }


      outFS.close(); // End of function for output file, must close
    }

    // These next lines will allow the user to input another file if desired
    cout << "Would you like to process another list (y/n): ";
    cin >> userInput;

    // Makes the user input to all lower case for accurate input
    for (int i = 0; i < userInput.size(); ++i)
    {
      userInput[i] = tolower(userInput[i]);
    }

    if (userInput[0] == 'y')
    {
      cout << "File name: ";
      cin >> fName;

      // Sets all the variables created to 0, to allow another file to be read
      totalSum = 0;
      mean = 0;
      variance = 0;
      standardDeviation = 0;

      aProbability = 0;
      tProbability = 0;
      gProbability = 0;
      cProbability = 0;

      aaProbability = 0;
      ttProbability = 0;
      ggProbability = 0;
      ccProbability = 0;
      atProbability = 0;
      agProbability = 0;
      acProbability = 0;
      taProbability = 0;
      tgProbability = 0;
      tcProbability = 0;
      gaProbability = 0;
      gtProbability = 0;
      gcProbability = 0;
      caProbability = 0;
      ctProbability = 0;
      cgProbability = 0;
    }
    else
    {
      break; // Exits the program if user enters anything but 'y'
    }
  }

  delete dna; // Deletes the object in heap memory to not have memory leak

  return 0;
}
