/*
  tags: algorithm analysis, insertion sort
  task: count the number of shifts in insertion sort
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void print_vec(vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  } cout << endl;
}

void swap(vector<int>& v, int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int insertion_sort(vector<int>& v) {
  int shifts = 0;
  for(int i = 1; i < v.size(); i++) {
    int idx = i-1;
    while(idx >= 0 && v[idx] > v[idx+1]) {
      swap(v, idx, idx+1);
      idx--;
      shifts++;
    }
  }
  return shifts;
}

int main() {
  int n; // number of ints to sort
  cin >> n;

  vector<int> nums(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  int shifts = insertion_sort(nums);

  cout << shifts << endl;
}
