#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
  int q; // number of queries
  cin >> q;

  bitset<1024> set;
  set[0] = 0;

  int index = 0;
  int count = 0;
  while(index < 10) {
    count = pow(2, index);
    cerr << "idx: " << index << ", c: " << count << endl;

    for(int i = count; i <= (count*2)-1; i++) {
      set[i] = set[i - count];
      set.flip(i);
      // cerr << set[i - count] << " -> " << set[i] << ", ";
    }
    // cerr << endl;

    index++;
  }

  while(q--) {
    int num;
    cin >> num;

    cout << set[num] << endl;
  }
}
