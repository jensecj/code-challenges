/*
  tags: sorting
  task: given two arrays, and a number k, can you create some
  permutaitons of the arrays such that a[i] + b[i] >= k for all i.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
  int q;
  cin >> q;

  // the idea here is that is we sort one array increasingly, and one
  // decreasingly, and make pairs element for element, we will always
  // have made the optimal choice in making pairs (smallest
  // absolute distance), so there is no better pick, since we need to
  // pair all elements in both arrays.
  while(q--) {
    int n,k; // size of arrays, and number to be above
    cin >> n >> k;
    // cerr << "n: " << n << ", k: " << k << endl;

    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    vector<int> B(n);
    for(int i = 0; i < n; i++) cin >> B[i];

    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());

    bool possible = true;

    for(int i = 0; i < n; i++) {
      if(A[i] + B[i] < k)
        possible = false;
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
