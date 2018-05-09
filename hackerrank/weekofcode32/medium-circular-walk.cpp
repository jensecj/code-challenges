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

static inline int mod(int x){
  return (x % n + n) % n;
}

static inline int mod(int x, int a){
  return (x % a + a) % a;
}

int jumpgame(vector<int>* list) {
  if((*list)[0] == 0) return -1;
  if((*list)[0] >= list->size()-1) return 1;

  int n = list->size();

  int level = 0, currentMax = 0, i = 0, nextMax = 0;

  while(currentMax-i+1 > 0){		//nodes count of current level>0
    level++;
    for(; i <= currentMax; i++){	//traverse current level , and update the max reach of next level
      nextMax = max(nextMax, (*list)[i] + i);
      if(nextMax >= n-1)
        return level;   // if last element is in level+1,  then the min jump=level
    }
    currentMax = nextMax;
  }

  // vector<int> sums(list->size());
  // int i;
  // for(i = 0; i < sums.size(); i++) {
  //   sums[i] = i + (*list)[i];
  // }

  // vector<int> moves;
  // moves.push_back(0);

  // while (1) {
  //   int currentPosition = moves.back();
  //   int jumpValue = (*list)[currentPosition];

  //   // See if we can jump to the goal
  //   if (n - 1 - currentPosition <= jumpValue) {
  //     moves.push_back(n - 1);
  //     return moves.size();
  //   } else {
  //     int maxIndex = currentPosition;
  //     for (i = currentPosition; i <= currentPosition + jumpValue; i++) {
  //       if (!maxIndex || sums[i] > sums[maxIndex]) {
  //         maxIndex = i;
  //       }
  //     }
  //     if (maxIndex == currentPosition) {
  //       return moves.size();
  //     }
  //     moves.push_back(maxIndex);
  //   }
  // }

  return -1;
}

const int MAX_IDX = 10000010;

vector<int>* aforward = new vector<int>(MAX_IDX);
vector<int>* abackward = new vector<int>(MAX_IDX);

int walk(vector<int>& G, int s, int t) {
  // fill(G.begin(), G.end(), 0);
  // G = { 1,0,0,1 };
  // G.resize(4);
  // n = 4;

  if(s == t) return 0;
  if(G[s] == 0) return -1;
  if(s < t && G[s] >= t-s) return 1;
  if(s > t && G[s] >= s-t) return 1;

  int fidx = 0;
  for(int i = s; i != t; i++) {
    (*aforward)[fidx++] = G[i];
  }
  (*aforward)[fidx++] = G[t];
  aforward->resize(fidx);

  int bidx = 0;
  for(int i = s; i != t; i = mod(i-1)) {
    (*abackward)[bidx++] = G[i];
  }
  (*abackward)[bidx++] = G[t];
  abackward->resize(bidx);

  for(auto& a : G) cerr << a << ","; cerr << endl;
  for(auto& a : (*aforward)) cerr << a << ","; cerr << endl;
  for(auto& a : (*abackward)) cerr << a << ","; cerr << endl;

  int m1 = jumpgame(aforward);
  int m2 = jumpgame(abackward);

  cerr << "m1: " << m1 << endl;
  cerr << "m2: " << m2 << endl;

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

int jump(vector<int> A) {
  int n = A.size();
  if(n<2)return 0;
  int level=0,currentMax=0,i=0,nextMax=0;

  while(currentMax-i+1>0){		//nodes count of current level>0
    level++;
    for(;i<=currentMax;i++){	//traverse current level , and update the max reach of next level
      nextMax=max(nextMax,A[i]+i);
      if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level
    }
    currentMax=nextMax;
  }
  return -1;
}

int forward_dist(vector<int>& G, int s, int t) {
  return abs(t - s);
}

int backward_dist(vector<int>& G, int s, int t) {
  if(s > t) return t-s;
  return G.size() - abs(t - s);
}

int qtry(vector<int>& G, int s, int t, int mode) {
  // if(s == t) return 0;
  // if(G[s] == 0) return -1;
  // if(s < t && G[s] >= t-s) return 1;
  // if(s > t && G[s] >= s-t) return 1;

  vector<bool> seen(G.size());

  queue<ii> tries;
  tries.push({s,0});

  // int fdist = forward_dist(G, s, t);
  // int bdist = backward_dist(G, s, t);
  // cerr << "dists: " << fdist << "," << bdist << endl;

  while(!tries.empty()) {
    ii thisnode = tries.front();
    int node = thisnode.first;
    tries.pop();
    cerr << "AT NODE: " << node << " (" << thisnode.second << ")" << endl;
    seen[node] = true;

    int best_forward = node;
    int best_fdist = forward_dist(G, node, t);

    for(int i = 1; i <= G[node]; i++) {
      int trynode = mod(node+i, mode);
      if(seen[trynode]) continue;
      cerr << "  +" << i << " : " << trynode << "[" << G[trynode] << "]";

      if(trynode == t) return thisnode.second + 1;

      int fdist = forward_dist(G, trynode, t);
      cerr << " (to goal: " << fdist << ") " << endl;

      if(fdist < best_fdist) {
        best_forward = trynode;
        best_fdist = fdist;
      }
    }

    int best_backward = node;
    int best_bdist = backward_dist(G, node, t);
    cerr << "back dist from node to goal: " << best_bdist << endl;
    for(int i = 1; i <= G[node]; i++) {
      int trynode = mod(node - i, mode);
      if(seen[trynode]) continue;
      cerr << "  -" << i << " : " << trynode << "[" << G[trynode] << "]";

      if(trynode == t) return thisnode.second + 1;

      int bdist = backward_dist(G, trynode, t);
      cerr << " (to goal: " << bdist << ")" << endl;

      if(bdist < best_bdist) {
        best_backward = trynode;
        best_bdist = bdist;
      }
    }

    if(best_forward != node && !seen[best_forward]) {
      cerr << "  best forward: " << best_forward << endl;
      tries.push({best_forward, thisnode.second + 1});
    }
    if(best_backward != node && !seen[best_backward]) {
      tries.push({best_backward, thisnode.second + 1});
      cerr << "  best backward: " << best_backward << endl;
    }
  }

  return -1;
}

int main() {
  cin >> n >> s >> t;
  // cerr << "n: " << n << ", s: " << s << ", t: " << t << endl;
  R.resize(n);
  cin >> R[0] >> g >> seed >> p;

  for(int i = 1; i < n; i++)
    R[i] = (R[i-1] * g + seed) % p;

  // cout << walk(R, s, t) << endl;
  // vector<int> A{2,2,1,1,4};
  // cout << jump(A) << endl;

  // cout << qtry(R, s, t, n) << endl;

  for(int i = 0; i < 10; i++)
    cerr << endl;

  // vector<int> A {0,1,1,1,4,5};
  // int goal = qtry(A, 2, 5, A.size());
  // cout << endl << goal << endl;

  vector<int> A {1,0,4,2,3,6,1,0,4};
  int goal = qtry(A, 0, 2, A.size());
  cout << endl << goal << endl;
}
