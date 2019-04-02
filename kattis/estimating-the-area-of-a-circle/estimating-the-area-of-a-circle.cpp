/*
  tags: math, geometry
  task: we can estimate the area of a circle by enclosing it in a
  square, and dropping points randomly inside the square, once we have
  done that for a while, we count the number of points that landed in
  the circle, and the total number of points, if we divide the number
  of points that landed in the circle with the total number, we get an
  idea of how big the circle is compared to the square.
  given the real radius of the circle, and two integers which are out
  test points, calculate the real area of the circle, and the
  estimated area.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main() {
  double r; // true redius of the circle

  while(cin >> r && r != 0) {
    double m,c; // total number of points, and points in the circle
    cin >> m >> c;

    // c/m gives us how big the circle is compared to the square that
    // surrounds it, to get the real number we multiply it with the
    // area of that square
    cout << fixed << setprecision(6) << PI*r*r << " " << (c/m)*(2.0*r*2.0*r) << endl;
  }
}
