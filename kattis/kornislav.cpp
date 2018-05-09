/*
  tags: math
  task: you walk a steps forward, then turn right 90 degrees, then
  walk b steps forward, etc. you repeat this until you have turned
  three times and walked four segments. given the number of steps
  (which are in 1 unit increments), what is the biggest rectangle you
  have enclosed?
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];

  sort(begin(a), end(a));
  cout << a[0] * a[2] << endl;
}
