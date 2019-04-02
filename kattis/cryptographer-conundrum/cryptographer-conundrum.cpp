/*
  tags: string
  task: given a string of a size which is a multiple of 3, in all
  upper case letters, how many characters do you have to change to
  make it a string that only repeats the word "PER".
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
  string text;
  cin >> text;

  int changes = 0;

  string per = "PER";

  int i = 0;
  for(auto& c : text) {
    if(c != per[i++%3]) {
      changes++;
      cerr << c << " != " << per[(i-1)%3] << endl;
    }
  }

  cout << changes << endl;
}
