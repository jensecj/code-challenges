/*
  tags: array, stack
  task: given a leaderboard that uses dense ranking (i.e. people with
  the same score, have the same rank, so if four people have the
  scores 10,20,20,30, their ranks would be 3,2,2,1). and given a
  player alice, who starts at 0, but beats m games, output her rank on
  the leaderboard after each game.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  int n; // number of players on the leaderboard
  cin >> n;

  stack<long> leaderboard;

  while(n--) {
    long score;
    cin >> score;

    // only push a score if it is not a duplicate
    if(leaderboard.empty() || leaderboard.top() != score)
      leaderboard.push(score);
  }

  int m; // the number of games alice beats
  cin >> m;

  for (int i = 0; i < m; i++) {
    long score;
    cin >> score;

    // while there are lower scores in the stack than our score, pop them
    while(!leaderboard.empty() && score >= leaderboard.top())
      leaderboard.pop();

    // the number of scores left on the leaderboard, are the number of
    // players above us, and since we deduplicated it, it + 1 is our rank
    cout << leaderboard.size() + 1 << endl;
  }
}
