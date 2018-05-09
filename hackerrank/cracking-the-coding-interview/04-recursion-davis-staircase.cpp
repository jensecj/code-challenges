/*
  tags: davis staircase, climb stairs, dynamic programming, recursion
  task: given a staircase of n stairs, and the knowledge that we can
  take either 1, 2, or 3 steps at a time, calculate how many different
  ways we can reach the top of the staircase
*/
#include <iostream>
#include <map>

using namespace std;

// count the number of ways to climb a staircase of n stairs,
// taking either 1, 2, ..., m steps at a time, using a dynamic
// programming cache
int count_ways(int n, int m, map<int,int>& cache) {
  if(n < 0)
    return 0;

  // use our cache if we have already calculated this step
  if (cache.find(n) != cache.end())
    return cache[n];

  // find out how many ways there are to get to the staircases
  // 1,2,...,m steps below this one, and use that in this calculation
  int ways = 0;
  for(int i = 1; i <= m; i++) {
    ways += count_ways(n-i, m, cache);
  }

  // update our cache so future calculations can use it
  cache[n] = ways;

  return ways;
}

int main() {
  int s;
  cin >> s;

  for(int i = 0; i < s; i++) {
    int n;
    cin >> n;

    // we'll use a dynamic programming approach, because we mainly need
    // to remember how many ways we can climb to some stair i, and work
    // further from there
    map<int,int> ways;

    // there is only 1 way to climb a staircase of 0 or 1 stairs
    ways[0] = 1;
    ways[1] = 1;

    // we need to figure out how many ways we can traverse this n
    // stair staircase, using up to 3 steps at a time
    cout << count_ways(n, 3, ways) << endl;
  }
}
