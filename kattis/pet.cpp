/*
  tags: intro
  task: on a foodie show, five contestants cook for each other, while
  the others rate their meal, the winner is the person who gets the
  highest total score, find the winner
*/
#include <iostream>

using namespace std;

int main() {
  int winner = -1;
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    int score;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    score = a+b+c+d;

    if(score > sum) {
      sum = score;
      winner = i;
    }
  }

  cout << winner+1 << " " << sum << endl;
}
