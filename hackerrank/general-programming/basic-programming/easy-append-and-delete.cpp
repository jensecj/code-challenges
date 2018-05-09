/*
  tags: strings, puzzle
  task: given two strings, and a number k, is it possible to turn the
  first string into the second one in exactly k steps, if we can only
  remove the last letter from the string, or add another letter at the
  end of the string?
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int count_matches(string s1, string s2) {
  string a,b;

  if(s1.size() > s2.size()) {
    a = s2;
    b = s1;
  } else {
    a = s1;
    b = s2;
  }

  int matches = 0;
  for (int i = 0; i < a.size(); i++) {
    if(a.at(i) == b.at(i))
      matches++;
    else
      break;
  }

  return matches;;
}

int main() {
  string s, t; // the two strings, where we want to turn s into t
  cin >> s >> t;
  cerr << "s: " << s << endl;
  cerr << "t: " << t << endl;

  int k; // we want to turn s into t in k or fewer steps
  cin >> k;
  cerr << "k: " << k << endl;

  int matches = count_matches(s, t);
  cerr << "matches: " << matches << endl;

  int deletions = s.size() - matches;
  cerr << "deletions: " << deletions << endl;
  int additions = t.size() - matches;
  cerr << "additions: " << additions << endl;

  int sizes = s.size() + t.size();

  int moves = deletions + additions;

  // the difference in the two strings is too big to fix
  if(moves > k)
    cout << "No" << endl;
  // if the strings are equal we can
  // add->remove or remove->add to bring the moves up to k, without
  // changing the strings, so if we have an odd number of moves left, we
  // can still make it. if the strings are 1-off, we can add/remove or
  // add->remove->add or remove->add->remove, and close the distance, so
  // if we have an odd number of moves left, we can also make it
  else if(moves % 2 == k % 2)
    cout << "Yes" << endl;
  // if the combined sizes of the strings is less than our available
  // moves, we can completely remove one string, and rebuild it as the
  // other
  else if(sizes - k < 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
