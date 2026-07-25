#include "text_file.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

void TextFile::read(ifstream &fin) { // Loads each line of fin into data
  for (string s; fin >> s;) {
    data.push_back(s);
  }
}
void TextFile::write(ofstream &fout) { // Writes out data to fout
  for (string s : data) {
    fout << s << "\n";
  }
}
void TextFile::replace(
    const string &output,
    int number) { // replaces line # number with string output
  if (number >= size(data)) {
    throw invalid_argument("Attempted to access outside of file");
  }
  data[number] = output;
}
void TextFile::append(
    const string &output,
    int number) { // adds string output to end of line # number
  if (number >= size(data)) {
    throw invalid_argument("Attempted to access outside of file");
  }
  data[number] += (" " + output);
}
void TextFile::printline() {
  for (int line = 0; line < size(data); line++) {
    cout << "Line " << line << ": " << data[line] << "\n";
  }
}
void TextFile::printline(int line) {
  if (line >= size(data)) {
    throw invalid_argument("Attempted to access outside of file");
  }
  cout << "Line: " << line << "\n" << data[line] << "\n";
}
TextFile::TextFile() : data() {};
