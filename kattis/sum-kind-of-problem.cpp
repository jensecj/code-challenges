/*
  tags: math
  task: given a number N, print the sums of the first N integers, the
  first N odd integers, and the first N even integers
*/
#include <iostream>

using namespace std;

int main() {
  int P; // number of datasets
  cin >> P;

  while(P--) {
    int nr, N; // number of dataset, and its integer
    cin >> nr >> N;

    long sum_up_to_n = N*(N+1)/2;
    long sum_first_n_odds = N*N;
    long sum_first_n_evens = N*(N+1);

    cout << nr << " "
         << sum_up_to_n << " "
         << sum_first_n_odds << " "
         << sum_first_n_evens << endl;
  }
}
