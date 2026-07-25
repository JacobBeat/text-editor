#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class TextFile {
private:
  vector<string> data; // each element of data should be a line in the file
public:
  void read(ifstream &fin) { // Loads each line of fin into data
    for (string s; fin >> s;) {
      data.push_back(s);
    }
  }
  void write(ofstream &fout) { // Writes out data to fout
    for (string s : data) {
      fout << s << "\n";
    }
  }
  void replace(const string &output,
               int number) { // replaces line # number with string output
    if (number >= size(data)) {
      throw invalid_argument("Attempted to access outside of file");
    }
    data[number] = output;
  }
  void append(const string &output,
              int number) { // adds string output to end of line # number
    if (number >= size(data)) {
      throw invalid_argument("Attempted to access outside of file");
    }
    data[number] += (" " + output);
  }
  void printline() {
    for (int line = 0; line < size(data); line++) {
      cout << "Line: " << line << data[line] << "\n";
    }
  }
  void printline(int line) {
    if (line >= size(data)) {
      throw invalid_argument("Attempted to access outside of file");
    }
    cout << "Line: " << line << "\n" << data[line] << "\n";
  }
  TextFile() : data() {};
};

int main(int argc, char *argv[]) {
  if (argc == 1) {
    cout << "edit usage: \n";
    cout << "-a {line number} {input file} (optional){output file} \"string\"\n"
         << "appends string to end of line # line number, leaves input "
            "unchanged if output provided otherwise edits input\n";
    cout << "-r {line number} {input file} (optional){output file} \"string\"\n"
         << "replaces line # line number with string, leaves input unchanged "
            "if output provied otherwise edits input\n";
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
