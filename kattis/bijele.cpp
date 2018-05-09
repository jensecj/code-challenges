/*
  tags: hashmap
  task: knowing that you should start with some number of pieces (a:1,
  b:1, c:2, d:2, e:2, f:8), and given in input of 6 integers
  (representing how many of a,..,f you start with), print how many of
  each you should add or remove
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<int,int> map;
  map[0] = 1;
  map[1] = 1;
  map[2] = 2;
  map[3] = 2;
  map[4] = 2;
  map[5] = 8;

  for (int i = 0; i < 6; i++) {
    int in;
    cin >> in;

    cout << map[i] - in << " ";
  }

  cout << endl;
}
