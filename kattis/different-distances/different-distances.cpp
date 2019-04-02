/*
  tags: math, distance
  task: given x1,x2,y1,y2, and p. calculate the p-norm distance from x
  to y.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pnorm_dist(double x1, double x2, double y1, double y2, double p) {
  return pow((pow(abs(x1-x2), p) + pow(abs(y1-y2), p)), (1/p));
}

int main() {
  double x1, y1, x2, y2, p;
  while(cin >> x1 >> y1 >> x2 >> y2 >> p) {
    cerr << x1 << "," << x1 << "," << y1 << "," << y2 << "," << p << endl;
    cout << fixed << setprecision(10) << pnorm_dist(x1, x2, y1, y2, p) << endl;
  }
}
