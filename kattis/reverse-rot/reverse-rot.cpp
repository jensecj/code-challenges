/*
  tags: strings
  task: given a string of capital letters A-Z, . (periods), and _
  (underscores). first reverse the string, then perform some number of
  rotations on it (for 1 rotation: _ -> ., . -> A, A - B, ..., Z - _, etc).
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

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
