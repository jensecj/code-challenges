/*
  tags: search, xor, bit manipulation
  task: find the only integer in a sequence that does not have a twin
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // numbers in array
  cin >> n;

  int loner = 0;

  // the trick here is that when we xor a number with it self, it
  // becomes zero, and the order does not matter, as the bits simply
  // flip later on in the sequence, so we end up with the lonely
  // integer
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;

    loner ^= a;
  }

  cout << loner << endl;
}
