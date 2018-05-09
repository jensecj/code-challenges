/*
  tags: string
  task: given a sequence of strings, figure out the minimum cost of
  copying that string into a new string if you are allowed to copy 1
  character to the new string for a cost of 1, or you can copy any
  substring in the new string, and insert it for a cost of 1.
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  int n; // number of strings to test
  cin >> n;

  // the trick to note here is that a substring in the new string can
  // be of size 1. if when ever we have inserted a unique character
  // into the new string, we can copy it at will for a cost of 0, so
  // the total becomes the number of unique characters that we are
  // forced to copy from the old string.
  while(n--) {
    string s;
    cin >> s;

    unordered_set<char> chars;
    for(int i = 0; i < s.length(); i++) {
      chars.insert(s[i]);
    }

    cout << chars.size() << endl;
  }
}
