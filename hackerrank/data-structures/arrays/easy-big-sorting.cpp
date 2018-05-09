/*
  tags: big int, sorting, c++
  task: given n numeric strings (some really big), sort them and print
  in ascending order
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool big_int_compare(const string& a, const string& b) {
  if(a.size() > b.size()) return false;
  if(a.size() < b.size()) return true;

  return a < b;
}

int main() {
  int n; // number of strings in input
  cin >> n;

  vector<string> unsorted(n);

  for(int i = 0; i < n; i++) {
    cin >> unsorted[i];
  }

  sort(unsorted.begin(), unsorted.end(), big_int_compare);

  for(int i = 0; i < n; i++) {
    cout << unsorted[i] << endl;
  }
}
