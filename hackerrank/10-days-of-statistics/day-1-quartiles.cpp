/*
  tags: statistics, quartiles
  task: calculate the first, second and third quartiles of an array of
  integers
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

// average of two middle numbers, if an odd number of elements, just
// return the middle element
double median(vector<int> v) {
  if(v.empty())
    return 0;

  if(v.size() < 2)
    return v[0];

  int middle = v.size() / 2;

  if(v.size() % 2 == 0)
    return (v[middle - 1] + v[middle]) / 2;
  else
    return v[middle];
} 

int main() {
  int n; // numbers in the array
  cin >> n;

  vector<int> nums(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  // the array should be non-decreasing
  sort(nums.begin(), nums.end());

  for(int i = 0; i < n; i++) {
    cerr << nums[i] << " ";
  } cerr << endl;

  // middle element
  double middle = n/2;

  // split the array into halves based on if it has an even or odd
  // number of elements, if it has an odd number, we ignore the middle
  int lower_half;
  int higher_half;
  if(n % 2 == 0) {
    lower_half = floor(middle);
    higher_half = ceil(middle);
  } else {
    lower_half = middle;
    higher_half = middle + 1;
  }

  vector<int> lower(nums.begin(), nums.begin() + lower_half);
  vector<int> higher(nums.begin() + higher_half, nums.end());

  for(int i = 0; i < lower.size(); i++) {
    cerr << lower[i] << " ";
  } cerr << endl;
  for(int i = 0; i < higher.size(); i++) {
    cerr << higher[i] << " ";
  } cerr << endl;

  // print the quartiles
  cout << median(lower) << endl;
  cout << median(nums) << endl;
  cout << median(higher) << endl;
}
