/*
  tags: array, rotation
  task: given an array, and k 'circular-right-rotations', where
  [1,2,3] -> [3,1,2] is a single right rotation, recieve some queries
  to print elements at some indices.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, q; // the number of elements in the array, the number of
               // times to perform the 'right-curcular-rotation', and
               // the number of queries for elements to print
  cin >> n >> k >> q;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  long index = 0;
  for (int i = 0; i < k; i++) {
    index += n-1; // the same as moving back 1 element
    // cerr << i << ": index is now " << index << " = " << nums[index%n] << endl;
  }

  while(q--) {
    int m; // the indes of the element we're asked to print
    cin >> m;

    cout << nums[(index + m) % n] << endl;
  }
}
