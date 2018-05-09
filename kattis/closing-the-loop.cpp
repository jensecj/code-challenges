/*
  tags: programming puzzle
  task: given S segments of rope, each of some length C in cm, of
  colors red or blue, knowing that you can only tie together two
  different colors of rope, and that a knot costs 0.5 cm to tie, what
  is the longest rope you can make?
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N; // testcases
  cin >> N;

  for(int i = 1; i <= N; i++) {
    int S; // number of segments of rope
    cin >> S;

    vector<int> reds;
    vector<int> blues;

    while(S--) {
      int len;
      char color;

      cin >> len >> color;

      if(color == 'R')
        reds.push_back(len);
      else
        blues.push_back(len);
    }

    sort(reds.begin(), reds.end());
    sort(blues.begin(), blues.end());
    reverse(reds.begin(), reds.end());
    reverse(blues.begin(), blues.end());

    int m = min(reds.size(), blues.size());
    int length = 0;

    for(int j = 0; j < m; j++) {
      length += reds[j] + blues[j];
    }

    // subtract the lengths of the knots
    length -= m*2; // each segment from one set, needs two knots

    // cap a 0
    length = max(length, 0);

    cout << "Case #" << i << ": " << length << endl;
  }
}
