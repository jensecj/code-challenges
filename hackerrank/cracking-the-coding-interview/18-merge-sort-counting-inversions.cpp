/*
  tags: sort, merge sort, count inversions
  task: count the number of inversions in an array of integers
*/
#include <iostream>
#include <vector>

using namespace std;

long merge_and_count_array(vector<int>& arr, int low, int middle, int high, vector<int>& aux) {
  long inversions = 0;

  int left_idx = low;
  int right_idx = middle + 1;
  int idx = low;

  // while(left_idx <= middle  && right_idx <= high) {
  //   if(aux[left_idx] <= aux[right_idx]) {
  //     arr[idx++] = aux[left_idx++];
  //   } else {
  //     cout << aux[right_idx] << "<" << aux[left_idx] << endl;
  //     arr[idx++] = aux[right_idx++];
  //     inversions += middle + 1 - left_idx;
  //   }
  // }

  // while(left_idx < middle + 1)
  //   arr[idx++] = aux[left_idx++];

  // while(right_idx < high)
  //   arr[idx++] = aux[right_idx++];

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

  // cout << "[ ";
  // for(int i = low; i <= high; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << "] = [ ";

  // for(int i = low; i <= middle; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << "] + [ ";
  // for(int i = middle+1; i <= high; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << "]";
  // cout << endl;

  long inversions = 0;
  inversions += sort_and_count_array(aux, low, middle, arr);
  inversions += sort_and_count_array(aux, middle + 1, high, arr);
  inversions += merge_and_count_array(arr, low, middle, high, aux);

  return inversions;
}

// this approach is also using merge sort, but it does away with
// creating multiple new arrays by using a single auxiliary array, so
// the space requirement is now O(2n) = O(n)
long count_inversions_merge_array(vector<int>& arr) {
  vector<int> aux(arr);
  return sort_and_count_array(arr, 0, arr.size() - 1, aux);
}

vector<int> merge_and_count(const vector<int>& a, const vector<int>& b, long& inversions) {
  vector<int> v;

  int left_idx = 0;
  int right_idx = 0;

  while(left_idx < a.size() && right_idx < b.size()) {
    if(a[left_idx] <= b[right_idx]) {
      v.push_back(a[left_idx]);
      left_idx++;
    }
    else {
      v.push_back(b[right_idx]);
      right_idx++;

      // if a[left_idx] > b[right_idx], then, since the arrays are sorted,
      // the rest of the elements of a must also be inversions
      inversions += a.size() - left_idx;
    }
  }

  while(left_idx < a.size()) {
    v.push_back(a[left_idx]);
    left_idx++;
  }

  while(right_idx < b.size()) {
    v.push_back(b[right_idx]);
    right_idx++;
  }

  return v;
}

vector<int> sort_and_count(const vector<int>& v, long& inversions) {
  if(v.size() == 1)
    return v;

  int middle = v.size() / 2;

  vector<int> left(v.begin(), v.begin() + middle);
  vector<int> right(v.begin() + middle, v.end());

  long inv_left = 0;
  left = sort_and_count(left, inv_left);
  long inv_right = 0;
  right = sort_and_count(right, inv_right);

  long inv_merge = 0;
  vector<int> result = merge_and_count(left, right, inv_merge);

  inversions = inv_left + inv_right + inv_merge;

  return result;
}

// uses a merge sort approach, and accumulates inversions at any point
// when we need to swap elements, runtime is O(n log n), since we
// split/merge the array log n times, and compare all elements as they
// are merged (although most comparisons are of sorted elements), this
// one creates new arrays for each merge step, so it also takes
// O(n log n) space
long count_inversions_merge(const vector<int>& dataset) {
  long inversions = 0;
  sort_and_count(dataset, inversions);
  return inversions;
}

// for each element in the array, we can simply count the number of
// elements to the right of it that are smaller than it is,
// runtime is O(n^2), since, for each element, we look at all other
// elements to compare.
int count_inversions_iterative(const vector<int>& dataset) {
  long inversions = 0;

  for (int i = 0; i < dataset.size() - 1; i++)
    for (int j = i+1; j < dataset.size(); j++)
      if (dataset[i] > dataset[j])
        inversions++;

  return inversions;
}

int main() {
  int d; // the number of datasets
  cin >> d;
  for(int i = 0; i < d; i++) {
    int n; // number of elements in this dataset
    cin >> n;

    vector<int> dataset(n);
    for(int j = 0; j < n; j++) {
      cin >> dataset[j];
    }

    cout << count_inversions_merge_array(dataset) << endl;

    // for(auto& a : dataset) {
    //   cout << a << " ";
    // }
    // cout << endl;
  }
}
