#include "text_file.hpp"
#include <iostream>

using namespace std;

void TextFile::read(ifstream &fin) { // Loads each line of fin into data
  string s;
  while (getline(fin, s)) {
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
  number -= 1;    // Use 1-based indexing
  if (number < 0) {
    cout << "Line number must be greater than or equal to one\n";
    return;
  }
  if (number >= size(data)) {
    for (int i = size(data); i < number; i++) {
      data.push_back("");
    }
    data.push_back(output);
    return;
  }
  data[number] = output;
}
void TextFile::append(
    const string &output,
    int number) { // adds string output to end of line # number
  number -= 1;
  if (number < 0) {
    cout << "Line number must be greater than or equal to one\n";
    return;
  }
  if (number >= size(data)) {
    for (int i = size(data); i < number; i++) {
      data.push_back("");
    }
    data.push_back(output);
    return;
  }
  data[number] += output;
}
void TextFile::printline() {
  for (int line = 0; line < size(data); line++) {
    cout << "Line " << line + 1 << ": " << data[line] << "\n";
  }
}
void TextFile::printline(int line) {
  if (line < 1) {
    cout << "Line number must be greater than or equal to one\n";
    return;
  }
  if (line > size(data)) {
    cout << "Attempting to print outside of file";
    return;
  }
  cout << "Line: " << line << "\n" << data[line - 1] << "\n";
}
TextFile::TextFile() : data() {};
