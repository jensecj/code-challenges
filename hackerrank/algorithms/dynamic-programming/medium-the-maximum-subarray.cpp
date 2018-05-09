/*
  tags: dp, dynamic programming, longest increasing subsequence, LIS
  task: find the sums of the largest contiguous and non-contiguous
  subarrays (remember to account for arrays of negative numbers)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// kadanes algorithm, we start at one end of the array and keep track
// of two numbers as we iterate iterate through the array, the biggest
// subarray sum we have seen yet, and the biggest subarray sum ending
// at the index we are at now, we keep updating the current subarray
// sum as we run through the array, and update the max if needed.
// runtime is O(n), because we just run through the numbers once
int subarray_contiguous(vector<int>& v) {
  int max_ending_here = v[0];
  int max_so_far = v[0];

  for(int i = 1; i < v.size(); i++) {
    // update the current subarray sum
    max_ending_here = max(v[i], max_ending_here + v[i]);
    max_so_far = max(max_so_far, max_ending_here);
  }

  return max_so_far;
}

// if the sum does not have to be contiguous, we can just add all the
// positive numbers to get the biggest sum
int subarray_noncontiguous(vector<int>& v) {
  int sum = 0;

  for(const int& i: v)
    if(i > 0)
      sum += i;

  // if there are positive numbers, we print the sum, but if the array
  // only consists of negative numbers, we return the least negative one
  if(sum > 0)
    return sum;
  else
    return *max_element(v.begin(), v.end());
}

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int N; // numbers in array
    cin >> N;

    vector<int> array(N);
    for(int i = 0; i < N; i++)
      cin >> array[i];

    cout << subarray_contiguous(array) << " ";
    cout << subarray_noncontiguous(array) << endl;
  }
}
