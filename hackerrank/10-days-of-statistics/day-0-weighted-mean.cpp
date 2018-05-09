/*
  tags: statistics, weighted mean
  task: given a list of elements, and a list of the weights of the
  elements in the first list, calculate the weighted mean
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int N; // number of elements
  cin >> N;

  vector<int> X(N); // elements
  vector<int> W(N); // weights of elements in X

  for(int i = 0; i < N; i++)
    cin >> X[i];

  for(int i = 0; i < N; i++)
    cin >> W[i];

  double sum = 0;
  int weight_sum = 0;

  for(int i = 0; i < N; i++) {
    sum += W[i] * X[i];
    weight_sum += W[i];
  }

  cout << fixed << setprecision(1) << sum / weight_sum << endl;
}
