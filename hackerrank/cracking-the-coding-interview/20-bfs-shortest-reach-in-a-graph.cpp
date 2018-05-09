/*
  tags: search, graph, bfs, breadth first search, shortest reach,
  adjacency list
  task: given a graph (adjacency list), find the shortest reach from a
  source node, to all other reachable nodes
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// a graph class using an adjacency list internally to keep track of
// connecting nodes
class Graph {
private:
  vector<vector<int>> adjacency_list;

public:
  int vertices;

  Graph(int vertices) : adjacency_list(vertices) { this->vertices = vertices; }

  void add_edge(int u, int v) {
    // add edge connections in both directions
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  vector<int> neighbours(int node) { return adjacency_list[node]; }
};

// uses a BFS approach to searching through nodes (layer-wise).
// runtime complexity is O(|V| * |E|), since we we go through all
// edges of all nodes. since we're using an adjacency list space
// complexity is also O(|V| * |E|), since we're storing all edges of
// all nodes. (e.g time and space are O(n)/linear, since our inputs
// are the vertices + edges)
vector<int> shortest_reach(Graph &graph, int source) {
  vector<int> distances(graph.vertices, -1);

  queue<int> queue;
  queue.push(source);

  distances[source] = 0;

  while (!queue.empty()) {
    const int c = queue.front();
    queue.pop();

    for (const int n : graph.neighbours(c)) {
      // if we have not visited this node yet, the distance is not set
      // cout << "found new node: " << n << endl;
      if (distances[n] == -1) {

        // each edge costs 6
        distances[n] = distances[c] + 6;
        queue.push(n);
      }
    }
  }

  return distances;
}

int main() {
  int q; // number of queries
  cin >> q;
  // cout << q << " queries" << endl;
  for (int i = 0; i < q; i++) {
    int n; // number of nodes in graph
    int m; // number of edges in graph
    cin >> n >> m;

    // cout << "query[" << i << "]: " << n << " node(s), " << m << " edge(s)" <<
    // endl;

    Graph graph(n);

    for (int j = 0; j < m; j++) {
      int u;
      int v;
      cin >> u >> v;

      // adjust vertex indices because they're 1-based
      u--;
      v--;
      graph.add_edge(u, v);

      // cout << "edge[" << j << "] = " << u << " <-> " << v << endl;
    }

    int s; // the starting node for bfs
    cin >> s;
    s--; // also adjust this index
    // cout << "source: " << s << endl;

    vector<int> distances = shortest_reach(graph, s);

    for (int i = 0; i < distances.size(); i++) {
      if (i != s)
        cout << distances[i] << " ";
    }
    cout << endl;
  }
}
