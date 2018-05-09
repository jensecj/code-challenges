/*
  tags: loops, array
  task: given n cities, where each city is connected by a 1km road
  from the previous to it, and from it to the next (except the first
  and last cities, which only has a single outgoing/incoming road),
  also given that some of these cities have spacestations (?), how far
  if the furthest city from a space station?
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n,m; // the number of cities, and cities with spacestations
  cin >> n >> m;

  vector<int> cities(n);

  for (int i = 0; i < n; i++) {
    int city_with_space_station;
    cin >> city_with_space_station;
    cities[city_with_space_station] = -1;
  }

  for (int i = 0; i < n; i++) {
    cerr << cities[i] << " ";
  }
  cerr << endl;

  // we can figure out the maximum distance from any city to a
  // spacestation in O(2n) = O(n), if we just run through the array of
  // cities from front to back, and then back to front

  int dist = -1;
  for (int i = 0; i < n; i++) {
    // we cannot start counting distance until a spacestation before
    // we have seen the first spacestation, the elements we skip here
    // will be filled by the second loop over the vector
    if(dist == -1 && cities[i] != -1)
      continue;
    // if a city has a spacestation, the distance starts here
    if(cities[i] == -1) {
      dist = 1;
    } else { // increment the distance to the spacestation as we get
             // further away
      cities[i] = dist++;
    }
  }

  for (int i = 0; i < n; i++) {
    cerr << cities[i] << " ";
  }
  cerr << endl;

  dist = -1;
  for (int i = n-1; i >= 0; i--) {
    if(dist == -1 && cities[i] != -1)
      continue;
    if(cities[i] == -1) {
      dist = 1;
    } else if(dist < cities[i] || cities[i] == 0) {
      cities[i] = dist++;
    }
  }

  for (int i = 0; i < n; i++) {
    cerr << cities[i] << " ";
  }
  cerr << endl;

  int max = 0;
  for (int i = 0; i < n; i++) {
    if(cities[i] > max)
      max = cities[i];
  }

  cout << max << endl;
}
