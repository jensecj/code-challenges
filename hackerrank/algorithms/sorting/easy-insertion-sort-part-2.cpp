/*
  tags: sorting, insertion sort
  task: given an array of unsorted numbers, sort them, printing each
  step in the process (after each number has been put in its place,
  from front to back)
*/
#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  } cout << endl;
}

void swap(vector<int>& v, int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void insertion_sort(vector<int>& v) {
  for(int i = 1; i < v.size(); i++) {
    for(int j = 0; j < i; j++) {
      if(v[i] < v[j]) {
        swap(v, i, j);
      }
    }
    print_vec(v);
  }
}

int main() {
  int size; // size of array
  cin >> size;

  vector<int> ar(size);
  for(int i = 0; i < size; i++)
    cin >> ar[i];

  insertion_sort(ar);
}
