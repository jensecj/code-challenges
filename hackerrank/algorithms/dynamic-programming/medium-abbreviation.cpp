/*
  tags: dp, dynamic programming, substrings
  task: given a string of upper and lower case letters, and a string
  of only uppercase letters, can you turn the first string into the
  second one in you are allowed the following operations:
  1) you may turn any lowercase letter into its uppercase
  2) you may delete the remaining lowercase letters in the string
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool can_abbreviate(const string & a, const string & b){
  vector<vector<bool>> can_abbre(a.size()+1, vector<bool>(b.size()+1, false));
  // if we have a string of length zero, and the string we need to
  // turn it into is also of length zero, it is already solved
  can_abbre[0][0] = true;

  // essentially count all the indices of the string (from the
  // beginning) that can be turned into a string of length 0 (i.e. we
  // can remove all the lowercase letters, so if the string is
  // 'abcdEFG', then can_abbre[1..4][0] = true, because we can remove
  // any of the first 1,...,4 characters)
  for (int i = 1; i <= a.size() && islower(a[i-1]); i++)
    can_abbre[i][0] = true;

  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      // if we could abbreviate the string before we looked at this
      // letter, and this letter is lowercase, we can stille
      // abbreviate the string, because we can just remove the letter
      if (islower(a[i-1]) && can_abbre[i-1][j])
        can_abbre[i][j] = true;

      // if we could abbreviate the string up until this point, and
      // the letter we are looking at can be turned into (or is
      // already) the letter of the second string, we can abbreviate
      // the string at this index as well.
      if (can_abbre[i-1][j-1] && (toupper(a[i-1]) == b[j-1]))
        can_abbre[i][j] = true;
    }
  }

  return can_abbre[a.size()][b.size()];
}

int main() {
  int q; // queries
  cin >> q;

  while(q--) {
    string a, b;
    cin >> a >> b;

    cout << (can_abbreviate(a, b) ? "YES" : "NO") << endl;
  }
}
