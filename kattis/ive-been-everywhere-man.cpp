/*
  tags: hashset
  task: given a list of cities that alice has been to for work, find
  out which different cities she has been to
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int n; // trips
    cin >> n;

    unordered_set<string> cities;

    for (int i = 0; i < n; i++) {
      string city;
      cin >> city;
      cities.insert(city);
    }

    cout << cities.size() << endl;
  }
}
