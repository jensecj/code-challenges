/*
  tags: loops
  task: given a 2d array, mirror it vertically, and horizontally
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  int tests = T;

  while(T--) {
    int r,c; // rows and columns in image
    cin >> r >> c;

    vector<vector<char>> img(r, vector<char>(c));
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        cin >> img[i][j];
      }
    }
    cout << "Test " << tests-T << endl;
    for(int i = r-1; i >= 0; i--) {
      for(int j = c-1; j >= 0; j--) {
        cout << img[i][j];
      }
      cout << endl;
    }
  }
}
