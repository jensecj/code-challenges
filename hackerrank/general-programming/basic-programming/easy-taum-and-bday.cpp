/*
  tags: closed form, min
  task: you have to buy B black presents, and W white presents, each
  has a price (X for black presents, Y for white), or you can swap a
  black present for a white one for price Z (or vice versa), what is
  the cheapest price you can get all the presents for?
*/
#include <iostream>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    long B, W; // number of black and white gifts to buy
    cin >> B >> W;

    // cost of a black gift, cost of a white gift, and cost of
    // switching a gift black<->white
    long X, Y, Z;
    cin >> X >> Y >> Z;

    // is it cheaper to buy a black present, or buy a white one and
    // swap it?
    long b_price = min(X, Y + Z);
    // same thing
    long w_price = min(Y, X + Z);

    cout << B*b_price + W*w_price << endl;
  }
}
