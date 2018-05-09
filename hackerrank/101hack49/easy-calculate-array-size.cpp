#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  long double sum = 1;
  for(int i = 0; i < n; i++) {
    long d;
    cin >> d;
    sum *= d;
  }

  cout << floor((sum*4)/1024.0) << endl;
}
