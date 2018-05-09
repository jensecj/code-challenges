/*
  tags: subsets in array
  task: given an array of numbers, calculate how many ways there are
  of 'breaking' the array into blocks of m, so the blocks sum to d
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // number of squares in the chocolate bar
  cin >> n;
  cerr << "n: " << n << endl;
  vector<int> squares(n);
  while(n--)
    cin >> squares[n];

  int d, m; // rons birthday and month
  cin >> d >> m;
  cerr << "d: " << d << ", m: " << m << endl;

  int ways = 0;

  // m is the size of our sliding window
  for (int i = 0; i < squares.size()-m+1; i++) {
    cerr << "i: " << i << endl;
    int sum = 0;
    for (int j = 0; j < m; j++)
      sum += squares[i+j];

    cerr << "sum: " << sum << endl;
    if(sum == d)
      ways++;
  }
  cerr << "ways to break off " << m << " pieces of chocolate so they sum to " << d << " = ";
  cout << ways << endl;
}
