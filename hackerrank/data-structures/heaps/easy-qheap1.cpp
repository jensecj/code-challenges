/*
  tags: min heap
  task: implement a min heap which has three functions, add, delete
  (this is the weird one), and print. on add, add an element to the
  heap, keeping the minimum ordering, on delete, remove that element
  from the heep, also keeping (or remaking) the minimum ordering, on
  print, print the minimum element of the heap.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

template<typename T>
class min_heap : public priority_queue<T, vector<T>, greater<T>>
{
public:
  bool remove(const T& value) {
    auto it = find(this->c.begin(), this->c.end(), value);
    if (it != this->c.end()) {
      this->c.erase(it);
      make_heap(this->c.begin(), this->c.end(), this->comp);
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  int Q; // the number of queries
  cin >> Q;

  min_heap<int> q;

  // instead of using the remove function, we keep track of an item
  // when we get a command to remove it, if it is the front element,
  // we remove, otherwise we just remember it, and remove it when it
  // becomes the top (we also remember how many times it has been removed)
  unordered_map<int,int> removes;

  while(Q--) {
    int type;
    cin >> type;

    while(!q.empty() && removes.find(q.top()) != removes.end() && removes[q.top()] > 0) {
      removes[q.top()]--;
      q.pop();
    }

    if(type == 1) {
      int v;
      cin >> v;
      q.push(v);
    } else if(type == 2) {
      int v;
      cin >> v;

      if(q.top() == v)
        q.pop();
      else
        removes[v]++;

      // actually using this approach times out, which makes sense,
      // because heaps are not supposed to have remove functionality
      // for arbitrary elements, because we would need to search
      // through all elements in linear time, they are made to keep
      // track of the min/max elements.
      // q.remove(v);
    } else if(type == 3) {
      cout << q.top() << endl;
    }
  }
}
