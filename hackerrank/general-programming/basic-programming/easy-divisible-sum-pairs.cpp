/*
  tags: mod arithmetic
  task: given an array of integers, and an integer k, count the number
  of pairs where i != j, for indices i and j into the array, and where
  the addition of the elements corresponding to those indices is
  evenly divisible with k.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k; // the amount of numbers in our array, and the number to
            // check divisibility against
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  int pairs = 0;

  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      if((nums[i]+nums[j]) % k == 0)
        pairs++;

  cout << pairs << endl;
}
