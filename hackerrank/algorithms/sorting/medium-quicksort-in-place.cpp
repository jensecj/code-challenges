/*
  tags: sorting
  task: implement in-place quicksort
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& A) {
  for(int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  } cout << endl;
}

void swap(vector<int>& A, int i, int j) {
  int tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

int partition(vector<int>& A, int lo, int hi) {
  int pivot = A[hi];
  int i = lo-1;
  for(int j = lo; j <= hi - 1; j++) {
    if(A[j] <= pivot) {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i+1, hi);


  return i + 1;
}

void quicksort(vector<int>& A, int lo, int hi) {
  if(lo < hi) {
    int p = partition(A, lo, hi);
    print(A);

    quicksort(A, lo, p-1);
    quicksort(A, p+1, hi);
  }
}

int main() {
  int n; // size of array
  cin >> n;

  vector<int> ar(n);
  for(int i = 0; i < n; i++)
    cin >> ar[i];

  quicksort(ar, 0, n-1);
}
