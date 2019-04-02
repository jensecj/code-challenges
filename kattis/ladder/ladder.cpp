/*
  tags: math
  task: given the height of a roof, and the angle the ladder needs to
  be from the ground, calculate the height the ladder needs to be to
  reach the roof
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int h,v; // height of root, and angle ladder needs to be at
  cin >> h >> v;

  double PI = 4.0*atan2(1.0,1.0);

  // trig
  cout << ceil(h / sin(PI*v/180.0)) << endl;
}
