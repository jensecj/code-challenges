/*
  tags: hashmap, brute force, array
  task: given an array, find the pair of elements, whose indices
  differ, but are the same number, which have the smallest distance
  between them in the array
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// runtime is O(n^2), since, for each element in the array, we look at
// all other elements in the array to calculate their distance if
// they're the same number, space is O(n)
void solve_brute_force(vector<int>& nums) {
  int n = nums.size();
  int min = n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(nums[i] == nums[j] && i != j)
        if(abs(i-j) < min)
          min = abs(i-j);
    }
  }

  if(min == n)
    cout << -1 << endl;
  else
    cout << min << endl;
}

// runtime is O(n), since we only run through the array once, and save
// the indices for each element we have seen before, or check the
// distance and update the minimum if we have seen it. space is O(n)
void solve_cache(vector<int>& nums) {
  int n = nums.size();
  unordered_map<int, int> cache;

  int min = n;

  for (int i = 0; i < n; i++) {
    if(cache.find(nums[i]) != cache.end()) {
      int dist = i - cache[nums[i]];
      if(dist < min) min = dist;
    } else {
      cache[nums[i]] = i;
    }
  }

  if(min == n) cout << -1 << endl;
  else cout << min << endl;

}

int main() {
  int n; // size of the array
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  // solve_brute_force(nums);
  solve_cache(nums);
}
