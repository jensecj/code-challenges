/*
  tags: string
  task: given a binary string, how many bit flips do you need to make
  to make the string beautiful? a beautiful binary string is one that
  does not contain the substring '010'.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int _; // we don't really need the number of bits
  cin >> _;

  string s;
  cin >> s;
  cerr << s << endl;

  // if, everytime we find the substring '010', we change it to '011',
  // we never introduce new substrings that look like '010', (but we
  // may remove other possible substrings), so just count how many of
  // these replacements we need to do

  int count = 0;
  size_t found = -1;
  found = s.find("010");

  while(found != string::npos) {
    s.replace(found, 3, "011");
    count++;

    found = s.find("010", found+1);
  }

  cout << count << endl;
}
