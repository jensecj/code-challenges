/*
  tags: simple math
  task: implement the spec from the problem (if a book is late by less
  than a month, the fine is x, if mroe than a month but same year, etc.)
*/

#include <iostream>

using namespace std;

int main() {
  int d, m, y; // the day month and year when the book should have
               // been given back
  cin >> d >> m >> y;

  int dd, mm, yy; // the actual return date of the book
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
