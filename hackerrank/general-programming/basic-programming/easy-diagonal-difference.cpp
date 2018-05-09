/*
  tags: arrays, matrix, simple math
  task: given a matrix (2darray), calculate the absolute difference
  between the sums of its diagonals
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; // the size of the matrix (N*N)
  cin >> N;

  vector<vector<int>> matrix(N, vector<int>(N));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> matrix[i][j];

  int backslash = 0;
  for (int i = 0; i < N; i++)
    backslash += matrix[N-1-i][i];

  int forwardslash = 0;
  for (int i = 0; i < N; i++)
    forwardslash += matrix[i][i];

  cout << abs(forwardslash - backslash) << endl;

}
