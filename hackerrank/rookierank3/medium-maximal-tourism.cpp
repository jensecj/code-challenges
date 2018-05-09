/*
  tags: graphs, connected components
  task: given a graph of cities, some connnected to others via bus
  routes, if we can choose to fly to whichever city, what is the
  maximum number of cities we can visit via bus routes?
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

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
    // add edge connections in both directions
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  vector<int> neighbours(int node) {
    return adjacency_list[node];
  }

  int size() {
    return vertices;
  }
};

int DFS_recursive(Graph& graph, int v, vector<bool>& discovered) {
  discovered[v] = true;

  int component_size = 0;
  for(auto& n : graph.neighbours(v)) {
    if(!discovered[n]) {
      // cerr << "found new node: " << v << endl;
      // everytime we look at a neighbour, we count it
      component_size += 1 + DFS_recursive(graph, n, discovered);
    }
  }

  return component_size;
}

int DFS(Graph& graph) {
  vector<bool> discovered(graph.size());

  int biggest_component = 0;

  for(int i = 0; i < graph.size(); i++) {
    int component_size = 1+DFS_recursive(graph, i, discovered);

    if (component_size > biggest_component)
      biggest_component = component_size;
  }

  return biggest_component;
}

// notice that the problem is about finding the maximum number of
// connected cities in a graph, i.e. finding the biggest connected
// components in a undirected graph, in this case. use DFS to find the
// biggest component in the graph.
int main() {
  int n,m; // number of nodes and edges in graph
  cin >> n >> m;
  cerr << "nodes: " << n << ", edges: " << m << endl;

  Graph graph(n);

  for(int i = 0; i < m; i++) {
    int u,v; // edge from u -> v
    cin >> u >> v;
    u--; v--; // they're 1-indexed
    graph.add_edge(u, v);
    cerr << "new edge " << u << " <-> " << v << endl;
  }

  cout << DFS(graph) << endl;
}
