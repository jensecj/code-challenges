/*
  tags:
  task:
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>

using namespace std;

long long solve_rec(vector<long long>& array, int index, vector<long long>& scores, long long& running_sum) {
  if(index == array.size())
    return accumulate(scores.begin(), scores.end(), 0);

  return 0;
  // max(solve(array, index, scores, running_sum),
  // solve(array, index + 1, aside, scores, running_sum));
}

long long solve(vector<long long>& v) {
  int n = v.size();

  long long max = 0;
  for(int i = 0; i < n; i++) {
    vector<long long> scores(n);
    long long running_sum;
    long long cur = solve_rec(v, i, scores, running_sum);
    if(cur > max)
      max = cur;
  }

  return max;
}

int median_idx(vector<long long> v) {
  if(v.empty() || v.size() < 2)
    return 0;

  int middle = v.size() / 2;

  if(v.size() % 2 == 0)
    return middle-1;
  else
    return middle;
}
long long solve1(vector<long long> nums, int x) {
  int n = nums.size();
  sort(nums.begin(), nums.end());

  vector<long long> scores(n);
  long long running_sum = 0;

  for(int i = 0; i < n; i++) {
    long long removed;
    long long max = 0;
    long long min = LLONG_MAX;
    int idx = 0;
    if(i == 0) {
      idx = x;
      // for(int j = 0; j < nums.size(); j++) {
      //   if(nums[j] < min) {
      //     min = nums[j];
      //     idx = j;
      //   }
      // }
    } else {
      for(int j = 0; j < nums.size(); j++) {
        cerr << nums[j] << " = " << (running_sum % nums[j]) << endl;
        if(running_sum % nums[j] > max) {
          max = nums[j];
          idx = j;
        }
      }
    }

    removed = nums[idx];
    nums.erase(nums.begin()+idx);
    cerr << "removed " << removed << endl;

    scores[i] = running_sum % removed;
    if(!nums.empty())
      running_sum += removed;
  }

  return accumulate(scores.begin(), scores.end(), 0);
}

int main() {
  int n; // number of elements in sequence
  cin >> n;

  vector<long long> nums(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  long long max = 0;
  for(int i = 0; i < n; i++) {
    long long res = solve1(nums, i);
    if(res > max)
      max = res;
  }

  cout << max << endl;
  // int total = solve(nums, 0, aside, scores, running_sum);
}
