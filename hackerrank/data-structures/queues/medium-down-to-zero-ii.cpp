/*
  tags: queues, memoization
  task: given a number, fogure out how mny steps it takes to get to
  zero if you can perform one of two commands at each step:
  1) subtract 1 from the number
  2) if the number is on the form n = a*b, you may change the number
  to max(a,b)
  note: this looks a lot more like a dynamic programming problem, than
  a queue problem.
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// returns the 'neighbours' of a number, to be used in bfs search,
// here we make use of a cache to only add neighbours we dont know the
// distances of
vector<int> next(int n, unordered_map<int,int>& cache) {
  vector<int> nexts;

  // add n-1
  if(cache.find(n-1) == cache.end()) {
    nexts.push_back(n-1);
    cache[n-1] = cache[n] + 1;
  }
  // for all posible 2-number factorizations of this number, add the
  // largest of the two
  for (int i = 2; i <= (int)sqrt(n); i++) {
    if(n % i == 0) {
      if(cache.find(n/i) == cache.end()) {
        nexts.push_back(n/i);
        cache[n/i] = cache[n] + 1;
      }
    }
  }

  return nexts;
}

// using a bfs approach to search through 'nodes', until we reach zero
int search(int n) {
  unordered_map<int,int> cache;
  unordered_map<int,bool> seen;
  queue<int> queue;
  queue.push(n);
  cache[n] = 0;

  while(!queue.empty()) {
    int i = queue.front();
    queue.pop();

    seen[i] = true;

    // update the distance to this node, only if this distance is
    // shorter, if a distance already existed in the cache, that
    // distance would have been added earlier, and would be shorter
    // than how we got to it here
    if(cache.find(i) == cache.end()) {
      cache[i] = cache[n] + 1;
    }

    // cerr << "at: " << i << " (" << cache[i] << ")" << endl;

    if(i == 0) {
      // cerr << "found the goal!" << endl;
      return cache[i]; // do not count the initial node
    }

    for(const int& n : next(i, cache)) {
      if(!seen[n]) {
        // cerr << " -> " << n << endl;
        queue.push(n);
      }
    }
  }

  return -1;
}

int main() {
  int Q; // number of queries
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int N;
    cin >> N;

    cout << search(N) << endl;
  }
}
