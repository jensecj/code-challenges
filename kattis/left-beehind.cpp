/*
  tags: simple, conditionals
  task: you have n jars of honey, some of them have gone sour, if you
  have more jars of sour honey than sweet honey, you cannot go to the
  beekeepers convention, if you have more sour ones, you are left
  beehind. if you have en equal amount it is undecided. but if you
  have exactly 13 jars of honey, the other beekeepers are
  supersticious, and will not speak to you. given how many jars you
  have, and how many have gone sour, find out what happens!
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int a,b;

  while(cin >> a >> b) {
    if(a == 0 && b == 0) break;

    if(a+b == 13) cout << "Never speak again." << endl;
    else if (b > a) cout << "Left beehind." << endl;
    else if (a > b) cout << "To the convention." << endl;
    else cout << "Undecided." << endl;
  }
}
