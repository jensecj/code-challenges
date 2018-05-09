/*
  tags: dp, dynamic programming, coin change, greedy
  task: an intern at a company has given out some cookies to the other
  interns, but she has not given everyone the same amount! her
  supervisor tells her that this is no good, and to make sure that all
  the other interns all have an equal number of cookies, she is
  allowed to do one of three things:
  1) select an intern, and give all other interns one more cookie
  2) -------||-------, and give all other interne two more cookies
  3) -------||-------, and give all other interns 5 more cookies
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// we can look at this problem as an isomorph of the coin change
// problem. each action we are allowed to do, we can also look at as
// taking 1,2, or 5 cookies away from the selected intern, and we do
// this until all interns have an equal number of cookies. the coin
// change part comes in when we notice that the max number of 'moves'
// we have to make, is to get the person with the smallest number of
// cookies, to have the same number of cookies as the person with the
// highest number of cookies (almost, more on this later). so what we
// have to do is, using either moves of 1,2, or 5, make up the gap
// between the two people with the biggest bap. (this parallels to
// coin change in making up for some dollar amount with coins of
// either value 1,2, or 5!)
// now, this is almost the answer, we need to account for some edge
// cases when making up for this gap not necessarily gives us the
// optimal solution, e.g. when giving the person with the most
// cookies even more cookies, and this allows us to use fewer moves
// because other moves become shorter (like being able to use a +5,
// instead of several +1/+2 moves)
// we handle this by looking for the minimum number of operations to
// close a gap of size n, n+1, n+2., the n+1 and n+2 cases handle the
// cases where, if we instead increase the number of cookies, can make
// a better move (use a +5 instead), we do not have to check higher
// numbers, because +3 and +4 are not possible moves, and if we use +5
// it is a move we could find anyway, and doing it now would be more
// expensive. this is a greedy solution to a dp problem, we dont need
// to memoize (although we could just remember the best solutions for
// a gap of size n, but it is not necessary with the size of this
// problem).
int min_actions(vector<int>& chocos) {
  sort(chocos.begin(), chocos.end());

  int min_moves = INT_MAX;

  // check cases n, n+1, and n+2
  for(int base = 0; base < 3; base++) {
    int moves = 0;

    // how many moves does it take to get to the intern with the
    // minimum number of cookies? (the vector is sorted, so chocos[0]
    // is the minumum)
    for(int i = 0; i < chocos.size(); i++) {
      int gap = chocos[i] - chocos[0] + base;

      // calculate how many moves it takes, we start with taking moves
      // of length 5, when we can no longer do that, we take moves of
      // 2, then of 1. using modulo here gives us the remaining gap we
      // need to make up for.
      int moves_of_5 = gap / 5;
      int moves_of_2 = (gap % 5) / 2;
      int moves_of_1 = ((gap % 5) % 2) / 1;
      moves += moves_of_5 + moves_of_2 + moves_of_1;
    }
    min_moves = min(min_moves, moves);
  }

  return min_moves;
}

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int N; // number of co-interns
    cin >> N;

    vector<int> chocos(N);
    for(int i = 0; i < N; i++)
      cin >> chocos[i];

    cout << min_actions(chocos) << endl;
  }
}
