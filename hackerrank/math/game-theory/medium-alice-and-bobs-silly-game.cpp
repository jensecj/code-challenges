/*
  tags: game theory, taking turns, primes
  task: alice and bob plays a game. the game begins with being given a
  number n. the numbers in the game are then 0 <= x <= n. alice always
  starts. at each players turn, they pick a prime number p, and remove
  all multiples of that number in the game, the player who can no
  longer make a move loses, given the number of the game, figure out
  who wins.
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  int g; // number of games played
  cin >> g;

  const int n = 100000;

  // prime sieve for all numbers below the threshold of n
  bool primes[n];
  fill(begin(primes), end(primes), true);

  for(int i = 2; i*i <= n; i++)
    if(primes[i])
      for(int j = i*2; j <= n; j += i)
        primes[j] = false;

  while(g--) {
    int i; // number of integers in the game
    cin >> i;

    // since alice always starts, if there are an uneven number of
    // primes below the number given in the game to be removed, alice
    // will win, if there are an even number of primes, bob wins.
    int primes_below_i = 0;
    for(int p = 2; p <= i; p++)
      if(primes[p])
        primes_below_i++;

    if(primes_below_i % 2 == 0)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
}
