/*
  tags: loops, arrays
  task: we play a card game where we have three types of cards, T, C,
  and G. a player gets score based on which cards he has played during
  the game. for each set of all three different cards she has played
  she gets +7 points. and for each type card she has at the end of the
  game, she gets <number of that type of card>^2 points. (e.g. she has
  played 3 T's, 2 C's and 1 G, so she gets 3^2 + 2^2 + 1^2 + 7 points)
  figure out the number of points the input play has.
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
  int cards[3]{0};

  string in;
  cin >> in;

  for(auto& c : in) {
    switch (c) {
    case 'T':
      cards[0]++;
      break;
    case 'C':
      cards[1]++;
      break;
    case 'G':
      cards[2]++;
      break;
    }
  }

  cerr << "T: " << cards[0] << ", C: " << cards[1] << ", G: " << cards[2] << endl;

  int points = pow(cards[0], 2) + pow(cards[1], 2) + pow(cards[2], 2);

  // add the extra points if we have atleast one of each
  while(cards[0]-- && cards[1]-- && cards[2]--) {
    points += 7;
  }

  cout << points << endl;
}
