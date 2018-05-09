/*
  tags: sorting
  task: given an array of numbers, how many swaps are required to turn
  the array beautiful? a beautiful array is one where the absolute
  difference between neighbours is minimal.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solve(vector<long>& A) {
  // a map that holds the original index for all elements in the array
  unordered_map<long,long> M;
  for(int i = 0; i < A.size(); i++)
    M[A[i]] = i;

  // we sort the array so we can compare whether elements are in their
  // right place or not, this is O(n log n), and the next part is
  // O(n), since we run through all elements once, so the runtime
  // complexity is the same as if we had calculated the swaps inside
  // an implementation of sort.
  vector<long> S(A);
  sort(S.begin(), S.end());

  int swaps = 0;

  for(int i = 0; i < A.size(); i++) {
    // the element from the original place is not in its
    if(A[i] != S[i]) {
      swaps++;

      // update the location in the map
      M[A[i]] = M[S[i]];

      // swap the elements
      int idx = M[S[i]];
      A[idx] = A[i];
      A[i] = S[i];
    }
  }

  return swaps;
}

int main() {
  int n; // size of array
  cin >> n;

  vector<long> nums(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  vector<long> clone(nums);

  // we pick the least swaps we can make, since we can sort the array
  // both increasingly, and decreasingly (and both would result in a
  // 'beautiful' array)
  long swaps_inc = solve(nums);
  reverse(clone.begin(), clone.end());
  long swaps_dec = solve(clone);

  cout << min(swaps_inc, swaps_dec) << endl;
}
