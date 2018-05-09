/*
  tags: quicksort, partition
  task: implement the partition step of quicksort, given an unsorted
  array of numbers, partition them into three sets, left, equal, and
  right, of numbers less than some pivot, equal to the pivot, and
  higher than the pivot.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n; // size of array
  cin >> n;

  vector<int> ar(n);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }

  // our pivot
  int p = ar[0];

  vector<int> left;
  vector<int> right;
  int equals = 1;
  for(int i = 1; i < n; i++) {
    if(ar[i] < p)
      left.push_back(ar[i]);
    else if (ar[i] > p)
      right.push_back(ar[i]);
    else
      equals++;
  }

  for(auto& i : left) {
    cout << i << " ";
  }

  for(int i = 0; i < equals; i++) {
    cout << p << " ";
  }

  for(auto& i : right) {
    cout << i << " ";
  }

  cout << endl;
}
