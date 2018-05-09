/*
  tags: modulo
  task: you get a number, print Alice if it is odd, otherwise print
  Bob
*/
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  if(N % 2)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
}
