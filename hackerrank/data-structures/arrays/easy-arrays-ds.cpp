/*
  tags: arrays
  task: given an array, print it in reverse
*/

#include <iostream>

using namespace std;

int main() {
  int N; // number of integers in the array
  cin >> N;

  int A[N];

  for(int i = 0; i < N; i++)
    cin >> A[i];

  for(int i = N-1; i >= 0; i--)
    cout << A[i] << " ";

  cout << endl;
}
