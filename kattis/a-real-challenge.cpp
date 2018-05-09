/*
  tags: math
  task: given the area of a squre, find the length of its perimeter
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  long long area; // area of farm
  cin >> area;

  cout << fixed << setprecision(8) << (sqrt(area))*4 << endl;
}
