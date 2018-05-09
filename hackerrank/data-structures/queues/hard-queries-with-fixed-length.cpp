/*
  tags: queue
  task:
*/
#include <iostream>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

void solve_deque(const vector<int>& list, const vector<int>& ds) {
  int n = list.size();
  int q = ds.size();

  for(const int& d : ds) {
    deque <int> s;
    int min = INT_MAX;
    cout << "at: " << d << endl;
    int i = 0;
    for(i = 0; i < d; i++) {
      while(!s.empty() && list[i] > list[s.back()])
        s.pop_back();
      s.push_back(i);
    }
    for(; i < n; i++) {
      if(min > list[s.front()])
        min = list[s.front()];

      while(!s.empty() && s.front() <= i-d)
        s.pop_front();

      while(!s.empty() && list[i] > list[s.back()])
        s.pop_back();

      s.push_back(i);
    }

    if(min > list[s.front()])
      min = list[s.front()];

    cout << min << endl;
  }
}

void solve(const vector<int>& list, const vector<int>& ds) {
  int n = list.size();
  int q = ds.size();

  for(const int& d : ds) {
    queue<int> max_values;
    queue<int> sub_arr;

    int min_value = INT_MAX;

    for(int i = 0; i < n; i++) {
      if(i >= d && sub_arr.front() == max_values.front())
        max_values.pop();

      max_values.push(-1);

      while(!max_values.empty() && max_values.front() >= list[i]){
        max_values.push(max_values.front());
        max_values.pop();
      }

      while(!max_values.empty() && max_values.front() < list[i])
        max_values.pop();

      max_values.push(list[i]);
      sub_arr.push(list[i]);

      if(i >= d)
        sub_arr.pop();

      if(i >= d-1)
        min_value = min(min_value, max_values.front());
    }

    cout << min_value << endl;
  }
}

int main() {
  int n, q; // the length of the integer sequence, and the number of queries
  cin >> n >> q;
  cerr << "n: " << n << ", q: " << q << endl;
  vector<int> list(n);

  for (int i = 0; i < q; i++) {
    cin >> list[i];
  }

  vector<int> ds(q);
  for (int i = 0; i < q; i++) {
    cin >> ds[i];
  }

  solve_deque(list, ds);
}
