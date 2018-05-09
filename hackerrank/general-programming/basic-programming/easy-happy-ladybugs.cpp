/*
  tags: hashmap
  task: given a board of ladybugs with colors (a board is an array of
  length n), can you mvoe ladybugs around to make them all happy? a
  ladybug is happy if it is next to another ladybug of the same color,
  and you may only move ladybugs to cells denoted by '_' (which means
  empty, when you move the lady bug, the cell it was in becomes empty)
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  int g; // the number of games to play
  cin >> g;

  // the solution is in linear time with regards to the input, we run
  // over the input once to determine if it is unhappy initially, and
  // store the frequencies of each ladybug with color c, then we run
  // over all the different colors of ladybugs to check the
  // frequencies. (ladybugs can be any of 26 colors)
  while(g--) {
    int n; // number of cells on board (length of board)
    cin >> n;
    string b; // the string describing the cells of the board
    cin >> b;

    // save the board state in a freq-map, this way we can check if
    // there are any colors that are only 1 of
    unordered_map<char,int> map;
    for(auto& c : b)
      map[c]++;

    // check if the initial string has unhappiness
    int unhappies = 0;
    for (int i = 1; i < n-1; i++) {
      if(b.at(i) != b.at(i-1) && b.at(i) != b.at(i+1))
        unhappies++;
    }

    // check the first and last indices as well
    if(b.size() > 1) {
      if(b.at(0) != b.at(1))
        unhappies++;
      if(b.at(b.size()-1) != b.at(b.size()-2))
        unhappies++;
    }

    // check if there are any colors that are only 1 off, if that is
    // the case, there is no way to make that ladybug happy
    bool fine = true;
    for(auto& kv : map) {
      if(kv.first != '_' && kv.second == 1)
        fine = false;
    }

    // if there are no lonely ladybugs
    if(fine) {
      // if there are misplaces ladybugs, and no slot to move them
      // around, there is no way to make this a happy board
      if(unhappies > 0 && !map['_'])
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else cout << "NO" << endl;
  }
}
