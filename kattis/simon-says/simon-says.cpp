/*
  tags: simple programmming puzzle
  task: given a sequence of lines, do what simon says.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int N; // number of strings
  cin >> N;
  cin.ignore(); // read the newline

  while(N--) {
    string s;
    getline(cin, s);

    // cerr << s << endl;

    if(s.substr(0, 10) == "Simon says")
      cout << s.substr(11, s.length()-1) << endl;
  }
}
