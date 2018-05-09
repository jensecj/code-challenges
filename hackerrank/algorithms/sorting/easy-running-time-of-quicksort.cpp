/*
  tags: sorting
  task: compare the number of swaps that quicksort and insertion sort
  does sorting some arrays.
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

int iswaps = 0, qswaps = 0;

void iswap(vector<int>& A, int i, int j) {
  int tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
  iswaps++;
}

void qswap(vector<int>& A, int i, int j) {
  int tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
  qswaps++;
}

int partition(vector<int>& A, int lo, int hi) {
  int pivot = A[hi];
  int i = lo-1;
  for(int j = lo; j <= hi - 1; j++) {
    if(A[j] <= pivot) {
      i++;
      qswap(A, i, j);
    }
  }
  qswap(A, i+1, hi);


  return i + 1;
}

void quicksort(vector<int>& A, int lo, int hi) {
  if(lo < hi) {
    int p = partition(A, lo, hi);
    quicksort(A, lo, p-1);
    quicksort(A, p+1, hi);
  }
}

void insertion_sort(vector<int>& v) {
  for(int i = 1; i < v.size(); i++) {
    for(int j = 0; j < i; j++) {
      if(v[i] < v[j]) {
        iswap(v, i, j);
      }
    }
  }
}


int main() {
  int n; // size of array
  cin >> n;

  vector<int> ar(n);
  for(int i = 0; i < n; i++)
    cin >> ar[i];

  vector<int> qar(ar);
  quicksort(qar, 0, n-1);

  vector<int> iar(ar);
  insertion_sort(iar);

  cout << iswaps - qswaps << endl;
}
