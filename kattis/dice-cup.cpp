/*
  tags: probability
  task: given two dies with N and M sides respectively, what is the
  sum that you are most probable to roll? if there are several, list
  them all.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  int N,M; // number of sides on the two dies
  cin >> N >> M;

  unordered_map<int,int> map;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      map[i+j]++;

  for(auto& kv : map) {
    cerr << "there are " << kv.second << " ways to get " << kv.first << endl;
  }

  int max = 0;
  vector<int> eyes(1);
  for(auto& kv : map) {
    if(kv.second > max) {
      max = kv.second;
      eyes.clear();
      eyes.push_back(kv.first);
    } else if (kv.second == max) {
      eyes.push_back(kv.first);
    }
  }

  sort(eyes.begin(), eyes.end());

  for(const int& i : eyes) {
    cout << i << endl;
  }
}
