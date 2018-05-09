/*
  tags: heap, hashmap,
  task: you have an empty set, and two operations you can perform on
  it, you can insert a number into it, or remove a number from it.
  given some series inserts and removes of numbers, after each
  command, print the product of the minimum and maximum numbers of the
  set
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// we keep track of the min and max elements by using two heaps, and
// we simple remember which numbers we have removed, and how many of
// them we have removed, and then when we need to figure out which
// elements are the max/min, we skip the deleted ones, space is O(2n)
// = O(n), and since we just keep track of each pop, there is no extra
// cost there. in the worst case, after each command, we would have to
// remove 1 element before we are back to balance.
vector<long> maxMin(vector<string> operations, vector<int> x) {
  int n = operations.size();

  unordered_map<long,int> removed;

  vector<long> results;

  priority_queue<long, vector<long>, greater<long>> min_heap;
  priority_queue<long, vector<long>, less<long>> max_heap;

  for (int i = 0; i < n; i++) {
    if(operations[i] == "push") {
      cerr << "push " << x[i] << endl;
      removed[x[i]]--;

      if(removed[x[i]] < 0)
        removed[x[i]] = 0;

      max_heap.push(x[i]);
      min_heap.push(x[i]);
    } else if (operations[i] == "pop") {
      cerr << "pop " << x[i] << endl;
      removed[x[i]]++;
      cerr << "removed += " << x[i] << endl;
    }

    long min = min_heap.empty() ? 0 : min_heap.top();
    cerr << "min: " << min << endl;
    while(removed[min] > 0) {
      removed[min]--;
      min_heap.pop();
      min = min_heap.top();
      cerr << "min was removed, new min: " << min << endl;
    }

    long max = max_heap.empty() ? 0 :  max_heap.top();
    cerr << "max: " << max << endl;
    while(removed[max] > 0) {
      removed[max]--;
      max_heap.pop();
      max = max_heap.top();
    }

    cerr << "max*min = " << max * min << endl;
    results.push_back(max*min);
  }

  return results;
}

int main() {
  int n; // number of operations
  cin >> n;

  vector<string> ops(n);
  for (int i = 0; i < n; i++)
    cin >> ops[i];

  int m; // number of numbers
  cin >> m;

  vector<int> xs(m);
  for (int i = 0; i < m; i++)
    cin >> xs[i];

  vector<long> results = maxMin(ops, xs);
}
