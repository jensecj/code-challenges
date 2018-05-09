#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  long x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  long xc, yc;
  cin >> xc >> yc;
  cerr << "c : " << xc << "," << yc << endl;

  long width = min((xc - x1)*2+1, (x2 - xc)*2+1);
  long height = min((yc - y1), (y2 - yc));

  cerr << width << ",," << height << endl;

  cout << width * (height) + (width/2) << endl;
}
