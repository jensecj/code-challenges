/*
  tags:
  task:
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int moves(const vector<vector<int>>& graph, int x, int y) {
  if(((x > 0 && x < 3) && (y > 0 && y < 3)))
    return 0;

  int n = graph.size();
  int m = graph[0].size();

  if(x < 0 || x > n || y < 0 || y > m) {
    cout << "ERROR:" << x << "," << y << " [" << n << "," << m << "]" << endl;
    throw new runtime_error("error: index for node was outside bounds");
  }

  int moves = 0;

  if(x-1 >= 0 && y-1 >= 0)
    moves++;
  if(x-1 >= 0)
    moves++;
  if(x-1 >= 0 && y+1 < m)
    moves++;

  if(y-1 >= 0)
    moves++;
  if(y+1 < m)
    moves++;

  if(x+1 < n && y-1 >= 0)
    moves++;
  if(x+1 < n)
    moves++;
  if(x+1 < n && y+1 < m)
    moves++;

  return moves;
}


int main() {
  vector<char> alphabet {
    '_', '.', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
      'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
      'Y', 'Z'};

  int forwards_rotations;

  while(cin >> forwards_rotations && forwards_rotations != 0) {
    string s; // string to reverse, then rotate
    cin >> s;

    // cerr << "string: " << s << endl;
    // cerr << "rotations: " << forwards_rotations << endl;

    reverse(s.begin(), s.end());

    for(int i = 0; i < s.length(); i++) {
      int idx = s[i]-63; // 'A' is 65 in ascii, but we added 2 new
                         // letters at the beginning of our alphabet
      if(s[i] == '_') idx = 0;
      if(s[i] == '.') idx = 1;
      // cerr << s[i] << " = " << idx << " = " << alphabet[(idx+forwards_rotations) % alphabet.size()] << endl;
      s[i] = alphabet[(idx + forwards_rotations) % alphabet.size()];
    }

    cout << s << endl;
  }
}
