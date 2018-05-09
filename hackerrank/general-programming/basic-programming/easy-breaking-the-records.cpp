/*
  tags: highscore
  task: given a stream of games (or, scores of games), keep track of
  how many times we make a new highscore or lowscore
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // the number of birds
  cin >> n;

  vector<int> scores(n);

  for (int i = 0; i < n; i++)
    cin >> scores[i];

  int most = scores[0];
  int breaks_most = 0;
  int least = scores[0];
  int breaks_least = 0;

  cerr << "initial score: " << scores[0] << endl;

  for (int i = 1; i < scores.size(); i++) {
    if(scores[i] > most) {
      cerr << "broke highscore: " << most << " -> " << scores[i] << endl;
      breaks_most++;
      most = scores[i];
    }
    else if (scores[i] < least) {
      cerr << "broke lowscore: " << least << " -> " << scores[i] << endl;
      breaks_least++;
      least = scores[i];
    }
  }

  cout << breaks_most << " " << breaks_least << endl;
}
