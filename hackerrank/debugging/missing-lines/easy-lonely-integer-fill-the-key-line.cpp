/*
  tags: bit manipulation
  task: find the lonely integer using onlu a single line for the key
  calculation (using bit operations)
*/

#include <iostream>
#include <vector>

using namespace std;

int lonely_integer(vector<int> a) {
  int answer = 0;
  for(int i = 0; i < a.size(); i++) {
    // this was the line to be filled, the trick is that if you xor a
    // number with itself you get zero, and since you can chain the
    // operations, we can just call it like this and all the
    // duplicated will filter themselves out.
    answer ^= a[i];
  }
  return answer;
}

int main() {
  int res;
  int _a_size;
  cin >> _a_size;
  vector <int> _a(_a_size);
  for(int _a_i = 0; _a_i < _a_size; _a_i++) {
    cin >> _a[_a_i];
  }
  res = lonely_integer(_a);
  cout << res;
  return 0;
}
