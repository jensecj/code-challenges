/*
  tags: hello world
  task: implement int add
*/
#include <iostream>

using namespace std;

int solveMeFirst(int a, int b) {
  return a + b;
}

int main() {
  int num1, num2;
  cin >> num1 >> num2;

  int sum = solveMeFirst(num1,num2);
  cout << sum << endl;
}
