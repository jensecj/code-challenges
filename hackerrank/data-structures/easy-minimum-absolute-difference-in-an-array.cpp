/*
  tags: simple math
  task: given a sequence of numbers, find the minimum absolute
  difference between any two numbers and print it.
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; // integers in the array
  cin >> n;

  vector<long> nums(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  sort(nums.begin(), nums.end());

  // linear time since we sorted the list first, including sort,
  // O(n) + O(n log n) = O(n log n)
  long min = LONG_MAX;
  for(int i = 1; i < n; i++) {
    long num = abs(nums[i] - nums[i-1]);
    if(num < min)
      min = num;
  }

  // naive approach, O(N^2)
  // for(int i = 0; i < n; i++) {
  //   for(int j = i+1; j < n; j++) {
  //     cerr << nums[i] << " - " << nums[j] << endl;
  //     if(abs(nums[i] - nums[j]) < min)
  //       min = abs(nums[i] - nums[j]);
  //   }
  // }

  cout << min << endl;
}
