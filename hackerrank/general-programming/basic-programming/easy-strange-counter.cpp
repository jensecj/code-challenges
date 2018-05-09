/*
  tags: math
  task:
  Bob has a strange counter. At the first second, t=1, it displays
  the number 3. At each subsequent second, the number displayed by the
  counter decrements by 1.

  The counter counts down in cycles. In the second after the counter
  counts down to 1, the number becomes 2x the initial number for that
  countdown cycle and then continues counting down from the new initial
  number in a new cycle.
*/
#include <iostream>
#include <cmath>

using namespace std;

// theres a closed form solution to this, but this is pretty readable
// at least
int main() {
  long t; // the time we need to find the value of the counter for
  cin >> t;

  // we can figure out which column t is in, by looking at the last
  // indices of each column, 3,9,21,..., and see that increate with
  // each time (3->9=6, 9->21=12), the sequence 6, 12, 24, ...
  // is 6*2^0 = 6, 6*2^1 = 12, 6*2^2 = 24, ...
  // which generalizes to 6*2^i for column i
  long column = 0;
  long val = 3;
  while(val < t) {
    val += 6 * pow(2, column);
    column++;
  }

  // the first values for columns 0, 1, 2 are 3*1, 3*2, 3*4, ...
  // the series of exponents 1, 2, 4, ... = 2^0, 2^1, 2^2, 2^3, ...
  // so we can generalize this to 3*2^i, for column i (if columns start at 0)
  long first_value_of_column = 3*pow(2, column);
  long first_time_of_column = first_value_of_column - 2;
  // we can get the value for the time t, by subtracting from the
  // first value of the column, the difference in the time t, and the
  // start time of the column (same as counting the number of times
  // down from the initial value)

  long t_value = first_value_of_column - (t - first_time_of_column);
  cerr << "column for time " << t <<  " = "  << column << endl
       << "first value of column: " << first_value_of_column << endl
       << "first time of column: " << first_time_of_column << endl
       << "t value: " << t_value << endl;

  cout << t_value << endl;
}
