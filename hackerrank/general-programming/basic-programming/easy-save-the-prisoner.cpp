/*
  tags: modulo
  task: given some n prisoners with ids, situated in a ring, and some
  number of candies. starting at prisoner i, and going around the
  circle until we have distributed all the candies, who ends up
  getting the last, poisoned, candy?
*/

#include <iostream>

using namespace std;

int main() {
  int T; // the number of test cases
  cin >> T;

  while(T--) {
    long N, M, S; // the number of prisoners, the number of sweets, and
    // the id of the first prisoner
    cin >> N >> M >> S;

    // we take the starting id S, add the number of candies M (-1
    // because the first prisoner with id S also gets a candy), and
    // modulo with the number of prisoners N, to get the index of the
    // prisoner ending up with the poisoned candy, note that if the
    // number is divisible (e.g. mod = 0), then we need to print the
    // N'th prisoner, and not the 0th.
    if((S+M-1) % N == 0) cout << N << endl;
    else cout << (S+M-1) % N << endl;
  }
}
