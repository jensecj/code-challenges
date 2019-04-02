/*
  tags: modulo
  task: given 8 players in a circle (1,..,8), some player starts with
  a box in front of her, and we know that after 3 minutes and 30
  seconds the box explodes into glitter. the player that has the box
  has to answer a question. given as input, the player who starts with
  the box, and a series of answers, and when they were stated, figure
  out who ended up with the box as it exploded. (and answer can be
  answered correctly, incorrectly, or the player can skip the
  question, and get another)
*/
#include <iostream>

using namespace std;

int main() {
  int start, questions; // the player who starts out with the box, and
                        // the number of questions
  cin >> start >> questions;

  int player = start;
  cerr << "starting player: " << start << endl;

  int time = 0;
  for(int i = 0; i < questions; i++) {
    int t; // the time it took to answer
    cin >> t;
    char type; // the type of anwser (T = true, N = false, P = skipped)
    cin >> type;

    time += t;
    cerr << "time: " << time << " / " << 3*60+30 << endl;

    if(time >= 3*60+30)
      break;

    if(type == 'T') {
      cerr << "player " << player << " answered correctly!" << endl;

      player = ((player + 1) % 9);
      if (player == 0)
        player = 1;

      cerr << "new player: " << player << endl;
    }
  }

  cout << player << endl;
}
