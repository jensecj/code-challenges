/*
  tags: sets

  task: given a string of words, find duplicate words

  url: https://open.kattis.com/problems/nodup
*/
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  set<string> s;

  bool dups = false;

  string in;
  while (cin >> in) {
    if (s.find(in) != s.end()) {
      dups = true;
      break;
    }

    s.insert(in);
  }

  if (dups) {
    cout << "no" << endl;
  } else {
    cout << "yes" << endl;
  }
}
