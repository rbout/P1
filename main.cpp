/* ===================================================================
 * Authors     : Robert Boutillier and Marcus Novoa
 * Class       : CSCI4547-01 - Systems Programming
 * Date        : September 9, 2020
 * Description : Lab 1 - Print command line arguments.
 * Version     : 1.0.2
 * =================================================================== */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  char const file_name[] = "P1_BoutillierNovoa.txt";
  vector<string> arguments(argv, argv+argc);
  int j, k;

  ofstream OutFile(file_name, ios::out | ios::app);

  OutFile << "--------------------------------------" << endl;
  OutFile << "command  ";
  cout << "--------------------------------------" << endl;
  cout << "command  ";

  if (arguments[0][0] == '.' && arguments[0][1] == '/') {
    for (j = 2; j < arguments[0].size(); ++j) {
      OutFile << arguments[0][j];
      cout << arguments[0][j];
    }
  } else {
    OutFile << arguments[0];
    cout << arguments[0];
  }
  OutFile << endl;
  cout << endl;

  for (j = 1; j < arguments.size(); ++j) {
    if (arguments[j][0] == '-') {
      int dashes = arguments[j][1] == '-' ? 2 : 1;
      OutFile << "switch   ";
      cout << "switch   ";
      for (k = dashes; k < arguments[j].size(); ++k) {
          OutFile << arguments[j][k];
          cout << arguments[j][k];
      }
    } else {
      OutFile << "argument ";
      OutFile << arguments[j];
      cout << "argument ";
      cout << arguments[j];  
    }
    OutFile << endl;
    cout << endl;
  }

  OutFile.close();
  return 0;
}

/* ===================================================================
 * Explanations:
 * Part E
 *    Command: ./P1 -i "CSCI 6657" *.html > mytemp.txt
 * 
 *    The output was returned to the given file name "mytemp.txt".
 *    The greater-than character sends the output to that file
 *    location using the given arguments.
 * 
 *    Command Output:
 *    --------------------------------------
 *    command  P1
 *    switch   i
 *    argument CSCI 6657
 *    argument *.html
 * 
 * Part F
 *    Command: ./P1 *.bak *.log
 * 
 *    The asterisk character (*) seems to use all files that end
 *    with the given extension as command line arguments. For this
 *    example, the output includes both dummy files created for our
 *    testing (one.bak, two.bak).
 * 
 *    Command Output:
 *    --------------------------------------
 *    command  P1
 *    argument one.bak
 *    argument two.bak
 *    argument *.log
 * =================================================================== */
