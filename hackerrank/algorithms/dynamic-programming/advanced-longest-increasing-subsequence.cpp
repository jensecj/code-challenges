/*
  tags: dp, dynamic programming, longest increasing subsequence, LIS
  task: find the longest increasing subsequence in an array of numbers
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearchCeil(vector<int> &v, int left, int right, int key) {
  while (right - left > 1) {
    int middle = left + (right - left) / 2;
    if (v[middle] >= key)
      right = middle;
    else
      left = middle;
  }

  return right;
}

// finds the longest increasing subsequence by keeping a running list
// of the 'best' sequence, everytime we find a new better ending to
// the list, we append it to the best sequence, and if we find a lower
// number which starts a new longer sequence, we find the position in
// the old best list, and replace it with the new better list. for
// each N elements in the array, we there fore may do binary search,
// whic is log n, so the running time is O(n log n). note that LIS
// here not is the actual largest subsequence, but an auxiliary array
// used to keep track of the last numbers of the sequences, and the
// length of that array is the length of the largest subsequence. to
// actually get the largest subsequence we coult use a parent array
// for each element.
int lis_nlogn(vector<int> &v) {
  if (v.size() == 0)
    return 0;

  vector<int> LIS(v.size());
  // the 'length' of the LIS, we only increase this when we find a new
  // end element to append, so it represents the actual length of the
  // LIS.
  int length = 1;

  // the first value in the array starts as our smallest value
  LIS[0] = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] < LIS[0])
      // v[i] is the new smallest value
      LIS[0] = v[i];
    else if (v[i] > LIS[length-1])
      // v[i] extends largest subsequence
      LIS[length++] = v[i];
    else
      // v[i] becomes end candidate of a new subsequence
      LIS[BinarySearchCeil(LIS, -1, length - 1, v[i])] = v[i];
  }

  return length;
}

// finds the longest increasing subsequence using a bottom-up
// approach, this algorithm checks for each number in the sequence, if
// this is a longest subsequence, and it does that by looking at the
// numbers before it, which we have calculated first. (thus bottom-up)
// runtime is O(N^2), because, for each number, we check all
// the other numbers to see if this new number is the end of a new
// longest increasing subsequence.
int lis(vector<int>& array) {
  vector<int> sequences(array.size(), 1);
  // fill(sequences.begin(), sequences.end(), 1);

  int max = 0;
  for(int i = 0; i < array.size(); i++)
    for(int j = 0; j < i; j++)
      if((array[i] > array[j]) && sequences[i] < sequences[j] + 1)
        sequences[i] = sequences[j] + 1;

  return *max_element(sequences.begin(), sequences.end());
}

int main() {
  int N; // numbers in array
  cin >> N;

  vector<int> array(N);
  for(int i = 0; i < N; i++)
    cin >> array[i];

  cout << lis_nlogn(array) << endl;
}
