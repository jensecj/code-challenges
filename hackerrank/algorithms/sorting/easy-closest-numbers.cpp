/*
  tags: sorting
  task: given an array of sorted numbers, find the pairs of numbers
  which have the smalles absolute difference, there can be more than
  one pair of closest numbers.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

int main() {
  int n; // size of array
  cin >> n;

  vector<int> nums(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  sort(nums.begin(), nums.end());

  vector<pair<int,int>> pairs;
  int min_dist = INT_MAX;
  for(int i = 1; i < n; i++) {
    int dist = abs(nums[i] - nums[i-1]);
    if(dist == min_dist)
      pairs.push_back(make_pair(min(nums[i], nums[i-1]), max(nums[i], nums[i-1])));
    if(dist < min_dist) {
      min_dist = dist;
      pairs.clear();
      pairs.push_back(make_pair(min(nums[i], nums[i-1]), max(nums[i], nums[i-1])));
    }
  }

  for(int i = 0; i < pairs.size(); i++) {
    cout << pairs[i].first << " " << pairs[i].second << " ";
  } cout << endl;
}
