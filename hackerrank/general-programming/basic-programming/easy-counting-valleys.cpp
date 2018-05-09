/*
  tags: loop
  task: count how many valleys are in an array of up/down movements, a
  valley is when you went below sealevel (1 down from the initial
  position), and came back up to sealevel.
*/
#include <iostream>

using namespace std;

int main() {
  int n; // the number of steps in garys last hike
  cin >> n;

  int valleys = 0;
  int elevation = 0;
  while(n--) {
    char dir;
    cin >> dir;

    // if we get 'back' to elevation 0 after adding 1, we just got
    // back from a valley
    if(dir == 'U') {
      elevation++;
      if(elevation == 0) {
        valleys++;
      }
    } else if (dir == 'D') {
      elevation--;
    }
  }

  cout << valleys << endl;
}
