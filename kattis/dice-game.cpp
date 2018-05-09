/*
  tags: probability, math
  task: two players are each given two dice, different sides and
  different numbers on them (they can start at an arbitraty number),
  figure out which player a better chance of winning if the winner is
  the player who has the higher sum when playing their dice. print tie
  if they are equal.
*/
#include <iostream>

using namespace std;

struct dice {
  int low;
  int high;
};

int expected_rolls(dice a, dice b) {
  return a.low + a.high + b.low + b.high;
}

int main() {
  dice a,b; // gunnars dice
  cin >> a.low >> a.high >> b.low >> b.high;

  dice c,d; // emmas dice
  cin >> c.low >> c.high >> d.low >> d.high;

  int ab = expected_rolls(a, b);
  int cd = expected_rolls(c, d);

  cerr << ab << " -- " << cd << endl;

  if(ab > cd) cout << "Gunnar" << endl;
  else if (ab < cd) cout << "Emma" << endl;
  else cout << "Tie" << endl;
}
