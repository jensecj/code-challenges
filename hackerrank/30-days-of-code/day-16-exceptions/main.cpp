#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  try {
    int i = stoi(s);
    cout << i;
  } catch(...) {
    cout << "Bad String";
  }
}
