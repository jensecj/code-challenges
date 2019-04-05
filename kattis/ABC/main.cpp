/*
  tags: math

  task: given three integers, and an ordering, print them in the correct order.

  url: https://open.kattis.com/problems/ABC
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;

  string order;
  cin >> order;

  map<char, int> m;
  m['A'] = min({x, y, z});
  m['C'] = max({x, y, z});

  m['B'] = x + y + z - m['A'] - m['C'];

  cout << m[order[0]] << " " << m[order[1]] << " " << m[order[2]] << endl;
}
