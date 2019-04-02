/*
  tags: array
  task: given n stores on a line, find where to park on this line to
  minimuze the distance needed to walk to visit all stores.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// the best strategy would be to start at one of the stores, and then
// walk to all the others, since that is the only way to save any
// distance, we can simple start at one end, and walk to all other
// stores in a line, and then walk back.
int main() {
  int t; // number of testcases
  cin >> t;

  while(t--) {
    int stores;
    cin >> stores;

    vector<int> dist(stores);
    for(int i = 0; i < stores; i++)
      cin >> dist[i];

    sort(dist.begin(), dist.end());

    int distance = 0;
    for(int i = dist.size()-1; i >= 1; i--) {
      distance += dist[i] - dist[i-1];
    }

    distance *= 2;

    cout << distance << endl;
  }
}
