/*
  tags: min heap
  task: given some number of cookies with a sweetness value, and a
  threshold for sweetness, and a way to combine cookies so they get
  sweeter, keep combining the two least sweet cookies, until all
  cookies exceed the threshold, or you run out of cookies to combine
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N, K; // the number of cookies, and the sweetness threshold
  cin >> N >> K;

  priority_queue<int, vector<int>, greater<int>> min_heap;

  while(N--) {
    int i; // the sweetness of cookie i
    cin >> i;

    min_heap.push(i);
  }

  int ops = 0;
  while(min_heap.size() >= 2 && min_heap.top() < K) {
    // we keep taking the two least sweet cookies and combining them,
    // then putting them back into the min heap, untill all cookies
    // are sweet enough, or we run out
    int a = min_heap.top();
    min_heap.pop();
    int b = min_heap.top();
    min_heap.pop();

    // add a new cookie with sweetness 1*a + 2*b
    min_heap.push(a + b + b);

    ops++;
  }

  if(min_heap.top() < K) // not possible to make cookies sweet enough
    cout << -1 << endl;
  else // it took ops combinations to make all cookies sweet enough
    cout << ops << endl;
}
