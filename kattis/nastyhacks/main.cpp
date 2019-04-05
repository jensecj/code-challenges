/*
  tags:

  task: given three numbers, the revenue without advertising, the revenue with
  advertising, and the cost of advertising, output whether to advertise or not.

  url: https://open.kattis.com/problems/nastyhacks
*/
#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    int r, e, c;
    cin >> r >> e >> c;

    int net = e - c;

    if (net > r) {
      cout << "advertise" << endl;
    } else if (net < r) {
      cout << "do not advertise" << endl;
    } else {
      cout << "does not matter" << endl;
    }
  }
}
