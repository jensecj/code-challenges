/*
  tags: math
  task: given three kangaroos standing on a number line, at every
  move, one of them can jump into an empty number between the others,
  how long can they play for?
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int pos[3]; // starting position of the three kangaroos
  cin >> pos[0] >> pos[1] >> pos[2];

  sort(begin(pos), end(pos));

  cout << max(abs(pos[1] - pos[0])-1, abs(pos[2] - pos[1])-1) << endl;
}
