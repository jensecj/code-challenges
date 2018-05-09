/*
  tags: simple
  task: given a point in the plane, and some queries (points), tell
  whether the points are northeast,..., etc of the cross that the
  point excrudes in all directions (in the directions of the axis), or
  whether the points land on the axis.
*/
#include <iostream>

using namespace std;

int main() {
  int K; // number of queries

  while(cin >> K && K != 0) {

    int N, M; // coordinates for division point
    cin >> N >> M;

    for(int i = 0; i < K; i++) {
      int x, y;
      cin >> x >> y;

      if(x < N && y > M) cout << "NO" << endl;
      else if (x > N && y > M) cout << "NE" << endl;
      else if (x > N && y < M) cout << "SE" << endl;
      else if (x < N && y < M) cout << "SO" << endl;
      else cout << "divisia" << endl;
    }
  }
}
