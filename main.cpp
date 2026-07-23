#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void write_into_file(ofstream &out, string &data) { out << data; }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Use one argument.\n";
    return 1;
  }
  ofstream ost{argv[1]};
  string buffer;
  while (cin >> buffer) {
    write_into_file(ost, buffer);
  }
}
