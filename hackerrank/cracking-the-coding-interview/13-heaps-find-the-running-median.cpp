/*
  tags: heaps, min heap, max heap, balancing, priority queue
  task: given a stream of numbers, output the running median while
  reading input (use heaps)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

void balance(priority_queue<int, vector<int>, less<int>>& min_heap,
             priority_queue<int, vector<int>, greater<int>>& max_heap) {
  // we only need to balance the heaps if they're out of order
  if(!min_heap.empty() && !max_heap.empty() && min_heap.top() > max_heap.top()) {
    int min_heap_head = min_heap.top();
    int max_heap_head = max_heap.top();

    min_heap.pop();
    max_heap.pop();

    min_heap.push(max_heap_head);
    max_heap.push(min_heap_head);
  }
}

void push(int i,
          priority_queue<int, vector<int>, less<int>>& min_heap,
          priority_queue<int, vector<int>, greater<int>>& max_heap) {
  // we insert the first element into the min heap, then we alternate
  // where we insert elements, and keep balancing the tree after each
  // insert
  if(min_heap.empty())
    min_heap.push(i);
  else if(min_heap.size() <= max_heap.size())
    min_heap.push(i);
  else
    max_heap.push(i);

  balance(min_heap, max_heap);
}

double median(priority_queue<int, vector<int>, less<int>>& min_heap,
              priority_queue<int, vector<int>, greater<int>>& max_heap) {
  // if we have two middle elements (an even number of ints in the list)
  if ((min_heap.size() + max_heap.size()) % 2 == 0) {
    return (min_heap.top() + max_heap.top()) / 2.0;
  } else {
    return min_heap.top();
  }
}

int main() {
  int n;
  cin >> n; // number of ints in the data stream

  priority_queue<int, vector<int>, less<int>> min_heap;
  priority_queue<int, vector<int>, greater<int>> max_heap;

  for(int i = 0; i < n; i++) {
    int input;
    cin >> input;

    push(input, min_heap, max_heap);
    cout << fixed << setprecision(1) << median(min_heap, max_heap) << endl;
  }
}
