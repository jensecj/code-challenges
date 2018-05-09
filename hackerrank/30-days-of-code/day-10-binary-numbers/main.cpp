#include <iostream>
#include <bitset>

using namespace std;

int main() {
  int N;
  cin >> N;

  bitset<32> b(N);
  string s = b.to_string();

  int max = 0;
  int acc = 0;
  bool con = false;

  for(auto i = 0; i < b.size(); i++) {
    if (s[i] == '1') {
      acc++;
      con = true;
    }
    else {
      con = false;
      acc = 0;
    }

    if(acc > max)
      max = acc;
  }

  cout << max << endl;
}
