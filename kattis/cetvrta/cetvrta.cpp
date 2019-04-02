/*
  tags: math
  task: given three coordinates for a square, find the forth
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<int,int> xs;
  unordered_map<int,int> ys;

  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    xs[x]++;
    ys[y]++;
  }

  for(auto& i : xs) {
    if(i.second % 2 != 0)
      cout << i.first;
  }

  cout << " ";

  for(auto& i : ys) {
    if(i.second % 2 != 0)
      cout << i.first;
  }

  cout << endl;
}
