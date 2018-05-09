/*
  tags: simple programmming puzzle
  task: given a text of n strings, calculate the penalty score for the
  text. the penalty score is calculated using the longest line in the
  text, and every other, shorter, line gets a penalty of
  (|longest line| - |shorter line|)^2, the total penalty score of the
  text is the sum of the penalty scores of all lines, except the last one.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  string line;

  vector<string> lines;

  int max = 0;

  while(getline(cin, line)) {
    lines.push_back(line);

    if(line.length() > max)
      max = line.length();
  }

  int penalty = 0;
  for(int i = 0; i < lines.size()-1; i++) {
    penalty += pow(max - lines[i].length(), 2);
  }

  cout << penalty << endl;
}
