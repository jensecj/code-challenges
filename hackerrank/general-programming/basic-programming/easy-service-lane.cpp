/*
  tags: loop
  task: given a range of numbers (describing how wide an opening is
  along a road), and some queries into the range, figure out what the
  widest thing that can pass through the path that the query
  represents is.
  note: the problem text for the problem on hackerrank is a lot more
  involved than the actual problem.
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int N, T; // length of the freeway, and the number of test cases
  cin >> N >> T;

  vector<int> range(N);
  for (int i = 0; i < N; i++)
    cin >> range[i];

  while(T--) {
    int i,j; // the range to test
    cin >> i >> j;

    // the minimum number along the path that the query represents is
    // the biggest thing that can pass through this entire path
    int min = INT_MAX;
    for (int x = i; x <= j; x++)
      if(range[x] < min)
        min = range[x];

    cout << min << endl;
  }
}
