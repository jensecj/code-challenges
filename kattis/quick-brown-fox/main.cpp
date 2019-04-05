/*
  tags: hashmap

  task: report which characters are missing from a string to make it a pangram
  (a string which contains all letters in the alphabet.)

  url: https://open.kattis.com/problems/quickbrownfox
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore(1, '\n');

  for (int i = 0; i < n; i++) {
    string input;
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    map<char, bool> m;

    for (auto &c : input) {
      m[c] = true;
    }

    ostringstream output;
    for (char i = 'a'; i <= 'z'; i++) {
      if (!m[i]) {
        output << i;
      }
    }

    if (output.str() == "") {
      cout << "pangram" << endl;
    } else {
      cout << "missing " << output.str() << endl;
    }
  }
}
