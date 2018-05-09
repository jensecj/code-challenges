/*
  tags: sorting
  task: given a list of numbers, count how many times each number
  occurs (the numbers range from [0,100])
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
    counts[nr]++;
  }

  for(int i = 0; i < counts.size(); i++) {
    cout << counts[i] << " ";
  } cout << endl;
}
