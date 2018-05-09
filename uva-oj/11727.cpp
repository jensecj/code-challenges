/*
  tags: simple
  task: given three numbers, find the middle one (not the highest or lowest)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;

  int case_no = 1;
  while(T--) {
    int p[3];
    cin >> p[0] >> p[1] >> p[2];

    sort(begin(p), end(p));

    cout << "Case " << case_no++ << ": " << p[1] << endl;
  }
}
