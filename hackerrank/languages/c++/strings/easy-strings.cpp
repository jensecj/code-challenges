/*
  tags: string
  task: given two strings, print their lengths, print them
  concatenated, and print them with their first characters swapped
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string a,b; // the two strings
  cin >> a >> b;

  cout << a.length() << " " << b.length() << endl;
  cout << a+b << endl;

  char tmp = a[0];
  a[0] = b[0];
  b[0] = tmp;

  cout << a << " " << b << endl;
}
