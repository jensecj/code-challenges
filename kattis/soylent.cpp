/*
  tags: math
  task: given that a bottle of soylent is 400 calories, how many do
  you need to drink to meet your daily calorie goal? (once you start a
  bottle, you have to drink it all), input is the calorie goal you're
  trying to hit
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int calories;
    cin >> calories;

    cout << ceil(calories / 400.0) << endl;
  }
}
