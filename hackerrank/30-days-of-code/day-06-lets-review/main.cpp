#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    string s;
    cin >> s;

    for(auto i = 0; i < s.size(); i++) {
      if(i % 2 == 0) cout << s[i];
    }
    cout << " ";
    for(auto i = 0; i < s.size(); i++) {
      if(i % 2 == 1) cout << s[i];
    }

    cout << endl;
  }
}
