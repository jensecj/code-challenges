/*
  tags:
  task:
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <tuple>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

void naive(string s) {
  set<tuple<int,int,int>> triplets;

  int n = s.length();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if(s[i] == 'a' && s[j] == 'b' && s[k] == 'c') {
          if(pow(j+1, 2) == (i+1)*((k+1))) {
            triplets.insert({i,j,k});
          }
        }
      }
    }
  }

  cout << triplets.size() << endl;
}

typedef pair<char,int> ci;

void better(string s) {
  int n = s.length();

  vector<int> as,bs,cs;

  for(int i = 0; i < n; i++) {
    if(s[i] == 'a') as.push_back(i);
    if(s[i] == 'b') bs.push_back(i);
    if(s[i] == 'c') cs.push_back(i);
  }

  cerr << "as: ";
  for(int i = 0; i < as.size(); i++) {
    cerr << as[i] << " ";
  } cerr << endl;
  cerr << "bs: ";
  for(int i = 0; i < bs.size(); i++) {
    cerr << bs[i] << " ";
  } cerr << endl;
  cerr << "cs: ";
  for(int i = 0; i < cs.size(); i++) {
    cerr << cs[i] << " ";
  } cerr << endl;

  set<tuple<int,int,int>> triplets;

  for(int i = 0; i < as.size(); i++) {
    int sum = pow(as[i]+1,2);
    cerr << "sum: " << sum << endl;
    vector<int> a;

    for(int b = 0; b < bs.size(); b++)
      a.push_back(b+1);

    for(int c = 0; c < cs.size(); c++)
      a.push_back((c+1)*-1);

    sort(a.begin(), a.end());

    int len = a.size()-1;
    int idx = 0;

    while(idx < len) {
      int p = a[idx] * a[len] * -1;
      cerr << " p: " << p << endl;
      if(p == sum) {
        triplets.insert({i, idx, len});
        cerr << "NEW TRIPLET" << endl;
      }
      else if (p < len)
        idx++;
      else
        len--;
    }
  }

  cout << triplets.size() << endl;
}

void even_better(string s) {
  int n = s.size();
  vector<int> as,bs,cs;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'a') as.push_back(i);
    if(s[i] == 'b') bs.push_back(i);
    if(s[i] == 'c') cs.push_back(i);
  }

  set<tuple<int,int,int>> triplets;

  for(int i = 0; i < bs.size(); i++) {
    int sum = pow(bs[i]+1,2);

    unordered_map<int, int> counts;

    // look through all the as and store the number we need to make a
    // pair equal to sum
    for(int a = 0; a < as.size(); a++) {
      counts[sum/(as[a]+1)]++;
      cerr << sum/(as[a]+1) << ",";
    } cerr << endl;

    // if we find that number in cs, we have made a pair that fits the
    // requirements
    for(int c = 0; c < cs.size(); c++) {
      int thisc = cs[c];
      // cerr << thisc << " ";
      if(counts[thisc+1]) {
        cerr << counts[thisc]-1 << " * " << thisc << " = " << i << "^2 (" << sum << ")" << endl;
        triplets.insert({counts[thisc]-1, i, thisc});
        counts[thisc+1]--;
      }
    } cerr << endl;
  }

  for(auto& t : triplets) {
    cerr << "{ " << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << " }" << endl;
  }

  cout <<  triplets.size() << endl;
}

int main() {
  int n; // chars in string
  cin >> n;

  string s;
  cin >> s;

  // naive(s);
  // better(s);
  even_better(s);
}
