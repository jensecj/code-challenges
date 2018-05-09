/*
  tags: sorting, pairs
  task: you run a pizaria, given a sequence of orders, and some time
  it takes to complete each order, print out the orders as they are
  completend.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> ii;

int main() {
  int n; // # of orders
  cin >> n;

  vector<ii> orders(n);
  for(int i = 0; i < n; i++) {
    int a,b;
    cin >> a >> b;
    orders[i].first = a+b;
    orders[i].second = i+1; // 1 indexed
  }

  sort(orders.begin(), orders.end());

  for(int i = 0; i < n; i++) {
    cout << orders[i].second << " ";
  } cout << endl;
}
