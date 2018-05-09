/*
  tags: statistics, mean, median, mode
  task: given a list of numbers, find the mean, median, and mode.
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  double N; // number of elements in the array
  cin >> N;

  vector<int> nrs(N);
  for(int i = 0; i < N; i++)
    cin >> nrs[i];

  double mean = accumulate(nrs.begin(), nrs.end(), 1) / N;
  cout << mean << endl;

  sort(nrs.begin(), nrs.end());

  int middle = nrs.size()/2-1;
  double median = (nrs[middle] + nrs[middle+1]) / 2.0;
  cout << median << endl;

  unordered_map<int,int> seen;

  int mode = 0;
  int max = 0;
  for(auto& n : nrs) {
    seen[n]++;

    if(seen[n] > max) {
      max = seen[n];
      mode = n;
    }
  }

  cout << mode << endl;
}
