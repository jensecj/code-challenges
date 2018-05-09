#include <iostream>

using namespace std;

int main() {
  int T; // test cases
  cin >> T;

  while(T--) {
    int n; // number of pairs of socks in the drawer
    cin >> n;

    // for each pair of socks, we have two socks, so we need to draw
    // half of that +1 to be sure to have atleast 1 pair of socks of
    // the same color
    cout << (n*2) / 2 + 1 << endl;
  }
}
