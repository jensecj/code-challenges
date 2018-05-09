/*
  tags: modulo, string to int
  task: given a number, find how many of its digits divide the number evenly
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;
  cerr << T << " testcases" << endl;

  while(T--) {
    long number;
    cin >> number;
    cerr << "number: " << number << endl;

    int even_divisors = 0;
    string n = to_string(number);

    for (int i = 0; i < n.length(); i++) {
      int c = n.at(i) - '0';
      if(c != 0 && number % c == 0)
        even_divisors++;
    }

    cout << even_divisors << endl;
  }
}
