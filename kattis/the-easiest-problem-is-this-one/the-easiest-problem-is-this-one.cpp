/*
  tags: sum of digits
  task: given a number, find the smallest number, that when multiplied
  by the original, has the same sum of digits (must be higher than 10)
*/
#include <iostream>
#include <string>

using namespace std;

int sum_of_digits(int N) {
  int sum = 0;
  string Nts = to_string(N);
  for(auto& i : Nts)
    sum += i - '0';

  return sum;
}

int main() {
  int N; // number to test
  cin >> N;

  while(N != 0) {
    cerr << "N: " << N;

    int sum = sum_of_digits(N);
    cerr << ", sum: " << sum << endl;

    // N is at most 100.000,, which has the highest sum of 9+9+9+9+9=45
    for (int i = 11; i < 45*N; i++) {
      int s = sum_of_digits(i*N);
      if(s == sum) {
        cout << i << endl;
        break;
      }
    }

    cin >> N;
  }
}
