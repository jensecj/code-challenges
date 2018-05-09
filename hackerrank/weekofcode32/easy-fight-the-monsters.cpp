#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

int main() {
  long long n, hit, t;
  cin >> n >> hit >> t;
  // cerr << n << "," << hit << "," << t << endl;

  unsigned long long total_dmg = t*hit;
  // cerr << "TD: " << total_dmg << endl;

  vector<unsigned long long> mons(n);
  for(unsigned long long i = 0; i < mons.size() ; i++) {
    cin >> mons[i];
    if(mons[i] > total_dmg)
      mons.erase(mons.begin()+i--);
  }

  // cerr << "mons.size: " << mons.size() << endl;
  // for(int i = 0; i < mons.size(); i++) {
  //   cerr << mons[i] << ",";
  // } cerr << endl;

  sort(mons.begin(), mons.end());

  unordered_map<int,int> map;
  long max_idx = 0;
  for(int i = 0; i < mons.size(); i++) {
    long idx = ceil(mons[i]/(double)hit);
    if(idx > max_idx) max_idx = idx;
    map[idx]++;
  }

  // for(auto& kv : map) {
  //   cerr << kv.first << " -> " << kv.second << endl;
  // }

  long kills = 0;
  long time = 1;

  while(t > 0 && time <= max_idx) {
    for(int i = 0; i < map[time]; i++) {
      if(t > 0 && ((t-time) >= 0) && map[time]) {
        cerr << "new kill! " << t << " - " << time << endl;
        kills++;
        t -= time;
      }
    }
    time++;
  }

  cerr << "ANSWER: ";
  cout << kills << endl;

  // unsigned long long sum = 0;
  // unsigned long long killed = 0;
  // for(unsigned long long i = 0; i < n; i++) {
  //   if(sum + mons[i] > total_dmg)
  //     break;

  //   sum += mons[i];
  //   killed++;
  // }
  // cout << killed << endl;

  // cout << knapsack(total_dmg, mons) << endl;

}
