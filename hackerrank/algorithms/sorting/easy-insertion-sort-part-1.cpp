/*
  tags: sorting, insertion sort
  task: given an array of sorted numbers, and a new element to insert
  from the right, print the process of moving elements one to the
  right, until you end up at the spot for the new number.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

void print_vec(vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  } cout << endl;
}

int main() {
  int size; // size of array
  cin >> size;

  vector<int> ar(size);
  for(int i = 0; i < size; i++)
    cin >> ar[i];

  int e = ar[size-1]; // the out of place element

  for(int i = size-2; i >= 0; i--) {
    if(ar[i] > e)
      ar[i+1] = ar[i];
    else {
      ar[i+1] = e;
      break;
    }

    print_vec(ar);
  }

  // we're at the first element
  if(ar[0] > e)
    ar[0] = e;

  print_vec(ar);
}
