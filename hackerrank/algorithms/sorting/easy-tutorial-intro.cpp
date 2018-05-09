/*
  tags: sorting
  task: given a sorted array of numbers, and a new number n, find the
  index where n should be inserted into the array.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int V; // value to find index for
  int n; // size of array
  cin >> V >> n;

  vector<int> ar(n);
  for(int i = 0; i < n; i++)
    cin >> ar[i];

  int idx = lower_bound(ar.begin(), ar.end(), V) - ar.begin();

  cout << idx << endl;
}
