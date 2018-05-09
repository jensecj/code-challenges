/*
  tags: loops
  task: given the length of a sequence, and the knowledge that we
  start at 0, and can either add 'a', or add 'b', to the sequence,
  which numbers could be the final numbers for the sequence? (given a
  and b)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int n, a, b; // the number of stones, and the possible
                 // differences, a and b.
    cin >> n >> a >> b;
    cerr << "n: " << n << ", a: " << a << ", b: " << b << endl;

    // make sure we use the right values
    int max = std::max(a, b);
    int min = std::min(a, b);

    // if the values we can choose between are the same, there is not choice
    if(min == max)
      cout << (n-1)*min;
    else {
      // otherwise, start at the lowest value (n-1)*min, and add the
      // difference of b-a at each iteration, until we reach out of
      // bounds for the highest value of stones we coult pick
      int current = (n-1)*min;
      int highest = (n-1)*max;
      while(current <= highest) {
        cout << current << " ";
        current += (max-min);
      }
    }
    cout << endl;
  }
}
