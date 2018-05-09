/*
  tags: inversions, permutations, parity, even / odd mess
  task: given an array of numbers, and the ability to make a type of
  rotation, which is in this case a left shift of three elements in
  the array, tell whether you are able to completely sort the array
  using only that operation.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long merge_and_count_array(vector<int>& arr, int low, int middle, int high, vector<int>& aux) {
  long inversions = 0;

  int left_idx = low;
  int right_idx = middle + 1;
  int idx = low;

  // while there are still elements in the split arrays
  while(left_idx <= middle || right_idx <= high) {
    if(left_idx > middle) // we already used all elements from the left array
      arr[idx++] = aux[right_idx++];
    else if (right_idx > high) // we already used all elements from the right array
      arr[idx++] = aux[left_idx++];
    else if (aux[left_idx] <= aux[right_idx]) // the elements we are looking at are already sorted
      arr[idx++] = aux[left_idx++];
    else { // we need to make an inversion, since the elements are out
           // of order (the left element is greater than the right
           // one) the rest of the elements to the right must
           // also be out of order
      arr[idx++] = aux[right_idx++];
      inversions += middle + 1 - left_idx;
    }
  }

  return inversions;
}

long sort_and_count_array(vector<int>& arr, int low, int high, vector<int>& aux) {
  if (low >= high)
    return 0;

  int middle = low + (high - low) / 2;

  long inversions = 0;
  inversions += sort_and_count_array(aux, low, middle, arr);
  inversions += sort_and_count_array(aux, middle + 1, high, arr);
  inversions += merge_and_count_array(arr, low, middle, high, aux);

  return inversions;
}

long count_inversions(vector<int>& arr) {
  vector<int> aux(arr);
  return sort_and_count_array(arr, 0, arr.size() - 1, aux);
}

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int n; // number of elements in array
    cin >> n;

    vector<int> array(n);
    for(int i = 0; i < n; i++)
      cin >> array[i];

    int inversions = count_inversions(array);

    // this puzzle is an even mess, so we can only solve it if it has
    // an even number of permutations to begin with, since a rotation
    // of the sort we are allowed to do does not change the parity of
    // the permutations
    if(inversions % 2 != 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
