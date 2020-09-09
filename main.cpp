// Created by Robert Boutillier and Marcus Novoa
// Date Created: 9/9/2020

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

  remove(file_name);
  ofstream OutFile(file_name, ios::out | ios::app);

  OutFile << "--------------------------------------" << endl;
  OutFile << "command  ";

  if (arguments[0][0] == '.' && arguments[0][1] == '/') {
    for (j = 2; j < arguments[0].size(); ++j) {
      OutFile << arguments[0][j];
    }
  } else
    OutFile << arguments[0];
  OutFile << endl;

  for (j = 1; j < arguments.size(); ++j) {
    if (arguments[j][0] == '-') {
      OutFile << "switch   ";
      for (k = 1; k < arguments[j].size(); ++k) {
          OutFile << arguments[j][k];
      }
    } else {
      OutFile << "argument ";
      OutFile << arguments[j];  
    }
    OutFile << endl;
  }

  OutFile.close();
  return 0;
}
