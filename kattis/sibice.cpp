/*
  tags: puzzle, math
  task: given a match box with width W and height H, and then given a
  sequence of matches of length l, calculate if the match can fit in
  the matchbox.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int N, W, H; // number of matches, width and height of matchbox
  cin >> N >> W >> H;

  double hyp = sqrt(pow(W, 2) + pow(H, 2));
  cerr << "hyp: " << hyp << endl;

  for(int i = 0; i < N; i++) {
    int length;
    cin >> length;

    length <= hyp ? cout << "DA" << endl : cout << "NE" << endl;
  }
}
