#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// utils for string cutting
string without_first(string s) { return s.substr(1); }
string without_last(string s) { return s.substr(0, s.length() - 1); }
string cut_front(string s, int cut) { return s.substr(0, cut); }
string cut_rear(string s, int cut) {
  if (cut > s.length()) {
    return "";
  }
  return s.substr(cut);
}

bool is_polymer_pair(char a, char b) {
  return (a != b) && (toupper(a) == toupper(b));
}

// combine two strings, if the pair where the two strings connect is a polymer
// pair, destroy it and combine the rest of the strings recursively.
string combine(const string &a, const string &b) {
  if (a.empty() || b.empty()) {
    return a + b;
  }

  if (is_polymer_pair(a.back(), b.front())) {
    string a_without_last = without_last(a);
    string b_without_first = without_first(b);
    return combine(a_without_last, b_without_first);
  }

  return a + b;
}

// react a string by cutting it in the middle and working on each side, until we
// reach out base-cases. `combine`is a constant cost op, and we split the string
// in half until we reach strings of length 1 or 2, and then we combine all our
// leaf together to reach the final result, making the complexity of O(n log n).
string react(const string &s) {
  int length = s.length();

  if (length == 0 || length == 1) {
    return s;
  }

  if (length == 2) {
    if (is_polymer_pair(s[0], s[1])) {
      return "";
    } else {
      return s;
    }
  }

  int cut = floor(length / 2);

  if (is_polymer_pair(s[cut - 1], s[cut])) {
    string front_without_last = without_last(cut_front(s, cut));
    string rear_without_first = without_first(cut_rear(s, cut));
    return combine(react(front_without_last), react(rear_without_first));
  } else {
    string front = cut_front(s, cut);
    string rear = cut_rear(s, cut);
    return combine(react(front), react(rear));
  }
}

// since reacting strings is now fast, the strings need to be very large before
// parallelizing gives us a performance improvement, the oveahead simply
// outweights the gains.
int part2(string input) {
  int smallest_improved_polymer = numeric_limits<int>::max();

  for (char i = 'a'; i < 'z'; i++) {
    char lower_case = i;
    char upper_case = (char)(i - 32);

    string s{input};
    s.erase(std::remove(s.begin(), s.end(), lower_case), s.end());
    s.erase(std::remove(s.begin(), s.end(), upper_case), s.end());

    int polymer_length = react(s).length();
    if (polymer_length < smallest_improved_polymer) {
      smallest_improved_polymer = polymer_length;
    }
  }

  return smallest_improved_polymer;
}

int main() {
  string s;
  cin >> s;

  cout << "part 1: " << react(s).length() << endl;
  cout << "part 2: " << part2(s) << endl;
}
