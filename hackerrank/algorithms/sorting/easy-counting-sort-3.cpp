/*
  tags: sorting
  task: given an sequence of numbers, from 1,...,99, tell how many
  numbers from the sequence were less than or equal to i.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // number of ints
  cin >> n;

  vector<int> counts(100);
  for(int i = 0; i < n; i++) {
    int nr;
    cin >> nr;
    cin.ignore(10, '\n');

    counts[nr]++;
  }

  int sum = 0;
  for(int i = 0; i < counts.size(); i++) {
    sum += counts[i];
    cout << sum << " ";
  } cout << endl;
}
