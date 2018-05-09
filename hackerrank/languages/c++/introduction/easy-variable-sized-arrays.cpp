/*
  tags: array
  task: play with 2darrays
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, q; // the number of arrays, and the number of queries
  cin >> n >> q;
  cerr << "number of rows: " << n << ", queries: " << q << endl;

  vector<vector<int>> matrix(n);

  for (int i = 0; i < n; i++) {
    int k; // how many elements are in this array
    cin >> k;

    vector<int> karray(k);

    for (int j = 0; j < k; j++) {
      cin >> karray[j];
    }

    matrix[i] = karray;
  }

  for (int i = 0; i < q; i++) {
    int a,b; // a query to print the element at matrix[a][b];
    cin >> a >> b;
    cerr << "print element at " << a << "," << b << endl;

    cout << matrix[a][b] << endl;
  }
}
