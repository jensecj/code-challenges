/*
  tags: binary
  task: given a number, reverse its binary form, and print the number
  that string represents
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
  long in;
  cin >> in;

  bitset<64> number(in);

  string num = number.to_string();
  num.erase(0, num.find_first_not_of('0'));
  cerr << num << endl;

  reverse(num.begin(), num.end());

  long rev = stoi(num, nullptr, 2);

  cout << rev << endl;
}
