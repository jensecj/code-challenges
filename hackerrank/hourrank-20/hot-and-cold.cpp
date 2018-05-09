/*
  tags: min / max
  task: given four people with different limits on when they think a
  room is too cold/warm, figure out if it is possible for the room to
  have a temperature that satisfies everyone
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  int highest_low = max(a,b);
  int lowest_high = min(c,d);

  if(highest_low <= lowest_high)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
