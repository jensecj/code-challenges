/*
  tags: simple math
  task: given two numbers, and another number, figure which of the
  first two numbers are closest to the third number
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int q; // the number of queries
  cin >> q;

  while(q--) {
    int a,b,c; // the location of cat a, cat b, and the mouse.
    cin >> a >> b >> c;

    int cata = abs(a-c);
    int catb = abs(b-c);
    if(cata < catb) cout << "Cat A" << endl;
    else if (catb < cata) cout << "Cat B" << endl;
    else cout << "Mouse C" << endl;
  }
}
