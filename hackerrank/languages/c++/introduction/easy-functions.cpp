/*
  tags:
  task:
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  int m = max(a,b);
  m = max(m, c);
  m = max(m, d);

  cout << m << endl;
}
