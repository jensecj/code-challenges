/*
  tags: string
  task: given a string of words delimited by '-', print the acronym
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  size_t pos = 0;
  while ((pos = s.find("-")) != string::npos) {
    cout << s[0]; // first letter of the word
    s.erase(0, pos + 1); // swallow everything up to and including the delimiter
  } // repeat

  // print the first letter of the last part of the string (no more delimiters)
  cout << s[0] << endl;
}
