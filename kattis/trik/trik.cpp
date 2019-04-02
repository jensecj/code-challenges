/*
  tags: simple puzzle
  task: the cup shuffle game! with a ball starting at the left cup,
  and given that we can move A: 1<->3, B:2<->3, C:1<->3. given a
  string of moves, find the ball
*/
#include <iostream>

using namespace std;

int main() {
  string moves;
  cin >> moves;

  int ball = 1;

  for(auto& c : moves) {
    if(c == 'A') {
      if(ball == 1) ball = 2;
      else if (ball == 2) ball = 1;
    }
    if(c == 'B') {
      if(ball == 2) ball = 3;
      else if(ball == 3) ball = 2;
    }
    if(c == 'C') {
      if(ball == 3) ball = 1;
      else if (ball == 1) ball = 3;
    }
  }

  cout << ball << endl;
}
