/*
  tags: bit manipulation
  task: given a number n, how many numbers 0 <= x <= n, are there
  where n+x = n xor x
*/
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main() {
  long n; // number to test
  cin >> n;

  // the trick here is to realize that xor is the same as addition,
  // without the carry. so we need to find all the binary strings
  // where, if we add them, we do not get a carry bit, so for all
  // strings a and b, they cannot have a 1 in the same place, because
  // it would cause the addition to carry, if they have different
  // bits, of both have 0, its fine.

  // we count how many zeroes there are in n, for each zero, we can
  // have either a 1 or a 0 in the binary number we're adding/xoring
  long zeroes = 0;
  while(n) {
    if((n & 1) == 0)
      zeroes++;

    n = n/2;
  }

  // to get all combinations we do 2^zeroes (remember, for each zero,
  // we could either place a 0 or a 1)
  zeroes = pow(2, zeroes);

  cout << zeroes << endl;
}
