/*
  tags:
  task:
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    long long n; // top limit
    cin >> n;

    long long sum = 0;
    long long a = 1, b = 1;
    while(a <= n) {
      if(a % 2 == 0)
        sum += a;

      long long tmp = b;
      b = a+b;
      a = tmp;
    }

    cout << sum << endl;
  }
}
