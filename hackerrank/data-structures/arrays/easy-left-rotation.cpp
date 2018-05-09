/*
  tags: arrays, left rotation
  task: given an array, perform some left shifts
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // the number of integers in the array
  int d; // how much to left-rotate the array
  cin >> n >> d;

  vector<int> a(n);

  for(int i = 0; i < n; i++)
    cin >> a[i];

  // we do not have to actually change the array to do left/right
  // rotations, we can just move an index
  int index = d;

  for(int i = 0; i < n; i++)
    cout << a[(i+index) % n] << " ";
}
