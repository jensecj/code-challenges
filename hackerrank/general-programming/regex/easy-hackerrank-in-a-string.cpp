/*
  tags: regex
  task: figure out if 'hackerrank' is a subsequence in a string
  note: using this approach on big strings will become a problem
  because of backtracking
*/
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
  int n; // the number of usernames to test
  cin >> n;

  regex match(".*h+.*a+.*c+.*k+.*e+.*r+.*r+.*a+.*n+.*k+.*");

  while(n--) {
    string s;
    cin >> s;

    if(regex_match(s, match))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
