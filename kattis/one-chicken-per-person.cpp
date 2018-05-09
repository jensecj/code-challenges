/*
  tags: simple math
  task: given two numbers, print their differences
*/
#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if(a-b == 1) {
    cout << "Dr. Chaz needs 1 more piece of chicken!" << endl;
  } else if (a-b == -1) {
    cout << "Dr. Chaz will have 1 piece of chicken left over!" << endl;
  } else if(a > b) {
    cout << "Dr. Chaz needs " << a-b << " more pieces of chicken!" << endl;
  } else if(b > a+1) {
    cout << "Dr. Chaz will have " << b-a << " pieces of chicken left over!" << endl;
  }
}
