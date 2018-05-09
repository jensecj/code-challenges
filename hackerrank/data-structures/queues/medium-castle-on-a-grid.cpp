/*
  tags: queues, bfs
  task: given a 2d grid, a start location on that grid, and a goal
  location, figure out how many moves it takes to get from start to
  goal, with the added feature, that any straight line move, only
  takes one move (like castles in chess), there are also blocked
  locations on the grid.
*/
#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

// this is where most of the work happens. when we add neighbours for
// a node, we also add neighbours in straight lines north, east,
// south, and west, if nothing is blocking their path, and the cost of
// moving to these is 1 move.
vector<pair<int,int>> neighbours(vector<vector<int>>& graph, int x, int y) {
  int n = graph.size();
  int m = graph[0].size();

  if(x < 0 || x > n || y < 0 || y > m) {
    cerr << "ERROR:" << x << "," << y << " [" << n << "," << m << "]" << endl;
    throw new runtime_error("error: index for node was outside bounds");
  }

  vector<pair<int,int>> neighbours;

  // add neighbours along the north, east, south, and west lines

  int xx = x-1;
  while(xx >= 0) {
    if(graph[xx][y]) { // is this is not a blocked location
      neighbours.push_back(make_pair(xx, y)); // add a new neighbour (along the x-i line)
      if(graph[x][y]+1 < graph[xx][y] || graph[xx][y] == 1) // if we find a shorter distance to a node, update the costs
        graph[xx][y] = graph[x][y]+1;
    }
    else // if it is a blocked location, stop adding locations along this line
      break;
    xx--;
  }
  xx = x+1;
  while(xx < n) {
    if(graph[xx][y]) {
      neighbours.push_back(make_pair(xx, y));
      if(graph[x][y]+1 < graph[xx][y] || graph[xx][y] == 1)
        graph[xx][y] = graph[x][y]+1;
    }
    else
      break;
    xx++;
  }

  int yy = y-1;
  while(yy >= 0) {
    if(graph[x][yy]) {
      neighbours.push_back(make_pair(x, yy));
      if(graph[x][y]+1 < graph[x][yy] || graph[x][yy] == 1)
        graph[x][yy] = graph[x][y]+1;
    }
    else
      break;
    yy--;
  }
  yy = y+1;
  while(yy < m) {
    if(graph[x][yy]) {
      neighbours.push_back(make_pair(x, yy));
      if(graph[x][y]+1 < graph[x][yy] || graph[x][yy] == 1)
        graph[x][yy] = graph[x][y]+1;
    }
    else
      break;
    yy++;
  }

  return neighbours;
}

// almost ordinary bfs
void BFS(vector<vector<int>>& graph, pair<int,int> source, pair<int,int> goal, vector<vector<int>>& discovered) {
  queue<pair<int,int>> queue;
  queue.push(source);

  // keep looking at nodes as long as we have some in the queue
  while(!queue.empty()) {
    pair<int,int> p = queue.front();
    queue.pop();

    cerr << "at: " << p.first << "," << p.second << endl;

    // if a node is not forbidden, and not yet seen, examine it
    if(graph[p.first][p.second] && !discovered[p.first][p.second]) {

      discovered[p.first][p.second] = true;

      if(goal == p) {
        cerr << "found goal" << endl;
        return;
      }

      // add all neighbours that are not forbidden and not yet seen to the queue
      for(auto& n : neighbours(graph, p.first, p.second)) {
        if(graph[n.first][n.second] && !discovered[n.first][n.second]) {
          queue.push(make_pair(n.first, n.second));
          cerr << " neighbour: " << n.first << "," << n.second << endl;
        }
      }
    }
  }
}

int main() {
  int N; // size of the grid (N*N)
  cin >> N;

  // the problem description uses characters, but we'll convert it to
  // a boolean matrix just for convenience
  vector<vector<int>> graph(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    string in;
    cin >> in;
    for(int j = 0; j < N; j++) {
      graph[i][j] = in[j] == '.';
    }
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      // print the graph
      cerr << graph[i][j] << " ";
      if(j % N == N-1) cerr << endl;
    }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      // print the graph
      cerr << i << "," << j << " ";
      if(j % N == N-1) cerr << endl;
    }

  int a,b; // initial position of the castle
  cin >> a >> b;

  cerr << "castle at " << a << "," << b << endl;

  int c,d; // position we want to move the castle to
  cin >> c >> d;

  cerr << "goal at " << c << "," << d << endl;

  vector<vector<int>> discovered(N, vector<int>(N));

  graph[a][b] = 1;

  BFS(graph, make_pair(a,b), make_pair(c,d), discovered);

  // we subtract one because the starting location is noted as a cost
  // of 1 (even if it is zero)
  cout << graph[c][d] - 1 << endl;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      // print the graph
      cerr << +graph[i][j] << " ";
      if(j % N == N-1) cerr << endl;
    }
}
