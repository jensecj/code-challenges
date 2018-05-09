/*
  tags: time
  task: given a 24-hour time stamp (in two ints), print the time
  subtracted 45 minutes
*/
#include <iostream>

using namespace std;

int main() {
  int h,m; // hour and minute mark
  cin >> h >> m;

  if(m >= 45) {
    cout << h << " " << (m-45) << endl;
    return 0;
  }

  if(h == 0)
    h = 23;
  else
    h--;

  m = 60+m-45;

  cout << h << " " << m << endl;
}
