/*
  tags: simple programming puzzle, arrays
  task: given a 2d matrix, find the position of the x character
*/
#include <iostream>

using namespace std;

int main() {
  int N; // grids size
  cin >> N;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      char g;
      cin >> g;

      if(g == 'X')
        cout << i << "," << j << endl;
    }
  }
}
