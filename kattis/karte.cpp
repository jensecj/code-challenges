/*
  tags: map, set
  task: given a deck of cards, with four suits, P, K, H, and T. you
  know there are 13 of each card, namely 1-13. figure out if the card
  set is complete, if you find duplicate cards, output "GRESKA", which
  is croatian for error
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  unordered_map<char,int> suits;
  suits['P'] = 0;
  suits['H'] = 0;
  suits['K'] = 0;
  suits['T'] = 0;

  unordered_set<string> cards;

  char suit;
  while(cin >> suit) {
    int nr;
    cin >> nr;

    suits[suit]++;

    string card = suit + to_string(nr);

    if (cards.find(card) != cards.end()) {
      cout << "GRESKA" << endl;
      return 0;
    }

    cards.insert(card);
  }

  cout << 13-suits['P'] << " ";
  cout << 13-suits['K'] << " ";
  cout << 13-suits['H'] << " ";
  cout << 13-suits['T'] << endl;

  
}
