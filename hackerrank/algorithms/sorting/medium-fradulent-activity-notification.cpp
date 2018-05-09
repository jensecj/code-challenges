/*
  tags: sorting, median
  task: you are given a history of n transactions, and you know that
  after d transactions, if the transaction on d+1 is more than, or equal
  to 2 times the median of the last d transactions, there could have
  been fraud! you job is, given n and d, to figure out how many fraud
  attempts have occured.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <deque>

using namespace std;

int main() {
  int n,d; // n days total, and d days to use for median
  cin >> n >> d;

  vector<int> days(n);

  for(int i = 0; i < n; i++)
    cin >> days[i];

  // the sliding window of the last d days of transactions
  deque<int> window(days.begin(), days.begin()+d);

  // could use counting sort here to be quicker, because numbers are
  // <= 200, but this is fast enough to pass
  sort(window.begin(), window.end());

  int notifications = 0;

  for (int i = d; i < n; i++) {
    double median = d % 2 == 0 ?
      window[(window.size() / 2) - 1] + window[window.size() / 2] / 2.0 :
      window[window.size()/2];

    if (days[i] >= 2.0 * median)
      notifications++;

    // update the sliding window, while keeping it sorted, thsi way we
    // dont have to sort the window completely every time we move,
    // this is what makes the algorithm fast enough to pass the testcasesm
    auto old = lower_bound(window.begin(), window.end(), days[i-d]);
    window.erase(old);
    auto cur = upper_bound(window.begin(), window.end(), days[i]);
    window.insert(cur, days[i]);
  }

  cout << notifications << endl;
}
