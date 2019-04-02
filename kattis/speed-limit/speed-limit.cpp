/*
  tags: arrays
  task: given a driving schedule, on the form, (2:20, 3:15, ...),
  meaning, for the first two hours, we drone 20 mph, for the next
  (3-2=1) hours we drove 15 mph... calculate the total miles driven
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  while(n != -1) {
    vector<int> miles(n);
    vector<int> hrs(n);
    for (int i = 0; i < n; i++) {
      cin >> miles[i];
      cin >> hrs[i];
    }

    int total = miles[0]*hrs[0];
    for (int i = 1; i < n; i++) {
      total += miles[i]*(hrs[i]-hrs[i-1]);
    }

    cout << total << " miles" << endl;

    cin >> n;
  }
}
