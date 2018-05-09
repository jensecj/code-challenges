/*
  tags: modulo
  task: given a set of n numbers, and a number k, find the maximum
  subset where no two numbers in the subset sum to a number that is
  evenly divisible by k
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n,k; // the number of integers in the set, and the number
           // subsets should not be evenly divisible by
  cin >> n >> k;

  vector<int> counts(k+1, 0);

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;

    // two numbers, (a,b) are evenly divisible by k, (a + b) % k == 0,
    // if (a % k + b % k) == k, (e.g if their remainders after division
    // with k, equals k), so instead of recording all the numbers, we
    // record their remainder after division with k.
    counts[num % k] += 1;
  }

  int subsets = min(counts[0], 1);

  int upto = k/2;
  if (upto * 2 == k)
    upto -= 1;

  for (int i = 1; i <= upto; ++i)
    subsets += max(counts[i], counts[k-i]);

  if (k % 2 == 0)
    if (counts[k/2] > 0)
      subsets++;

  cout << subsets << endl;
}
