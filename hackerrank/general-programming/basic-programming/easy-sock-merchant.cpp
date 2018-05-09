/*
  tags: hashmap
  task: given a number of socks, and a stream of socks of a certain
  color, how many socks can we sell if we can only sell them in pairs?
*/
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
  int n; // the number of socks
  cin >> n;

  unordered_map<int,int> socks;
  while(n--) {
    int sock;
    cin >> sock;
    socks[sock]++;
  }

  int pairs = 0;
  for(auto& kvp : socks) {
    pairs += kvp.second/2;
  }

  cout << pairs << endl;
}
