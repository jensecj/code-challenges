/*
  tags: simple math
  task: given a range, count the number of square numbers in the range
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    long A, B; // the range, where we have to count squares between
    cin >> A >> B;

    // count the amount of whole numbers that are between the two
    // numbers square roots
    cout << floor(sqrt(B)) - ceil(sqrt(A)) + 1 << endl;
  }
}
