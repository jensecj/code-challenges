/*
  tags: bit manipulation, bitwise and
  task: given numbers N and K. find the numbers a,b \in [0,..,N),
  where a&b < K, and a&b is as big as possible
*/
#include <iostream>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int N, K; // toplimit of integers to test, and constant we have to
              // stay below
    cin >> N >> K;

    int A, B;
    int max = 0;
    for(int a = 0; a <= N; a++) {
      for(int b = a+1; b <= N; b++) {
        if((a&b) < K && (a&b) > max) {
          max = (a&b);
          A = a;
          B = b;
        }
        // cout << a << ", " << b << " = " << (a&b) << endl;
      }
    }

    cout << max << endl;
  }
}
