#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TextFile {
private:
  vector<string> data; // each element of data should be a line in the file
public:
  void read(ifstream &fin) {
    for (string s; fin >> s;) {
      data.push_back(s);
    }
  }
  void write(ofstream &fout) {
    for (string s : data) {
      fout << s;
    }
  }
  TextFile() : data() {};
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Use one argument.\n";
    return 1;
  }
  vector<string> infile;
  ifstream ist{argv[1]};
  for (string s; ist >> s;) {
    infile.push_back(s);
  }
  ofstream ost{argv[1]};
  char c;
  while (cin.get(c)) {
    ost << c;
  }
}
