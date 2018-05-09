/*
  tags:
  task:
*/
#include <iostream>

using namespace std;

int main() {
  int T; // number of testcases
  cin >> T;

  while(T--) {
    long n; // number to sum to
    cin >> n;

    long threes = (n-1) / 3;
    long fives = (n-1) / 5;
    long fifteens = (n-1) / 15;

    long mod_threes = 3 * (threes * (threes+1) / 2);
    long mod_fives = 5 * (fives * (fives+1) / 2);
    long mod_fifteens = 15 * (fifteens * (fifteens+1) / 2);

    long sum = mod_threes + mod_fives - mod_fifteens;

    // too slow
    // long sum = 0;
    // for (long i = 1; i < n; i += 2) {
    //   if(i % 3 == 0 || i % 5 == 0) {
    //     sum += i;
    //   }
    // }

    cout << sum << endl;
  }
}
