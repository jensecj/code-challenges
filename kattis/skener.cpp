/*
  tags: 2darray, loops
  task: given a 2darray, zoom in on it given some zoom-numbers. e.g.
  (2,1), means that each character in the original map, becomes a 2*1
  matrix in the new map. (of the same character)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int R,C,ZR,ZC; // column/rows in article, and of the new scanner output
  cin >> R >> C >> ZR >> ZC;

  vector<vector<char>> map(R, vector<char>(C));

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> map[i][j];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cerr << map[i][j];
    }
    cerr << endl;
  }

  cerr << "=====" << endl;

  vector<vector<char>> zoomedmap(R*ZR, vector<char>(C*ZC));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {

      // each point here becomes a ZR*ZC matrix in the zoomed version,
      // this will be the initial coordinates for the new matrices we
      // create for each point in the original
      int zx = i*ZR;
      int zy = j*ZC;

      // create the new matrices
      for (int x = 0; x < ZR; x++) {
        for (int y = 0; y < ZC; y++) {
          zoomedmap[zx+x][zy+y] = map[i][j];
        }
      }
    }
  }

  for (int i = 0; i < zoomedmap.size(); i++) {
    for (int j = 0; j < zoomedmap[0].size(); j++) {
      cout << zoomedmap[i][j];
    }
    cout << endl;
  }
}
