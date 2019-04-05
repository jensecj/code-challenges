/*
  tags:

  task: given two non-negative integers, calculate the difference.

  url: https://open.kattis.com/problems/different
*/
#include <iostream>

using namespace std;

int main() {
  long long x, y = 0;
  while (cin >> x && cin >> y) {
    cout << abs(x - y) << endl;
  }
}
