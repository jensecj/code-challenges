/*
  tags: simple math, integer overflow
  task: given an array of big integers, print its sum
*/
#include <iostream>

using namespace std;

int main() {
  int N; // the size of the array of ints
  cin >> N;

  long long sum = 0;
  while(N--) {
    int n;
    cin >> n;
    sum += n;
  }

  cout << sum << endl;
}
