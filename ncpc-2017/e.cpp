#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

struct node {
  int x,y;
  bool seen;
  int value;
  int largest_seen;
};

vector<node> neighbours(const vector<vector<node>>& graph, int x, int y) {
  int n = graph.size();
  int m = graph[0].size();

  if(x < 0 || x > n || y < 0 || y > m) {
    cout << "ERROR:" << x << "," << y << " [" << n << "," << m << "]" << endl;
    throw new runtime_error("error: index for node was outside bounds");
  }

  vector<node> neighbours;

  if(x-1 >= 0 && y-1 >= 0)
    neighbours.push_back(graph[x-1][y-1]);
  if(x-1 >= 0)
    neighbours.push_back(graph[x-1][y]);
  if(x-1 >= 0 && y+1 < m)
    neighbours.push_back(graph[x-1][y+1]);

  if(y-1 >= 0)
    neighbours.push_back(graph[x][y-1]);
  if(y+1 < m)
    neighbours.push_back(graph[x][y+1]);

  if(x+1 < n && y-1 >= 0)
    neighbours.push_back(graph[x+1][y-1]);
  if(x+1 < n)
    neighbours.push_back(graph[x+1][y]);
  if(x+1 < n && y+1 < m)
    neighbours.push_back(graph[x+1][y+1]);

  return neighbours;
}

int DFS(vector<vector<node>>& graph, int x, int y) {
  int n = graph.size();
  int m = graph[0].size();

  vector<vector<bool>> seen(n, vector<bool>(m));

  auto comp = [](const node& n1, const node& n2) { return n1.value > n2.value; };
  priority_queue<node, vector<node>, decltype(comp)> Q(comp);

  long drained = 0;

  Q.push(graph[x][y]);

  while(!Q.empty()) {
    node n = Q.top();
    Q.pop();

    if(seen[n.x][n.y] || n.value >= 0)
      continue;

    seen[n.x][n.y] = true;

    if(n.largest_seen > n.value)
      drained += - n.largest_seen;
    else
      drained += -n.value;

    for(node ne : neighbours(graph, n.x, n.y)) {
      if(!seen[ne.x][ne.y] && ne.value < 0) {
        ne.largest_seen = max(n.largest_seen, n.value);
        Q.push(ne);
      }
    }
  }

  return drained;
}

int main() {
  int n; // number of rows in matrix
  int m; // number of columns in matrix;
  cin >> n >> m;

  vector<vector<node>> graph(n, vector<node>(m));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      int value;
      cin >> value;

      node n;
      n.x = i;
      n.y = j;
      n.value = value;
      n.largest_seen = -1000000;
      graph[i][j] = n;
    }

  int x, y; // location of the sink
  cin >> x >> y;

  cout << DFS(graph, x-1, y-1) << endl;
}
