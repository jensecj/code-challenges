/*
  tags: math, percentages
  task: given a pizza of radius R, which has a crust of radius C, and
  we know that there is no cheese on this crust, how big of a
  percentage of the pizza has cheese?
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main() {
  int R, C; // radius of pizza, and outer most cheeseless cm of pizza
  cin >> R >> C;

  double pizza_area = PI*R*R;
  double crust_area = pizza_area - (PI*(R-C)*(R-C));

  cout << fixed << setprecision(8) << (1-(crust_area / pizza_area))*100 << endl;
}
