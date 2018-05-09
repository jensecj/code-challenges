/*
  tags: hashmap
  task: given a dominant suit, and scores for cards played based on it
  if is from the dominant suit or not. and given some number of hands
  of 4 cards played, calculate the total score of the game
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int N; // hands played
  cin >> N;

  char dominant_suit;
  cin >> dominant_suit;

  // values of cards based on their dominance
  unordered_map<char, int> dominant;
  unordered_map<char, int> non_dominant;
  dominant['A'] = 11;
  non_dominant['A'] = 11;
  dominant['K'] = 4;
  non_dominant['K'] = 4;
  dominant['Q'] = 3;
  non_dominant['Q'] = 3;
  dominant['J'] = 20;
  non_dominant['J'] = 2;
  dominant['T'] = 10;
  non_dominant['T'] = 10;
  dominant['9'] = 14;
  non_dominant['9'] = 0;
  dominant['8'] = 0;
  non_dominant['8'] = 0;
  dominant['7'] = 0;
  non_dominant['7'] = 0;

  int score = 0;
  for (int i = 0; i < 4*N; i++) {
    string play; // two chars, the played card, and its suit
    cin >> play;

    if(play[1] == dominant_suit) {
      score += dominant[play[0]];
    } else {
      score += non_dominant[play[0]];
    }
  }

  cout << score << endl;

}
