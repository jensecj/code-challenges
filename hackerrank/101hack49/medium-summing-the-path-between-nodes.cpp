#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <climits>

using namespace std;

class Graph {
private:
  vector<vector<int>> adjacency_list;

public:
  int vertices;

  Graph(int vertices) : adjacency_list(vertices) {
    this->vertices = vertices;
  }

  void add_edge(int u, int v) {
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  vector<int> neighbours(int node) {
    return adjacency_list[node];
  }
};

int dijkstra(Graph& graph, vector<int>& weights, int source, int target) {
  if(source == target) return 0;
  vector<bool> seen;
  vector<int> min_distance(graph.vertices, INT_MAX);
  min_distance[source] = 0;

  set<int> active_vertices;
  active_vertices.insert(source);

  while (!active_vertices.empty()) {
    int node = *active_vertices.begin();

    if (node == target)
      return min_distance[node];

    active_vertices.erase(active_vertices.begin());

    for (auto nbr : graph.neighbours(node)) {
      int dist_to_nbr = min_distance[node] + weights[nbr];
      if (nbr == target)
        return dist_to_nbr;

      if (min_distance[nbr] > dist_to_nbr) {
        min_distance[nbr] = dist_to_nbr;
        active_vertices.insert(nbr);
      }
    }
  }
  return -1;
}

string str(int x, int y) {
  return to_string(min(x,y)) + "," + to_string(max(x,y));
}

int main() {
  int n; // number of vertices
  cin >> n;

  vector<int> colors(n);
  for(int i = 0; i < n; i++)
    cin >> colors[i];

  Graph graph(100010);
  vector<int> weights(n);
  for(int i = 0; i < n; i++) {
    int x,y,w;
    cin >> x >> y >> w;
    graph.add_edge(x,y);
    weights[i] = w;
  }

  unordered_map<string, bool> seen;

  int sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      string s = str(j,i);
      if(seen[s] || i == j || colors[i] == colors[j]) continue;
      sum += dijkstra(graph, weights, i, j);
      seen[s] = true;
    }
  }

  cout << sum << endl;
}
