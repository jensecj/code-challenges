/*
  tags: arrays, simple math
  task: given an array on ints, find which fractions of the numbers
  are positive, negative, and zero, and print the decimal values of
  each fraction on a new line
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  int n; // the amount of numbers in the array
  cin >> n;

  vector<int> nums(n);

  float neg = 0, pos = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    if(in == 0) zero++;
    if(in < 0) neg++;
    if(in > 0) pos++;
  }

  cout << fixed;
  cout << setprecision(6);
  cout << pos/n << endl;
  cout << neg/n << endl;
  cout << zero/n << endl;
}
