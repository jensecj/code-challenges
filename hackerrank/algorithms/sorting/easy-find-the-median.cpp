/*
  tags: sorting
  task: given a list of numbers, find the median
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; // size of array
  cin >> n;

  vector<int> ar(n);
  for(int i = 0; i < n; i++)
    cin >> ar[i];

  sort(ar.begin(), ar.end());

  int middle = ar.size() / 2;
  cout << ar[middle] << endl;
}
