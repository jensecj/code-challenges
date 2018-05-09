/*
  tags: math, simple
  task: given two numbers, read them in reverse and print the biggest one
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  string a,b;
  cin >> a >> b;

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int aa = stoi(a);
  int bb = stoi(b);

  cout << max(aa, bb) << endl;
}
