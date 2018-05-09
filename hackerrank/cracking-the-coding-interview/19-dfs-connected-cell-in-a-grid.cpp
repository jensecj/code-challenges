/*
  tags: search, graph, dfs, depth first search, finding components, biggest component
  task: given a graph, find the biggest connected component and print its size
*/
#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

vector<pair<int,int>> neighbours(const vector<vector<int>>& graph, int x, int y) {
  int n = graph.size();
  int m = graph[0].size();

  if(x < 0 || x > n || y < 0 || y > m) {
    cout << "ERROR:" << x << "," << y << " [" << n << "," << m << "]" << endl;
    throw new runtime_error("error: index for node was outside bounds");
  }

  vector<pair<int,int>> neighbours;

  if(x-1 >= 0 && y-1 >= 0)
    neighbours.push_back(make_pair(x-1, y-1));
  if(x-1 >= 0)
    neighbours.push_back(make_pair(x-1, y));
  if(x-1 >= 0 && y+1 < m)
    neighbours.push_back(make_pair(x-1, y+1));

  if(y-1 >= 0)
    neighbours.push_back(make_pair(x, y-1));
  if(y+1 < m)
    neighbours.push_back(make_pair(x, y+1));

  if(x+1 < n && y-1 >= 0)
    neighbours.push_back(make_pair(x+1, y-1));
  if(x+1 < n)
    neighbours.push_back(make_pair(x+1, y));
  if(x+1 < n && y+1 < m)
    neighbours.push_back(make_pair(x+1, y+1));

  return neighbours;
}

int DFS_iterative(vector<vector<int>>& graph, pair<int,int> source, vector<vector<bool>>& discovered) {
  // push first element to stack, and everytime we find a new
  // undiscovered vertex, we push it to the stack as well, typical
  // rewrite of a recursive program to use stacks instead of recursion
  stack<pair<int,int>> stack;
  stack.push(source);

  int component_size = 0;

  // keep looking at nodes as long as we have some in the stack
  while(!stack.empty()) {
    pair<int,int> p = stack.top();
    stack.pop();

    // if a node is filled, and not yet seen, examine it
    if(graph[p.first][p.second] && !discovered[p.first][p.second]) {

      // cout << p.first << "," << p.second << " is discovered!" << endl;
      discovered[p.first][p.second] = true;
      component_size++;

      // add all neighbours that are filled and not yet seen to the stack
      for(auto& n : neighbours(graph, p.first, p.second)) {
        if(graph[n.first][n.second] && !discovered[n.first][n.second]) {

          stack.push(make_pair(n.first, n.second));

          // cout << "found new node: " << n.first << "," << n.second << endl;
        }
      }
    }
  }

  return component_size;
}

int DFS_recursive(vector<vector<int>>& graph, pair<int,int> v, vector<vector<bool>>& discovered) {
  discovered[v.first][v.second] = true;

  int component_size = 0;
  for(auto& n : neighbours(graph, v.first, v.second)) {
    if(!discovered[n.first][n.second] && graph[n.first][n.second]) {
      // cout << "found new node: " << n.first << "," << n.second << endl;
      // everytime we look at a neighbour, we count it
      component_size += 1 + DFS_recursive(graph, n, discovered);
    }
  }

  return component_size;
}

// runtime is O(|V| * |E|) for vertices V and edges E, because it
// looks at all edges and vertices. it also has space
// requirements O(|V|) for storing the 'discovered/visited' array, and
// a stack of yet-to-be-explored vertices (in the iterative case)
int DFS(vector<vector<int>>& graph) {
  int n = graph.size();
  int m = graph[0].size();

  vector<vector<bool>> discovered(n, vector<bool>(m));

  int biggest_component = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(graph[i][j] && !discovered[i][j]) {
        // cout << "trying node: " << i << "," << j << endl;
        // +1 because the source element is also part of the component
        // int component_size = 1 + DFS_recursive(graph, make_pair(i,j), discovered);
        int component_size = DFS_iterative(graph, make_pair(i,j), discovered);

        if (component_size > biggest_component)
          biggest_component = component_size;
      }
    }
  }

  return biggest_component;
}

int main() {
  int n; // number of rows in matrix
  int m; // number of columns in matrix;
  cin >> n >> m;

  vector<vector<int>> graph(n, vector<int>(m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> graph[i][j];

      // print the graph
      // cout << graph[i][j] << " ";
      // if(j % m == m-1) cout << endl;
    }
  }

  cout << DFS(graph) << endl;
}
