/*
  tags: simple math
  task: given a range from s to t. and some numbers, determine if the
  numbers are in the range
*/
#include <iostream>

using namespace std;

int main() {
  int s, t; // the range - sams house
  cin >> s >> t;
  cerr << "sams house: " << s << "," << t << endl;

  int a, b; // the location of the apple tree, and orange tree
  cin >> a >> b;
  cerr << "apple tree: " << a << ", orange tree: " << b << endl;

  int m, n; // the number of apples and oranges that will fall
  cin >> m >> n;
  cerr << "apples: " << m << ", oranges: " << n << endl;

  int apple_hits = 0; // the number of apples that hit sams house
  while(m--) {
    int apple;
    cin >> apple;
    cerr << "apple fell: " << apple << endl;
    apple += a;
    cerr << " = " << apple << endl;
    if(apple >= s && apple <= t) {
      apple_hits++;
      cerr << "apple hit sams house!" << endl;
    }
  }

  int orange_hits = 0;
  while(n--) {
    int orange;
    cin >> orange;
    orange += b;
    if(orange >= s && orange <= t)
      orange_hits++;
  }

  cout << apple_hits << endl;
  cout << orange_hits << endl;
}
