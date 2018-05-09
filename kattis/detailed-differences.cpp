/*
  tags: strings
  task: given two strings, find where they are different, and print on
  a new line a string describing it, '.' for same character, '*' for
  different. (e.g. aab + abb -> .*.)
*/
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    string a, b;
    cin >> a >> b;

    cout << a << endl << b << endl;
    for(int i = 0; i < a.length(); i++) {
      if(a[i] == b[i]) cout << '.';
      else cout << '*';
    }

    cout << endl << endl;
  }
}
