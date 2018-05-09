/*
  tags: sorting, programming puzzle
  task: you are given n containers, and n different types of balls.
  each container can hold some number of a type of ball. and given the
  restrictions that a container can only hold one type of ball, and no
  two balls of the same type can be in different containers, is it
  possible to move the balls around between the containers (in swaps)
  such that you fulfill the requirements?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int q; // # of queries
  cin >> q;

  while(q--) {
    int n; // number of containers and ball types
    cin >> n;

    // the idea here is that we don't actually have to deal with the
    // matrix at all, we know how big each container is, that a
    // container can only contain one type of ball, that all balls of
    // a type must be in the same container, and we know how many of
    // each type of ball there is. so we just need to match up each
    // container with a type of ball, simply sort the arrays and check
    // if we can contain them.
    vector<int> containers(n);
    vector<int> balls(n);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int v;
        cin >> v;

        balls[i] += v;
        containers[j] += v;
      }
    }

    bool possible = true;

    sort(balls.begin(), balls.end());
    sort(containers.begin(), containers.end());

    for(int i = 0; i < n; i++) {
      if(balls[i] > containers[i]) {
        possible = false;
        break;
      }
    }

    if(possible) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
  }
}
