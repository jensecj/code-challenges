/*
  tags: math

  task: calculate a batters slugging percentage

  url: https://open.kattis.com/problems/batterup
*/
#include <iostream>
#include <limits>

using namespace std;

int main() {
  int n = 0;
  cin >> n;

  long double sum = 0.0;
  int hits = 0;
  for (int i = 0; i < n; i++) {
    int b = 0;
    cin >> b;

    if (b < 0) {
      continue;
    }

    sum += b;
    hits++;
  }

  cout.precision(numeric_limits<double>::max_digits10);
  cout << (sum / hits) << endl;
}
