/*
  tags: list, difference array
  task: given an empty list of size N, and M queries that look like
  (a,b,k), a query asks you to add k to the elements in the list in
  the range [a,b]. after performing all the operations, output the
  maximum value in the list.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M; // size of list, and number of operations to perform
  cin >> N >> M;

  // instead of simply updating the range in the array, this problems
  // begs us to use a difference array instead, here we simply
  // increase a with k, and decrease b+1 with k, then in the end, we can
  // reconstruct the original list if needed, or, since we only need
  // to find the maximum number in the array, we can simply sum
  // through all the numbers, keeping track of the biggest sum seen.
  vector<long> list(N+1);

  for (int i = 0; i < M; i++) {
    int a, b, k; // range [a,b], and value to add, k
    cin >> a >> b >> k;

    list[a] += k;

    if(b+1 <= N)
      list[b+1] -= k;
  }

  long max = 0;
  long acc = 0;

  for(const long& i : list) {
    acc += i;
    if(max < acc)
      max = acc;
  }

  cout << max << endl;
}
