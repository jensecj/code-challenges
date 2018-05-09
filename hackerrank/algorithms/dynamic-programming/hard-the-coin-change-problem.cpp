/*
  tags: dp, dynamic programming, coin change
  task: the classic coin change problem
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long make_change_dp_iterative(long dollars, vector<long>& coins, unordered_map<long,long>& cache) {
  for(long i = 0; i < coins.size(); i++) {
    for(long j = coins[i]; j <= dollars; j++) {
      cache[j] += cache[j - coins[i]];
    }
  }

  return cache[dollars];
}

int main() {
  long n; // the dollar value we need to count change for
  long m; // the number of coins we get to play with
  cin >> n >> m;

  vector<long> coins(m);
  for(int i = 0; i < m; i++) {
    cin >> coins[i];
  }

  // our dynamic programming cache
  unordered_map<long,long> cache;

  // we can make change for 0 dollars in 1 way, by giving nothing
  cache[0] = 1;

  cout << make_change_dp_iterative(n, coins, cache) << endl;
}
