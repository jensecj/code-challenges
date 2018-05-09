/*
  tags: min heap / array
  task: given an array of some sticks of some height. at every tick,
  we cut all sticks in the array by the height of the shortest stick,
  and we keep ticking until all sticks are gone. before every tick,
  print how many sticks are left.
*/
#include <iostream>
#include <queue>

using namespace std;

// we can easily do this with a min heap, another approach would be to
// sort the array, and only run through it once, updating the
// cut-height every time we pass a new height of stick, this can be
// done in O(n).
int main() {
  int N; // the number of sticks
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> min_heap;

  for (int i = 0; i < N; i++) {
    int stick;
    cin >> stick;
    min_heap.push(stick);
  }

  int cut = 0;
  while(!min_heap.empty()) {
    int top = min_heap.top();
    cerr << "top: " << top << endl;
    cut += top;

    cout << min_heap.size() << endl;

    while(!min_heap.empty() && top >= min_heap.top()) {
      min_heap.pop();
    }
  }
}
