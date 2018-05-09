#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  while(n--) {
    int p;
    cin >> p;

    bool prime = true;

    for(int j = 2; j <= sqrt(p); j++) {
      if(p % j == 0)
        prime = false;
    }

    if(prime && p > 1) cout << "Prime" << endl;
    else cout << "Not prime" << endl;
  }
}
