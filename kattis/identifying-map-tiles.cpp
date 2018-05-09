/*
  tags: quadkey, maps, tiles
  task: given the quadkey for a map (TMS), output the zoom level and
  coordinates (ZXY)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s; // the quadkey
  cin >> s;

  int zoom = s.length();
  int x = 0;
  int y = 0;

  // algorithms courtesy of bing maps
  for (int i = zoom; i >0 ; i--) {
    int mask = 1 << (i-1) ;
    int cell = s[zoom-i] - '0';

    if ((cell & 1) != 0)
      x = x + mask;

    if ((cell & 2) != 0)
      y = y + mask;
  }

  cout << zoom << " " << x << " " << y << endl;
}
