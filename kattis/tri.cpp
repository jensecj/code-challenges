/*
  tags: simple programming puzzle
  task: given three numbers, figure out which equation makes sense
  (one number equals the two others, using only +,-,*,/)
*/
#include <iostream>

using namespace std;

int main() {
  int a,b,c; // the three integers
  cin >> a >> b >> c;

  // there are two ways to split the equation
  if     (a == b+c) cout << a << "=" << b << "+" << c << endl;
  else if(a == b-c) cout << a << "=" << b << "-" << c << endl;
  else if(a == b*c) cout << a << "=" << b << "*" << c << endl;
  else if(a == b/c) cout << a << "=" << b << "/" << c << endl;
  else if(a+b == c) cout << a << "+" << b << "=" << c << endl;
  else if(a-b == c) cout << a << "-" << b << "=" << c << endl;
  else if(a*b == c) cout << a << "*" << b << "=" << c << endl;
  else if(a/b == c) cout << a << "/" << b << "=" << c << endl;
}
