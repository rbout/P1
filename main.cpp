// Created by Robert Boutillier and Marcus Novoa
// Date Created: 9/9/2020

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) {
  remove("P1_BoutillierNovoa.txt");
  ofstream OutFile("P1_BoutillierNovoa.txt", ios::out | ios::app);
  OutFile << "--------------------------------------" << endl;

  OutFile << "command " << argv[0] << endl;

  for (int i = 1; i < argc; ++i) {
  
    // TODO need to format the output better

    if (strncmp(&argv[i][0], "-", 1) == 0)
      OutFile << "switch " << argv[i] << endl;
    else
      OutFile << "argument " << argv[i] << endl;
  }

  OutFile.close();
  return 0;
}