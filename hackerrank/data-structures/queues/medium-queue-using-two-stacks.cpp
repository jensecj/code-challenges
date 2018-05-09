/*
  tags: queues, stacks
  task: emulate a queue using two stacks
*/
#include <iostream>
#include <stack>

using namespace std;

void enqueue(int i, stack<int>& a, stack<int>& b) {
  a.push(i);
}

void flood(stack<int>& a, stack<int>& b) {
  while(!a.empty()) {
    int i = a.top();
    a.pop();
    b.push(i);
  }
}

int dequeue(stack<int>& a, stack<int>& b) {
  if(a.empty() && b.empty())
    return -1;

  if(b.empty())
    flood(a, b);

  int i = b.top();
  b.pop();
  return i;
}

int peek(stack<int>& a, stack<int>& b) {
  if(a.empty() && b.empty())
    return -2;

  if(b.empty())
    flood(a, b);

  int i = b.top();
  return b.top();
}

int main() {
  int q; // the number of queries
  cin >> q;

  stack<int> a;
  stack<int> b;

  for(int i = 0; i < q; i++) {
    int type;
    cin >> type;

    int val;
    if(type == 1)
      cin >> val;

    switch(type) {
    case 1: enqueue(val, a, b); break;
    case 2: dequeue(a, b); break;
    case 3: cout << peek(a, b) << endl; break;
    default: cout << "error: unknown command: " << type << endl; break;
    }
  }
}
