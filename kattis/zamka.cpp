/*
  tags: bounds
  task: given three numbers, a lower bound L, an upper bound D, and a
  sum X. find the biggest and smallest number s.t. L <= i <= D, and
  the digits of i sum to X.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  int L, D, X; // L is lower bound, D is upper, X is the number digits
               // has to sum to
  cin >> L >> D >> X;

  int lower;
  for (int i = L; i <= D; i++) {
    string nts = to_string(i);

    int sum = 0;
    for(auto& c : nts) {
      sum += (c - '0');
    }

    if(sum == X) {
      lower = i;
      break;
    }
  }

  int higher;
  for (int i = D; i >= L; i--) {
    string nts = to_string(i);

    int sum = 0;
    for(auto& c : nts) {
      sum += (c - '0');
    }

    if(sum == X) {
      higher = i;
      break;
    }
  }

  cout << lower << endl;
  cout << higher << endl;
}
