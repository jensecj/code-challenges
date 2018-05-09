/*
  tags: sorting, comparator
  task: create a comparator to sort a vector of players, first by
  score, then alphabetically by name
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
  string name;
  int score;
};

bool player_compare(Player a, Player b) {
  // sort after highest score first
  if(a.score > b.score) return true;
  if(b.score > a.score) return false;
  // sort alphabetically
  if(a.name < b.name) return true;
  if(b.name < a.name) return false;

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<Player> players;

  for(int i = 0; i < n; i++){
    string name;
    int score;
    cin >> name >> score;

    Player p;
    p.name = name, p.score = score;

    players.push_back(p);
  }

  sort(players.begin(), players.end(), player_compare);

  for(int i = 0; i < players.size(); i++) {
    cout << players[i].name << " " << players[i].score << endl;
  }
}
