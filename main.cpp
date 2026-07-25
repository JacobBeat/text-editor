#include "text_file.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    cout << "edit usage: \n";
    cout << "-a {line number} {input file} (optional){output file} \"string\"\n"
         << "appends string to end of line # line number, leaves input "
            "unchanged if output provided otherwise edits input\n";
    cout << "-r {line number} {input file} (optional){output file} \"string\"\n"
         << "replaces line # line number with string, leaves input unchanged "
            "if output provided otherwise edits input\n";
    cout << "-p (optional){line number} {input file}\n"
         << "prints line # line number of input file, if none provided prints "
            "whole file\n";
    return 1;
  }
  TextFile file;
  if (strcmp(argv[1], "-a") == 0) {

    switch (argc) {
    case 5: {
      ifstream ist{argv[3]};
      file.read(ist);
      ofstream ost{argv[3]};
      file.append(argv[4], stoi(argv[2]));
      file.write(ost);
      return 0;
      break;
    }
    case 6: {
      ifstream ist{argv[3]};
      file.read(ist);
      ofstream ost{argv[4]};
      file.append(argv[5], stoi(argv[2]));
      file.write(ost);
      return 0;
      break;
    }
    default:
      cout << "Improper usage\n";
      return 1;
    }
  }
  if (strcmp(argv[1], "-r") == 0) {

    switch (argc) {
    case 5: {
      ifstream ist{argv[3]};
      file.read(ist);
      ofstream ost{argv[3]};
      file.replace(argv[4], stoi(argv[2]));
      file.write(ost);
      return 0;
      break;
    }
    case 6: {
      ifstream ist{argv[3]};
      file.read(ist);
      ofstream ost{argv[4]};
      file.replace(argv[5], stoi(argv[2]));
      file.write(ost);
      return 0;
      break;
    }
    default:
      cout << "Improper usage\n";
      return 1;
    }
  }
  if (strcmp(argv[1], "-p") == 0) {
    switch (argc) {
    case 3: {
      ifstream ist{argv[2]};
      file.read(ist);
      file.printline();
      return 0;
    }
    case 4: {
      ifstream ist{argv[3]};
      file.read(ist);
      file.printline(stoi(argv[2]));
      return 0;
    }
    default:
      cout << "Improper usage\n";
      return 1;
    }
  }
  cout << "Improper usage\n";
  return 1;
}
