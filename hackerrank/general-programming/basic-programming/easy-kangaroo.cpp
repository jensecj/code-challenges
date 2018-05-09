/*
  tags: mod arithmetic
  task: given two kangaroos that start somewhere on the x-axis, and
  with every jump, they each move some distance in the positive
  direction (the distance they travel depends on the kangaroo),
  determine if they ever meet up at some point in the future (after x jumps).
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x1, v1, x2, v2; // starting positions and travel distance per
                      // jump, for each kangaroo
  cin >> x1 >> v1 >> x2 >> v2;

  // if the slower kangaroo starts further back, they will never meet up
  if((x1 < x2 && v1 < v2) ||
     (x2 < x1 && v2 < v1)) {
    cout << "NO" << endl;
    return 0;
  }

  // if we are able to make up the difference in the starting
  // distance, and we are congruent, we will be able to land on the
  // same spot at some point in the future
  if(v1 > v2 && (x1-x2) % (v1-v2) == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
