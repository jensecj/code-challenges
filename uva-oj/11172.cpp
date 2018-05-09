/*
  tags: simple
  task: given two numbers, print whether the first is bigger, smaller
  of equal to the second
*/
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int a, b;
    cin >> a >> b;

    if (a > b)
      cout << ">" << endl;
    else if (a < b)
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }
}
