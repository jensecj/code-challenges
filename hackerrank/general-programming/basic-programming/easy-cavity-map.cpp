/*
  tags: 2d arrays
  task: given a 2d matrix, find the cavities (a cell is a cavity if it
  is not on the edge of the matrix, and it is deeper than all
  neighbours (left, above, right, below, and it is deeper if it has a
  greater value))
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<int> neighbours(vector<vector<int>>& map, int x, int y) {
  vector<int> ns;
  ns.push_back(map[x-1][y]);
  ns.push_back(map[x][y-1]);
  ns.push_back(map[x+1][y]);
  ns.push_back(map[x][y+1]);
  return ns;
}

int main() {
  int n; // size of map
  cin >> n;

  vector<string> dumb_map(n);
  for (int i = 0; i < n; i++)
    cin >> dumb_map[i];

  vector<vector<int>> map(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      map[i][j] = dumb_map[i].at(j) - '0'; // hack to convert from char to int

  int c = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      c++;
      cerr << map[i][j];

      if(c >= n) {
        c = 0;
        cerr << endl;
      }
    }

  cerr << endl;

  vector<pair<int,int>> cavities;

  for (int i = 1; i < n-1; i++) {
    for (int j = 1; j < n-1; j++) {
      bool add = true;
      for(auto& n : neighbours(map, i, j)) {
        if(map[i][j] <= n) {
          add = false;
        }
      }
      if(add) {
        cerr << "new cavity at " << i << "," << j << " - value: " << map[i][j] << endl;
        cavities.push_back(make_pair(i,j));
      }
    }
  }

  for(auto& c : cavities) {
    cerr << c.first << "," << c.second << endl;
    map[c.first][c.second] = -1;
  }

  c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c++;
      if(map[i][j] == -1)
        cout << "X";
      else
        cout << map[i][j];

      if(c >= n) {
        cout << endl;
        c = 0;
      }
    }
  }
}
