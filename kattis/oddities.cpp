/*
  tags: modulo
  task: given a number, check if it is even or odd
*/
#include <iostream>

using namespace std;

int main() {
  int t; // testcases
  cin >> t;

  while(t--) {
    int n; // number to test
    cin >> n;

    cout << n << " is " << (n%2==0 ? "even" : "odd") << endl;
  }
}
