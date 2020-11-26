#include <iostream>

using namespace std;

int main() {
  int n, h, v;
  cin >> n >> h >> v;

  int a = max(h, n - h);
  int b = max(v, n - v);
  int volume = a * b * 4;
  cout << volume << endl;
}
