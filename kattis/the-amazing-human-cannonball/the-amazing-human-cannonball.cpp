/*
  tags: math, trigonometry
  task: you want to shoot a person out of a cannot and through a hole
  in a wall, given the position of the cannon, initial velocity,
  distance to the wall, angle of cannon, gravity, the height of the
  beginning of the hole from the ground, and the distance from the
  roof to the beginning of the hole, calculate whether it is safe to
  shoot a man out of the cannon.
*/
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 4.0*atan2(1.0,1.0);
const double g = 9.81;

double deg2rad(double d) {
  return d * PI / 180.0;
}

int main() {
  int N; // number of testcases
  cin >> N;

  while(N--) {
    double v0, theta, x1, h1, h2; // parameters
    cin >> v0 >> theta >> x1 >> h1 >> h2;
    cerr << "   v0: " << v0 // initial velocity
         << ", theta: " << theta // angle shot at
         << ", x1: " << x1 // distance to wall
         << ", h1: " << h1 // hight of lower part
         << ", h2: " << h2 << endl; // height of upper part (from ceiling)

    theta = deg2rad(theta);

    // just rearrange the formula we got from the problem to get the time
    double time = x1 / (v0 * cos(theta));
    double y = (v0 * time * sin(theta)) - (0.5 * g * pow(time,2));

    cerr << "   y: " << y << endl;

    if(y > h1+1 && y < h2-1)
      cout << "Safe" << endl;
    else
      cout << "Not Safe" << endl;
  }
}
