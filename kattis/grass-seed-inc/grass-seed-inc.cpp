/*
  tags: math
  task: given a cost to sow 1 m^2 of lawn, and n lawns of some size,
  calculate the total cost to sow all lawns
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double C; // cost of seed to sow 1 m^2
  cin >> C;

  int L; // number of lawns to sow
  cin >> L;

  double price = 0;

  for (int i = 0; i < L; i++) {
    double w,l; // width and length of lawn
    cin >> w >> l;

    price += w*l*C;
  }

  cout << fixed << setprecision(7) << price << endl;
}
