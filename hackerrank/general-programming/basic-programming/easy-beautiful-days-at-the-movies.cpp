/*
  tags: number puzzle
  task: given a range [i,j], and a number k, find the numbers x in the
  range, such that the absolute difference between x, and reverse(x),
  is evenly divisible by k. (the reverse of a number is like reversing
  a string, digit by digit, e.g. 321 -> 123)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int reverse_w_string(int i) {
  string num = to_string(i);
  reverse(num.begin(), num.end());
  return stoi(num);
}

int reverse(int i){
  int reverse = 0;
  while(i != 0){
    reverse = 10 * reverse + i % 10;
    i = i / 10;
  }
  reverse += i;
  return reverse;
}

int main() {
  int i, j, k; // the range [i,j], and the number k, which beautiful
               // days must be evenly divisible by
  cin >> i >> j >> k;

  int days = 0;
  for (int x = i; x < j; x++) {
    // cerr << x << " -> " << reverse(x) << endl;
    if(abs(x - reverse(x)) % k == 0)
      days++;
  }

  cout << days << endl;
}
