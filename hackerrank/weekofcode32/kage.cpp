#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
#include <climits>
#include <list>

using namespace std;

typedef pair<int,int> ii;

vector<int> R;
int n,s,t;
int g, seed, p;
int V;

static inline int mod(int x){
  return (x % n + n) % n;
}

vector<int> neighbours(int node) {
  vector<int> ns;

  for(int j = -R[node]; j <= R[node]; j++) {
    if(j == 0) continue;
    // cerr << i << " -> " << mod(i+j) << endl;
    int a = mod(node+j);
    if(R[a] != 0)
      ns.push_back(a);
  }

  return ns;
}

vector<int> neighbours(int node, const vector<bool>& seen) {
  vector<int> ns;

  for(int j = -R[node]; j <= R[node]; j++) {
    if(j == 0) continue;
    // cerr << i << " -> " << mod(i+j) << endl;
    int a = mod(node+j);
    if(R[a] != 0 && !seen[a])
      ns.push_back(a);
  }

  return ns;
}

vector<int> BFS2(vector<int>& graph, int source, int target) {
  vector<int> distances(graph.size(), -1);
  distances[source] = 0;

  vector<unsigned char> seen(graph.size());

  for(int i = 0; i < seen.size(); i++)
    seen[i] = false;

  queue<int> queue;
  queue.push(source);

  while(!queue.empty()) {
    const int c = queue.front();
    queue.pop();

    bool found = false;
    if (n == target) {
      found = true;
      break;
    }

    seen[c] = true;

    for(const int n : neighbours(c)) {
      if(distances[n] == -1) {
        distances[n] = distances[c] + 1;

        if(!seen[n])
          queue.push(n);
        else
          cerr << "already seen " << n << endl;

        seen[n] = true;
      }

      if (n == target) {
        found = true;
        break;
      }
    }

    if(found) break;
  }

  return distances;
}

vector<int> BFS3(vector<int>& graph, queue<int>& queue, vector<bool>& seen, vector<int>& distances, int source, int target) {
  const int c = queue.front();
  queue.pop();

  seen[c] = true;

  for(const int n : neighbours(c)) {
    if(distances[n] == -1) {
      distances[n] = distances[c] + 1;
      queue.push(n);
      // seen[n] = true;
    }
  }

  return distances;
}
int intersect(vector<bool> a, vector<bool> b) {
  for(int i = 0; i < a.size(); i++) {
    if(a[i] && (a[i] && b[i]))
      return i;
  }

  return -1;
}
int BDS3(vector<int>& G, int s, int t) {
  vector<bool> s_seen(G.size());
  vector<bool> t_seen(G.size());
  s_seen[s] = true;
  t_seen[t] = true;

  vector<int> s_dist(G.size(), INT_MAX);
  vector<int> t_dist(G.size(), INT_MAX);
  s_dist[s] = 0;
  t_dist[t] = 0;

  queue<int> s_queue;
  queue<int> t_queue;
  s_queue.push(s);
  t_queue.push(t);

  while (!s_queue.empty() && !t_queue.empty()) {
    BFS3(G, s_queue, s_seen, s_dist, s, t);
    BFS3(G, t_queue, t_seen, t_dist, s, t);

    int i = intersect(s_seen, t_seen);

    if(i)
      return i;
  }

  return -1;
}

int dijkstra(vector<int>& graph, int source, int target) {
  if(source == target) return 0;

  vector<bool> seen(graph.size());

  vector<int> min_distance(graph.size(), INT_MAX);
  min_distance[source] = 0;

  set<ii> active_vertices;
  active_vertices.insert({-1, source});

  while (!active_vertices.empty()) {
    int node = active_vertices.begin()->second;

    if (node == target)
      return min_distance[node];

    seen[node] = true;

    active_vertices.erase(active_vertices.begin());

    for (auto ed : neighbours(node, seen)) {
      if (min_distance[ed] > min_distance[node] + 1 && !seen[ed]) {
        active_vertices.erase( { min_distance[ed], ed } );

        min_distance[ed] = min_distance[node] + 1;

        active_vertices.insert({min_distance[ed], ed});
      }
    }
  }
  return -1;
}


int visitedIntersect(bool *s_visited, bool *t_visited)
{
  int j;
  for(j = V-1; j >= 0; j--) {
    if(s_visited[j] && s_visited[j] == t_visited[j])
      return j;
  }
  return -1;
}
void BFS(list<int> *queue, bool *visited, int *prev, int *dist) {
  int current = queue->front();
  queue->pop_front();
  for(auto& i : neighbours(current)) {
    if(!visited[i]) {
      dist[i] = dist[current]+1;
      prev[i] = current;
      visited[i] = true;
      queue->push_back(i);
    }
  }
}
int BDS(int s, int t){
  bool *s_visited = new bool[V];
  bool *t_visited = new bool[V];
  int *s_prev = new int[V];
  int *t_prev = new int[V];
  int *s_dist = new int[V];
  int *t_dist = new int[V];
  int meet_pt = -1;

  for (int i = 0; i < V; ++i) {
    s_visited[i] = false;
    t_visited[i] = false;
  }

  list<int> s_queue, t_queue;

  s_visited[s] = true;
  s_prev[s] = -1;
  s_dist[s] = 0;
  s_queue.push_back(s);

  t_visited[t] = true;
  t_prev[t] = -1;
  t_dist[t] = 0;
  t_queue.push_back(t);

  while(!s_queue.empty() && !t_queue.empty()) {
    //from front
    BFS(&s_queue, s_visited, s_prev, s_dist);
    //from back
    BFS(&t_queue, t_visited, t_prev, t_dist);

    meet_pt = visitedIntersect(s_visited, t_visited);
    if(meet_pt != -1) {
      return s_dist[meet_pt] + t_dist[meet_pt];
      // return meet_pt;
    }
  }

  return -1;
}

int jg(vector<int>& A) {
  int n = A.size();
  // if (n <= 1) return 0;
  // int maxReachableDistance = 0;
  // int maxNextAvailableDist = 0;
  // int minSteps = 0;

  // for (int i = 0; i < n; ++i) {
  //   if (i > maxReachableDistance) {
  //     if (maxNextAvailableDist > maxReachableDistance) {
  //       maxReachableDistance = maxNextAvailableDist;
  //       ++minSteps;
  //     }
  //     else
  //       return -1;
  //   }
  //   maxNextAvailableDist = max(maxNextAvailableDist, A[i] + i);
  //   if (maxNextAvailableDist >= n - 1) return minSteps + 1;
  // }

  // return minSteps;


  int res = 0;
  int last = 0, cur = 0;
  for(int i = 0; i < n; ++i) {
    if(i > last) {
      last = cur;
      ++res;
    }
    if(i+A[i] > cur) {
      cur = i+A[i];
    }
  }
  return res;
}

int jumpgame(vector<int>& list) {
  if(list[0] == 0) return -1;
  if(list[0] >= list.size()) return 1;



  return -1;
}

int walk(vector<int>& G, int s, int t) {
  if(G[s] == 0) return -1;
  // if(G[s] <= abs(t-s)) return 1;

  vector<int> forward(G.begin()+s, G.begin()+t+1);
  vector<int> backward;
  for(int i = s; i != t; i = mod(i-1)) {
    backward.push_back(G[i]);
  } backward.push_back(G[t]);

  for(auto& a : G) cerr << a << ","; cerr << endl;
  for(auto& a : forward) cerr << a << ","; cerr << endl;
  for(auto& a : backward) cerr << a << ","; cerr << endl;

  int m1 = jg(forward);
  int m2 = jg(backward);

  if(m1 < 0) return m2;
  if(m2 < 0) return m1;

  return min(m1, m2);

  // vector<int> dist(G.size(), INT_MAX);
  // dist[s] = 0;

  // int j = 0;
  // int k = 0;
  // while(j != 1) {
  //   for(int i = 0; i < j - 1; i++)
  //     if(G[i] >= j - i - 1) {
  //       dist[k++] = i;
  //       j = i+1;
  //       break;
  //     }
  // }
  // return k;
  // queue<int> q;
  // q.push(s);

  // int i;
  // vector<int> sums;
  // for(i = 0; i < G.size(); i++) {
  //   sums.push_back(i + G[i]);
  // }

  // while (1) {
  //   int currentPosition = q.front();
  //   int jumpValue = G[currentPosition];

  //   // See if we can jump to the goal
  //   if (G.size() - 1 - currentPosition <= jumpValue) {
  //     q.push(G.size() - 1);
  //     return q.size();
  //   } else {
  //     int maxIndex = currentPosition;
  //     for (i = currentPosition; i <= currentPosition + jumpValue; i++) {
  //       if (!maxIndex || sums[i] > sums[maxIndex]) {
  //         maxIndex = i;
  //       }
  //     }
  //     if (maxIndex == currentPosition) {
  //       return -1;
  //     }
  //     q.push(maxIndex);
  //   }
  // }
}

int main() {
  cin >> n >> s >> t;
  cerr << "n: " << n << ", s: " << s << ", t: " << t << endl;
  R.resize(n);
  cin >> R[0] >> g >> seed >> p;


  for(int i = 1; i < n; i++) {
    R[i] = (R[i-1] * g + seed) % p;
    // cerr << "R[" << i << "] = " << R[i] << endl;
  }
  V = R.size();
  // cout << BDS(s, t) << endl;
  // cout << dijkstra(R, s, t) << endl;
  // cout << dive(graph, s, t) << endl;
  // cout << BFS2(R, s, t)[t] << endl;

  cout << walk(R, s, t) << endl;
}
