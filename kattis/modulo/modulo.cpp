/*
  tags: modulo
  task: given a sequence of numbers, count the number of distinct
  numbers if we take % 42 of all numbers
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int distinct = 0;

  unordered_map<int, bool> seen;

  for (int i = 0; i < 10; i++) {
    int in;
    cin >> in;
    in = in % 42;

    if (!seen[in]) {
      seen[in] = true;
      distinct++;
    }
  }

  cout << distinct << endl;
}
