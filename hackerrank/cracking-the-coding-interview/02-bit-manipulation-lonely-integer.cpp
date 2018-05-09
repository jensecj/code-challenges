/*
  tags: lonely integer, twin pairs, find distinct
  task: given an array where all but 1 number comes in twin-pairs,
  find the one lonely integer
*/
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> a[i];
  }

  // if we, for each integer, look through the list to check if it has
  // a twin, we get O(n^2).
  // if we remove its twin if we find it, we can get O(n!)

  // using a hashmap, we can do it in linear time
  map<int, int> m;

  for(int i = 0; i < n; i++) {
    m[a[i]]++;
  }

  for(pair<const int,int>& x : m) {
    if(x.second == 1)
      cout << x.first;
  }
}
