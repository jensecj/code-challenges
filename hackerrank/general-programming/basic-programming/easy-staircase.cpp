/*
  tags: loops
  task: given a number n, print a staircase iof n stairs in ascii-art
*/
#include <iostream>

using namespace std;

int main() {
  int n; // the number of stairs
  cin >> n;

  for(int i = 1; i <= n; i++) {
    // print the spaces
    for (int j = 0; j < n-i; j++)
      cout << " ";

    for(int j = 0; j < i; j++)
      cout << "#";

    cout << endl;
  }
}
