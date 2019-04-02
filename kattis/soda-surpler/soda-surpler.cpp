/*
  tags: simple programming puzzle
  task: tim has a empty soda bottles, and finds b empty bottles during
  the day. he can exchange c empty bottles for a new full bottle of
  soda. given a,b, and c, how many bottles of soda can tim get to drink?
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int a,b,c; // number of bottles tim has, number he drinks, and
             // number of empty bottles required to turn in for a new soda
  cin >> a >> b >> c;

  int empty = a  + b;
  int drank = 0;
  while(empty >= c) {
    drank++;
    empty -= c;
    empty++;
  }

  cout << drank << endl;
}
