/*
  tags: math
  task: reconstruct a number we forgot, from the mean and one other number
*/
#include <iostream>

using namespace std;

int main() {
  int R1, S; // one number of the equation, and the mean value
  cin >> R1 >> S;

  // S = (R1+R2)/2 <=> 2*S = R1+R2 <=> (2*S)-R1 = R2
  cout << (2*S) - R1 << endl;
}
