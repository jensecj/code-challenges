/*
  tags: simple
  task: a clown starts in front of N monsters, and he has to out run
  them, given the speeds of the monsters, how fast does the clown have
  to run to always be in front of the monsters?
*/
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  for(int i = 1; i <= T; i++) {
    int monsters;
    cin >> monsters;

    int max = 0;

    for(int j = 0; j < monsters; j++) {
      int speed;
      cin >> speed;

      if(speed > max)
        max = speed;
    }

    cout << "Case " << i << ": " << max << endl;
  }
}
