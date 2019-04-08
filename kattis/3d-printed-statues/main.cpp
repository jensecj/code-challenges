/*
  tags:

  task: you need to 3d-print n statues, your printer can either print a statue,
  or another 3d-printer, printing takes a day. what is the minimum number of
  days you need to print all n statues?

  url: https://open.kattis.com/problems/3dprinter
*/
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  // the idea is that we create printers until we reach half of the needed
  // statues, and then build all the statues on the last day, so we just count
  // the number of times we need to double the number of printers.

  int target = n;

  int doubles = 0;
  for (int i = 0; i <= n; i++) {
    if (pow(2, i) >= target) {
      doubles = i;
      break;
    }
  }

  // unless we don't need to create any statues, it takes a day to build the
  // first statue or printer
  if (n != 0) {
    doubles++;
  }

  cout << doubles << endl;
}
