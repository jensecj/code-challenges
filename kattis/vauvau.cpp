/*
  tags: modulo
  task: two dogs have different 'schedules' of being aggressive, and
  passive. dog 1 starts with being aggressive for A minutes, then is
  passive for B minutes. dog 2 starts with being aggressive for C
  minutes, then is passive for D minutes. given the arrival times of
  the postman, mailman, and gardener, figure out which dogs, if any,
  are aggressive.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
  int times[4];
  cin >> times[0] >> times[1] >> times[2] >> times[3];
  int pmg[3];
  cin >> pmg[0] >> pmg[1] >> pmg[2];

  string answers[3] { "none", "one", "both" };

  // the idea is that we need to calculate the times versus two
  // modulos, one for each dog, to check if the arrival time is within
  // the timespan where the dog is aggressive.
  for(int i = 0; i < 3; i++) {
    int dogs = 0;

    for (int j = 0; j < 4; j += 2) {
      int time = pmg[i] % (times[j] + times[j + 1]);
      dogs += time > 0 && time <= times[j] ? 1 : 0;
    }

    cout << answers[dogs] << endl;
  }
}
