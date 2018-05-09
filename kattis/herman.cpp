/*
  tags: math, geometry
  task: given the radius of a circle, print its area in euclidian
  geometry, and minkowski geometry
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main() {
  long long radius;
  cin >> radius;

  long double area = PI*radius*radius;
  cout << fixed << setprecision(6) << area << endl;

  long double minkowski_area = 2*radius*radius;
  cout << fixed << setprecision(6) << minkowski_area << endl;
}
