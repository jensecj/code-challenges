/*
  tags: dynamic programming, recursion, coin change
  task: given a dollar amount and m different coins (in infinite
  quantity), each worth some amount, calculate how many different ways
  there is to make change for the dollar amount.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// a straight recursive approach, O(2^n)
int make_change_recursive(int dollars, vector<int>& coins, int index) {
  // base cases, having a negative amount to give change back for is
  // nonsense, and there is only 1 way to give change for nothing,
  // which is giving back nothing
  if (dollars < 0) return 0;
  if (dollars == 0) return 1;

  // if we have tried all coins, and we still have some remaining
  // amount to give change for, then there is no solution
  if(index == coins.size() && dollars > 0) return 0;

  // recursive step, the first being if we use the coin at index, and
  // continue, the second is if we choose not to use it. this is the
  // two choices we have to make, which makes the runtime O(2^n), for
  // n coins
  return make_change_recursive(dollars - coins[index], coins, index) +
    make_change_recursive(dollars, coins, index + 1);
}

int make_change_dp_recursive(int dollars, vector<int>& coins, int index, vector<vector<long>>& cache) {
  // use our cache
  if(cache[dollars][index] != 0)
    return cache[dollars][index];

  // base cases
  if (dollars == 0)
    return 1;

  // if this is the last coin we check, see if we can use it to make
  // change for the remaining dollar amount
  if (index == coins.size()-1) {
    if (dollars % coins[index] == 0) {
      cache[dollars][index] = 1;
      return 1;
    } else {
      cache[dollars][index] = 0;
      return 0;
    }
  }

  // recursive case, reduce the dollar amount we need to make change
  // for, and try with the next coin
  long ways = 0;
  for(int i = 0; i <= dollars; i += coins[index]) {
    ways += make_change_dp_recursive(dollars-i, coins, index+1, cache);
  }

  cache[dollars][index] = ways;
  return ways;
}

int make_change_dp_iterative(int dollars, vector<int>& coins, unordered_map<int,long>& cache) {
  for(int i = 0; i < coins.size(); i++) {
    for(int j = coins[i]; j <= dollars; j++) {
      cache[j] += cache[j - coins[i]];
    }
  }

  return cache[dollars];
}

// the main insight here is that the problem has optimal substructure,
// e.g. each subproblem has an optimal solution, which we can combine
// to get an optimal solution for the bigger problem.
// if we say, have 50 dollars, and coins worth 20,10,5,1, we can look
// at the different ways of making change as first the way to make
// change with no 20s, and just using the rest, then the way of making
// change with one 20, and mixing the rest. and we use this approach
// for all the coins, recursively, starting from the bottom and
// working up.
int main() {
  int n; // the dollar value we need to count change for
  int m; // the number of coins we get to play with
  cin >> n >> m;

  vector<int> coins(m);
  for(int i = 0; i < m; i++) {
    cin >> coins[i];
  }

  // our dynamic programming cache
  unordered_map<int,long> cache;

  cache.clear();
  // we can make change for 0 dollars in 1 way, by giving nothing
  cache[0] = 1;
  cout << make_change_recursive(n, coins, 0) << endl;

  vector<vector<long>> two_d_cache(n+1, vector<long>(m));
  cout << make_change_dp_recursive(n, coins, 0, two_d_cache) << endl;

  cache.clear();
  cache[0] = 1;
  cout << make_change_dp_iterative(n, coins, cache) << endl;
}
