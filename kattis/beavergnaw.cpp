/*
  tags: math
  task: a beaver wants to gnaw a specific volume out of a cylindrical
  tree, how thick should the remaining cylinder be where he chewed off
  wood, so he gets his fill?
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main() {
  int D; // diabeter of the cylinder that is the tree

  while(cin >> D && D != 0) {
    int V; // volume the beaver wants to chomp
    cin >> V;

    double d = pow(D, 3) - 6*V/PI;
    d = pow(d, 1/3.0);

    cout << fixed << setprecision(8) << d << endl;
  }
}
