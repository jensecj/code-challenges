/*
  tags: math

  task: given some pairs of quality-of-life, and the period of that, calculate
  the persons QALY.

  url: https://open.kattis.com/problems/qaly
*/
#include <iostream>
#include <limits>

using namespace std;

int main() {
  int n;
  cin >> n;

  double qaly = 0;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;

    qaly += x * y;
  }

  cout << qaly << endl;
}
