/*
  tags: min max
  task: Given five positive integers (64bit), find the minimum and maximum
  values that can be calculated by summing exactly four of the five
  numbers. Then print the respective minimum and maximum values as a
  single line of two space-separated long integers.
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
  vector<long> nums(5);

  long min = LONG_MAX;
  long max = LONG_MIN;
  long sum = 0;

  for (int i = 0; i < 5; i++) {
    cin >> nums[i];
    sum += nums[i];
    if(nums[i] > max) {
      max = nums[i];
      cerr << "new max: " << max << endl;
    }
    if (nums[i] < min) {
      min = nums[i];
      cerr << "new min: " << min << endl;
    }
  }

  // we can cheat, because we know we have to use all but one number,
  // the smallest subset we can get, is if we exclude the biggest
  // number from the array, and the biggest we can get, is if we
  // exclude the smallest number
  cout << (sum - max) << " " << (sum - min) << endl;
}
