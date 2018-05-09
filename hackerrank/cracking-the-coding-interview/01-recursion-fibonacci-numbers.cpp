/*
  tags: fibonacci, recursion
  task: given n, calculate fibonacci(n) recursively
*/
#include <iostream>

using namespace std;

int fibonacci(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
  int n;
  cin >> n;
  cout << fibonacci(n);
}
