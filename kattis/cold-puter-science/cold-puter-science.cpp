/*
  tags: introduction
  task: given a sequence of numbers, count how many of them are
  negative
*/
#include <iostream>

using namespace std;

int main() {
  int n; // days with recorded temperatures
  cin >> n;

  int days_with_below_zero_degrees = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    if(temp < 0)
      days_with_below_zero_degrees++;
  }

  cout << days_with_below_zero_degrees << endl;
}
