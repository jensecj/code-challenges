/*
  tags:
  task:
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
  int R, S, K; // dimensions of the grid, and the side length of the
               // racket (which is K*K)
  cin >> R >> S >> K;
  cerr << "R: " << R << ", S: " << S << ", K: " << K << endl;

  // read the graph
  vector<vector<char>> graph(R, vector<char>(S));
  for (int i = 0; i < R; i++)
    for (int j = 0; j < S; j++)
      cin >> graph[i][j];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < S; j++) {
      cout << graph[i][j];

      if(j == S-1)
        cout << endl;
    }
  }

  unordered_map<int, pair<int,int>> seen;
  int max = 0;

  // only look at the parts of the graph where we can fit the racket
  // inside, if we start
  for (int i = 1; i < R-K; i++) {
    for (int j = 1; j < S-K; j++) {

      int sum = 0;

      for (int a = i; a < i+K-1; a++) {
        for (int b = j; b < j+K-1; b++) {
          if(graph[a][b] == '*')
            sum++;

          graph[a][b] = 'o';
        }
      }

      if(seen.find(sum) == seen.end()) {
        if(sum > max) {
          cerr << "new max: " << sum << ", at: " << i << "," << j << endl;
          max = sum;
        }
        seen[sum] = make_pair(i,j);
      }
    }
  }

  pair<int,int> best = seen[max];
  for (int i = 0; i < K-1; i++) {
    graph[i+best.first][best.second] = '|';
    graph[i+best.first][best.second+K-1] = '|';
  }
  for (int i = 0; i < K-1; i++) {
    graph[best.first][i+best.second] = '-';
    graph[best.first+K-1][i+best.second] = '-';
  }

  graph[best.first][best.second] = '+';
  graph[best.first+K-1][best.second] = '+';
  graph[best.first][best.second+K-1] = '+';
  graph[best.first+K-1][best.second+K-1] = '+';

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < S; j++) {
      cout << graph[i][j];

      if(j == S-1)
        cout << endl;
    }
  }
}
