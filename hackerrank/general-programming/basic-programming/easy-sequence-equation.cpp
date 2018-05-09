/*
  tags: hashmap
  task: given a sequence of integers, p(1), p(2), ..., p(n). you task
  is, for 1,...,n, to print y satisfying the equation p(p(y)) = x
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n; // the number of elements in the sequence
  cin >> n;

  unordered_map<int,int> map;

  // for each input we get, we save which index, p(i) points to, this
  // way, we can do the reverse lookup from the p-values from 1,...,n
  for (int i = 1; i <= n; i++) {
    // p(i) = n;
    int n;
    cin >> n;

    map[n] = i;
  }

  // reverse lookup
  for (int i = 1; i <= n; i++) {
    int a = map[i];
    int b = map[a];

    cout << b << endl;
  }
}
