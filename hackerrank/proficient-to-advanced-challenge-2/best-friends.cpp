/*
  tags:
  task:
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cmath>

using namespace std;

// a graph class using an adjacency list internally to keep track of
// connecting nodes
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
    cerr << u << " <-> " << v << endl;
  }

  vector<int> neighbours(int node) {
    return adjacency_list[node];
  }
};

int bestTrio(int nodes, vector<int> from, vector<int> to) {
  vector<pair<int,int>> trios(nodes, make_pair(-1,-1));

  Graph graph(nodes);

  int edges = from.size()-1;
  for (int i = 0; i < edges; i++) {
    graph.add_edge(from[i], to[i]);
  }

  for (int i = 1; i < nodes; i++) {
    cerr << "testing node " << i << endl;
    vector<int> i_ns = graph.neighbours(i);
    // if this node has less than 2 friends, it cannot make a trio
    if(i_ns.size() < 2) {
      cerr << " not enough neighbours" << endl;
      continue;
    }

    cerr << " " << i_ns.size() << " neighbours: ";
    for(auto& n : i_ns)
      cout << n << " ";
    cout << endl;

    // for each neighbour, we need to check if the other neighbours
    // are also its neighbours
    for (int j = 0; j < i_ns.size()-1; j++) {
      int n = i_ns[j];

      vector<int> n_ns = graph.neighbours(n);
      for (int k = 0; k < n_ns.size(); k++) {
        vector<int> n_ns_ns = graph.neighbours(n_ns[k]);
        for (int l = 0; l < n_ns_ns.size(); l++) {
          if(n_ns_ns[l] == i) {
            cerr << " new trio: " << i << "," << j << "," << k << endl;
            trios[i] = make_pair(j, k);
          }
        }
      }
    }

    cout << endl << " all trios:" << endl << " ";

    for (int i = 0; i < nodes; i++) {
      if(trios[i].first != -1) {
        cout << i << ", " << trios[i].first << ", " << trios[i].second << endl << " ";
      }
    }

    cout << endl;
  }

  int min_trio_sum = 999;
  for (int i = 0; i < nodes; i++) {
    if(trios[i].first != -1) {
      int trio_sum = graph.neighbours(i).size() - 2;
      trio_sum += graph.neighbours(trios[i].first).size() - 2;
      trio_sum += graph.neighbours(trios[i].second).size() - 2;

      if(trio_sum < min_trio_sum && trio_sum >= 0)
        min_trio_sum = trio_sum;

      cout << "{" << i << "," << trios[i].first << "," << trios[i].second << "} = " << trio_sum << endl;
    }
  }

  cerr << "min trio sum: " << min_trio_sum << endl;
  return min_trio_sum;
}

int main() {
  int nodes, edges; // the number of nodes and edges in the graph
  cin >> nodes >> edges;
  cerr << "nodes: " << nodes << ", edges: " << edges << endl;

  vector<int> from(edges);
  vector<int> to(edges);

  for (int i = 0; i < edges; i++) {
    cin >> from[i];
    cin >> to[i];
    // cerr << from[i] << " -> " << to[i] << endl;
  }

  bestTrio(nodes, from, to);
}
