/*
  tags: sorting

  task: gives n trees, each of which takes some time to grow, and takes 1 day to
  plant, when is the earliest day when you can have grown all trees?

  url: https://open.kattis.com/problems/plantingtrees
*/
#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  // sort inputs from low to high
  multiset<int, less<int>> s;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }

  int high = 0;
  for (auto &x : s) {
    // we need at least as long as it takes to grow this tree, plus the number
    // of remaining trees
    int party_day = x + n;

    if (high < party_day) {
      high = party_day;
    }

    // we planted a tree, now we need to plant one fewer
    n--;
  }

  // we start on day 1
  high += 1;

  cout << high << endl;
}
