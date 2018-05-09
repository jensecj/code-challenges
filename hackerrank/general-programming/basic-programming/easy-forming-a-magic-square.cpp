/*
  tags: magic square, matrix
  task: given a 3x3 matrix, calculate how many changes need to be made
  to make it into a magic square (e.g. all columns, rows, and
  diagonals sum to the same number)
  note: kind of a silly problem, there is not proper solution except
  for hardcoding the possible magic circles, trying this for anything
  marginely larger than 3x3 would be infeasible since the problem is
  NP-hard.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  vector<vector<int>> matrix(3, vector<int>(3));

  for (int i = 0; i < 3; i++) {
    cin >> matrix[i][0];
    cin >> matrix[i][1];
    cin >> matrix[i][2];
  }

  // the 8 possible magic squares for a 3x3 matrix
  int arr[8][9]={
    {8,1,6,3,5,7,4,9,2},
    {6,1,8,7,5,3,2,9,4},
    {4,9,2,3,5,7,8,1,6},
    {2,9,4,7,5,3,6,1,8},
    {8,3,4,1,5,9,6,7,2},
    {4,3,8,9,5,1,2,7,6},
    {6,7,2,1,5,9,8,3,4},
    {2,7,6,9,5,1,4,3,8},
  };


  int sum = 999, idx = 0;
  // we look through all the 8 magic squares that exist for 3x3
  for (int x = 0; x < 8; x++) {
    int k = 0;
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        // count the errors, we only run through idx for the first
        // array because it was easier to input
        k += abs(arr[0][idx++] - matrix[i][j]);

    if(k < sum)
      sum = k;
  }

  cout << sum << endl;
}
