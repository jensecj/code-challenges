/*
  tags: math
  task: given a string which is a single 'A', at every turn, an 'A'
  gets turned into a 'B', and a 'B' gets turned into 'BA' after K
  turns, how many A's and B's are there?
*/
#include <iostream>
#include <cmath>

using namespace std;

int fib(int n) {
  if(n == 0) return 0;
  if(n == 1 || n == 2) return 1;

  int previous = 1;
  int current = 1;
  int next = 1;
  for (int i = 3; i <= n; ++i) {
    next = current + previous;
    previous = current;
    current = next;
  }
  return next;
}

int main() {
  int K; // k presses of the button
  cin >> K;

  // write down the sequence for the first 6 or so turns, notice that
  // theres fib(k-1) A's, and fib(k) B's, after K turns.
  cout << fib(K-1) << " " << fib(K) << endl;
}
