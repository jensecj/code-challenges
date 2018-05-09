/*
  tags: math
  task: you have three trucks, and a schedule of when they were parked at
  a rest stop. the rest stop uses pricing based on how many trucks you
  have parked at one time, it costs A per trucks if only 1 is parked, B if 2, C
  if 3. given the values for A, B, and C, and the schedule of parking,
  determine what the total cost of parkins is.
*/
#include <iostream>

using namespace std;

int main() {
  int A,B,C; // price for 1,2, or 3 parked trucks
  cin >> A >> B >> C;
  // cerr << A << "," << B << "," << C << endl;

  int times[6];
  for(int i = 0; i < 6; i++)
    cin >> times[i];

  int cost = 0;
  for(int i = 0; i <= 100; i++) {
    int trucks = 0;

    if(i >= times[0] && i < times[1])
      trucks++;

    if(i >= times[2] && i < times[3])
      trucks++;

    if(i >= times[4] && i < times[5])
      trucks++;

    // if(trucks > 0)
    // cerr << "time " << i << ": " << trucks << endl;

    if(trucks == 1) cost += A * trucks;
    if(trucks == 2) cost += B * trucks;
    if(trucks == 3) cost += C * trucks;
  }

  cout << cost << endl;
}
