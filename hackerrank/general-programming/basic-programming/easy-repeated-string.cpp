/*
  tags: big numbers, modulo
  task: given a string, that repeats infinitely, and a number n,
  figure out how many of the character 'a' appear up until the n'th
  character.
*/
#include <iostream>

using namespace std;

int main() {
  string s; // the infinitely repeating string
  cin >> s;

  long n; // the number we need to find all a's before
  cin >> n;

  int len = s.length();

  // count the number of a's in the string
  long as = 0;
  for (int i = 0; i < len; i++)
    if(s.at(i) == 'a')
      as++;

  cerr << as << " a's in " << s << endl;

  // figure out how many times we need to repeat this string until we
  // reach n characters
  long repeats = n / len;
  cerr << repeats << " repeats" << endl;

  // we may be missing some characters (e.g. a part of the string), so
  // we need to figure out how many characters we missed, so we can
  // count the number of a's in that part of the string
  long overflow = n % len;
  long as_in_overflow = 0;
  for (int i = 0; i < overflow; i++) {
    if(s.at(i) == 'a')
      as_in_overflow++;
  }

  cout << (repeats * as) + as_in_overflow << endl;
}
