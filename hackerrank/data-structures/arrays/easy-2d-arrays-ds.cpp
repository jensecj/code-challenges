/*
  tags: 2d arrays, matrix substructure
  task: given a 2d array, find the hourglass figure (above-1, above,
  above+1, left, right, below-1, below, below+1), that has the highest
  sum in the 2darray
*/
#include <iostream>
#include <climits>

using namespace std;

int main() {
  int arr[6][6];

  for(int i=0; i < 6; i++){
    for(int j=0; j < 6; j++){
      cin >> arr[i][j];
    }
  }

  int max_sum = INT_MIN;

  // there are 16 hour glasses in a 6x6 matrix, 4 across and 4 down
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      int sum = arr[i][j]   + arr[i][j+1]   + arr[i][j+2] +
        arr[i+1][j+1] +
        arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

      if(sum > max_sum)
        max_sum = sum;
    }
  }

  cout << max_sum;
}
