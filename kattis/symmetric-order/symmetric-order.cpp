/*
  tags: strings, arrays
  task: given a list of names in increasing order (by length), print
  them in a wave instead, with each pair of names appearing on
  different sides of the middle (e.g. a, aa, aaa -> a, aaa, aa)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n; // number of strings in set
  cin >> n;

  int index = 1;

  while(n != 0) {
    vector<string> names(n);

    for (int i = 0; i < n; i++) {
      cin >> names[i];
    }

    cout << "SET " << index++ << endl;

    for (int i = 0; i < n; i += 2) {
      if(i > n)
        break;

      cout << names[i] << endl;
    } ; // <-- because i += 2 breaks indentation in c++-mode...

      int start = 1;
      if(names.size() % 2 != 0)
        start = 2;

      for (int i = n-start; i > 0; i -= 2) {
        if(i < 0)
          break;

        cout << names[i] << endl;
      }

      cin >> n;
  }
}
