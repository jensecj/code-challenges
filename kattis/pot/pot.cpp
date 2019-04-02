/*
  tags: math
  task: given a sequence of numbers, we know that the last digit of
  each number is supposed to be the power it is raised to, but
  something went wrong, reconstruct the numbers to their proper form,
  and print the sum of all the numbers
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n; // the amount of numbers
  cin >> n;

  long sum = 0;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    int last_digit = in % 10;
    cerr << last_digit << endl;
    sum += pow(in/10, last_digit);
  }

  cout << sum << endl;
}
