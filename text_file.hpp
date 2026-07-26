#ifndef TEXT_FILE_H
#define TEXT_FILE_H
#pragma once
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class TextFile {
private:
  vector<string> data;

public:
  void read(ifstream &fin);
  void write(ofstream &fout);
  void append(const string &output, int line);
  void replace(const string &output, int line);
  void printline();
  void printline(int line);
  TextFile();
};

#endif
