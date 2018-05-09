#include <iostream>

using namespace std;

int main() {
  int d, m, y;
  cin >> d >> m >> y;

  int dd, mm, yy;
  cin >> dd >> mm >> yy;

  if (y > yy) {
    cout << 10000;
  } else if (y == yy && m > mm) {
    cout << (500 * (m - mm));
  } else if (y == yy && m == mm && d > dd) {
    cout << (15 * (d - dd));
  } else {
    cout << 0;
  }
}
