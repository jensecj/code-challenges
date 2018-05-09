/*
  tags: intervals, sorting, search
  task: given houses that lie somewhere on a line, we need to outfit
  the houses with some transmitters, each of which has a some range.
  we need to place the minimum number of transmitters, so that we
  still cover all the houses.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, range; // the number of houses, and the range of each transmitter
  cin >> n >> range;

  vector<int> houses(n);
  for(int i = 0; i < n; i++)
    cin >> houses[i];

  // we sort the houses first, so we can run from left to right, and
  // solve the problem in linear time.
  sort(houses.begin(), houses.end());

  // once we have sorted the list, we run through the list using a
  // two-pointer traversal. we start at the first house, and see how
  // far we can get within the range, then we place a transmitter
  // there. then we start looking for where to place the next
  // transmitter.

  int count = 0; // how many transmitters we need
  int cover = 0; // how much of the line we have covered
  int min = 0; // the min of our cover (left-hand side)

  for(int i = 0; i < n; i++) {
    // if we cannot cover the next house (the range is not big
    // enough), we need to place a transmitter, and update our cover
    if(cover < houses[i]) {
      min = houses[i];
      count++;
      cover = min + range;
    } else if(houses[i] - min <= range) {
      // if this house fits within our range, we update how much we
      // have covered
      cover = houses[i] + range;
    }
  }

  cout << count << endl;
}
