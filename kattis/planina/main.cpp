/*
  tags: math

  task: Given a number of itarations of midpoint displacement, output the number
  of points for that iteration, starting with 4 nodes, and then with 1
  iteration, ending up with 9 points, with 2, 25 points, etc.

  url: https://open.kattis.com/problems/planina
*/
#include <iostream>

using namespace std;

// the trick here is to notice that the number of points, is the square of the
// n'th triangular number, for the input n.

int main() {
  int iterations;
  cin >> iterations;

  int x = 2;
  while (iterations--) {
    x += x - 1;
  }

  cout << x * x << endl;
}
