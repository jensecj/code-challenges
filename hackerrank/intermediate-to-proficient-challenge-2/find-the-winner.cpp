#include <iostream>
#include <vector>
#include <string>

using namespace std;

int points(vector<int>& player, int index) {
  return 0;
}

// return the winner of the game, 'Andrea', 'Maria', or 'Tie' in case of a tie
string winner(vector<int> andrea, vector <int> maria, string s) {
  int size = andrea.size();

  int start = 0;
  if(s == "Odd")
    start = 1;

  int andrea_pts = 0;
  int maria_pts = 0;
  for(int i = start; i < size; i += 2) {
    andrea_pts += andrea[i] - maria[i];
    maria_pts += maria[i] - andrea[i];
  }

  if(andrea_pts > maria_pts) return "Andrea";
  else if (maria_pts > andrea_pts) return "Maria";
  else return "Tie";
}


int main() {
  int n; // number of ints in andreas array
  cin >> n;
  vector<int> andrea(n);
  for (int i = 0; i < n; i++) {
    cin >> andrea[i];
  }

  int m; // number of ints in maria array
  cin >> m;
  vector<int> maria(n);
  for (int i = 0; i < n; i++) {
    cin >> maria[i];
  }

  string game; // the type of game, Even or Odd
  cin >> game;

  cout << winner(andrea, maria, game) << endl;
}
