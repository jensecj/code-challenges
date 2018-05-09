#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;
int main() {
  int lines, chars;
  cin >> lines >> chars;

  vector<int> vs;

  for(int i = 0; i < lines; i++) {
    int v = 0;

    for(int j = 0; j < chars; j++) {
      char c;
      cin >> c;
      if(c == '1') {
        v |= (1 << (chars-j-1));
      }
    }
    // cout << bitset<5>(v) << endl;

    vs.push_back(v);
  }

  int best = 0;
  int best_sim = 1000;

  for(int i = 0; i < (1 << chars); i++) {
    int sim = 0;
    for(auto v : vs) {
      bitset<20> b(~(i ^ v));
      // cout << v << endl;
      sim = max(sim, (int)b.count());
      if(sim > best_sim)
        break;
    }
    if(sim < best_sim) {
      best_sim = sim;
      best = i;
    }
  }

  bitset<20> dbest(best);
  stringstream ss;
  ss << dbest;
  string s = ss.str();
  s = s.substr(s.length() - chars, chars);
  cout << s << endl;
}
