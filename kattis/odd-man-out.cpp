/*
  tags: xor, big numbers
  task: given a sequence of numbers, find the only one that only
  appears once
*/
#include <iostream>

using namespace std;

int main() {
  int N; // testcases
  cin >> N;

  for (int i = 0; i < N; i++) {
    int G; // number of guests
    cin >> G;

    int lonely_guest = 0;

    for (int j = 0; j < G; j++) {
      int nr;
      cin >> nr;

      lonely_guest ^= nr;
    }

    cout << "Case #" << i+1 << ": " << lonely_guest << endl;
  }
}
