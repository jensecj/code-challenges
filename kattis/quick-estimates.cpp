/*
  tags: simple programming puzzle
  task: given a number output how many digits it has
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  int N; // number of numbers
  cin >> N;

  while(N--) {
    string nr; // the number
    cin >> nr;

    cout << nr.length() << endl;
  }
}
