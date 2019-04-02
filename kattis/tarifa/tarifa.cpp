/*
  tags: math
  task: given that we have X megabytes of data each month, and the
  data we dont use gets transfared to the following month, and given a
  list of megabytes used in the first N months (never exceeding the
  quota), how many megabytes do we have in the n+1'th month?
*/
#include <iostream>

using namespace std;

int main() {
  int X; // megabytes of data per month
  cin >> X;

  int N; // number of months passed
  cin >> N;

  int data_used = 0;
  for (int i = 0; i < N; i++) {
    int use;
    cin >> use;
    data_used += use;
    cerr << "use: " << use << ", total_use: " << data_used << endl;
  }

  // total data for n+1 months minus the data used in the first n months
  cout << (X*(N+1)) - data_used << endl;
}
