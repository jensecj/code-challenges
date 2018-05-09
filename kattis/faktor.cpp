/*
  tags: math
  task: figure out how many people you have to bribe to reach a
  specific impact factor in a journal, given that the impact factor is
  always rounded up, and is calculated by
  (number of quotations for all articles / articles in the journal)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int A, I; // articles published, and impact factor we want
  cin >> A >> I;

  double bribes = 1;
  while(ceil(bribes/A) < I)
    bribes++;

  cout << bribes << endl;
}
