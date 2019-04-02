/*
  tags: modulo
  task: given a fraction, turn it into a mixed fraction
  e.g. 4/3 -> 1 1/3)
*/
#include <iostream>

using namespace std;

int main() {
  int a,b;
  cin >> a >> b;

  while (a != 0 & b != 0) {
    int whole = a / b;
    int remainder = a % b;

    cout << whole << " " << remainder << " / " << b << endl;

    cin >> a >> b;
  }
}
