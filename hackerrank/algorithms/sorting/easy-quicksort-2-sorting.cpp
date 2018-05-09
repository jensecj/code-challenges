/*
  tags: sorting, quicksort
  task: quicksort an array, print each subarray after it has been merged
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

void quick_sort(vector<int>& v) {
  if (v.size() < 2)
    return;

  vector<int> left;
  vector<int> right;

  int pivot = v[0];

  for (int i = 1; i < v.size(); ++i) {
    if (v[i] <= pivot)
      left.push_back(v[i]);
    else
      right.push_back(v[i]);
  }

  quick_sort(left);
  quick_sort(right);

  int index = 0;
  for (int i = 0; i < left.size(); i++) {
    v[index++] = left[i];
    cout << left[i] << " ";
  }

  v[index++] = pivot;
  cout << pivot << " ";

  for (int i = 0; i < right.size(); i++) {
    v[index++] = right[i];
    cout << right[i] << " ";
  }

  cout << endl;
}

int main() {
  int n; // number of ints to sort
  cin >> n;

  vector<int> nums(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  quick_sort(nums);
}
