/*
  tags: string
  task: given a circle of stones in the form of a string of B's and
  W's (black and white stones, imagine that the last character touches
  the first one). can we balance this circle of stones? balancing
  means removing stones until there is only a single white and a
  single black stone left. and we are allowed to remove stones with
  the following rules:
  in a contigous sequence of stones, if there is one more black stone
  than white stone, we can replace that sequence with a single black
  stone, if there is one more white stone than black stones, we can
  replace the sequence with a single white stone.
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
  string s; // string of stones
  cin >> s;

  int bs = 0;
  int ws = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == 'B') bs++;
    else ws++;
  }

  // notice that is we look at the sequence WWWBB, and we replace the
  // entire sequence with a single white stone, it is the same as if
  // we replaced the sequence in steps W(WWB)B -> WWB -> W, so we only
  // need to look at smaller sequences.
  // if we keep removing WB/BW, do we end up with an empty string? if
  // yes, then we can balance the stones, otherwise there are left
  // over stones, so we cannot balance them
  cout << !(abs(bs-ws) > 0) << endl;
}
