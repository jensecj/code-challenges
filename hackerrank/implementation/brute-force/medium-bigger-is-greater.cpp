/*
  tags: strings, permutations
  task: given a string, print a permutation of that string that is
  lexicographically greater, if none exists, print 'no answer'
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    string s;
    cin >> s;

    if(next_permutation(s.begin(), s.end()))
      cout << s << endl;
    else
      cout << "no answer" << endl;
  }
}
