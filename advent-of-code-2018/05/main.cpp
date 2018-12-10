#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// remove all pairs of uppercase/lowercase of the same characters, in either
// orientation (Aa or aA). then return the length of the final string.  in this
// case the naiive approach works, the strings are made in a way such that if
// there are multiple reductions, they end up reducing to the same string.
int part1(string input) {
  string s{input};

  for (int i = 0; i < s.length(); i++) {
    // if there are no more characters to check, break out
    if (i >= s.length() - 1) {
      break;
    }

    char c = s[i];
    char n = s[i + 1];

    // in ascii, the difference between two in different cases is 32
    if (abs(c - n) == 32) {
      // cout << "eating " << s.substr(i, 2) << endl;
      s = s.substr(0, i) + s.substr(i + 2);
      i = -1; // reset counter, gets +1 after finishing loop
    }
  }

  return s.length(); // 10384
}

// find the smallest reduction of a polymer-string, after remove all existing
// pairs of a single unit.
// e.g. remove all Aa/aA pairs, or all Bb/bB pairs, and then return the length
// of the smallest reduction. we can just reuse the solution from part 1, and
// the process is easily parallelizable.
int part2(string input) {
  int smallest_improved_polymer = numeric_limits<int>::max();

  for (char i = 'a'; i < 'z'; i++) {
    char lower_case = i;
    char upper_case = (char)(i - 32);

    string s{input};
    s.erase(std::remove(s.begin(), s.end(), lower_case), s.end());
    s.erase(std::remove(s.begin(), s.end(), upper_case), s.end());

    int polymer_length = part1(s);
    if (polymer_length < smallest_improved_polymer) {
      smallest_improved_polymer = polymer_length;
    }
  }

  return smallest_improved_polymer; // 5412
}

int main() {
  cout << part1("AaaA") << endl;                                 // 0
  cout << part1("dabAcCaCBAcCcaDA") << endl;                     // 10
  cout << part1("AAa") << endl;                                  // 1
  cout << part1("ACacACacACacACacACacACacACacACacACac") << endl; // 36

  string s;
  cin >> s;

  cout << "part 1 - length of reduced polymer: " << part1(s) << endl;
  cout << "part 2 - smallest improved polymer length: " << part2(s) << endl;
}
