/*
  tags: stack, maximum stack
  task: use a stack. given some queries, either push an element onto
  the stack, pop an element off, or print the biggest element in the
  stack.
  note: this approach also works for keeping track of a minimum
  element, just change the comparison
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int N; // number of queries to perform
  cin >> N;

  stack<int> S;
  stack<int> maxes;

  for (int i = 0; i < N; i++) {
    int action;
    cin >> action;

    // everytime we push an element onto the stack, check if it is
    // bigger than (or equal to) the biggest element we have seen thus
    // far, if it is, we push it to the stack we keep of maxes. this
    // way we can retrive the max in O(1) time. and space is O(2n) =
    // O(n)
    if(action == 1) {
      int element;
      cin >> element;

      S.push(element);

      if(maxes.empty() || element >= maxes.top())
        maxes.push(element);
    }

    // everytime we pop off an element from the stack, if it matches
    // the max element we have seen, we also pop it off the maxes
    // stack, since we should no longer count it.
    if(action == 2) {
      int element = S.top();

      if(element == maxes.top())
        maxes.pop();

      S.pop();
    }

    if(action == 3)
      cout << maxes.top() << endl;
  }
}
