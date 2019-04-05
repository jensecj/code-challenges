/*
  tags:

  task: two people each have a list of CD's, identified by id's. output the
  number of duplicated in the lists.

  url: https://open.kattis.com/problems/cd
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int x, y;

  while (cin >> x >> y && x != 0 && y != 0) {
    unordered_set<int> s;

    int dups = 0;

    for (int i = 0; i < x + y; i++) {
      int in;
      cin >> in;

      if (s.find(in) != s.end()) {
        dups++;
      } else {
        s.insert(in);
      }
    }

    cout << dups << endl;
  }
}
