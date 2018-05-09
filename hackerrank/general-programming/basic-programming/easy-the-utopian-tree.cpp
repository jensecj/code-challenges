/*
  tags: simple math
  task: given a tree that has two growth cycles every year, one where
  it doubles it height, and one where it grows one meter, and its
  initial height being 1m. how tall is it after N growth cycles?
*/
#include <iostream>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int N; // the number of growth cycles
    cin >> N;

    int height = 1;
    for (int i = 0; i < N; i++) {
      if(i % 2 == 0)
        height *= 2;
      else
        height++;
    }

    cout << height << endl;
  }
}
