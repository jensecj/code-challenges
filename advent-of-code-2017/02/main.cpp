/*
description: you are given a matrix of numbers.
for part 1, you need to find the difference between the smallest and
biggest number in each line, and sum these differences.
for part two, you need the find the pair of integers in each line that
are evenly divisible (there is exactly one pair in each line), and sum
the ratios of these pairs.
tags: loops, 2d vector, modulo
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

// grab the 2d vector from stdin
std::vector<std::vector<int>> grab_input() {
  std::vector<std::vector<int>> input;

  std::string line;
  while (getline(std::cin, line)) {
    std::vector<int> v;

    std::istringstream iss(line);

    int num;
    while (iss >> num) {
      v.push_back(num);
    }

    input.push_back(v);
  }

  return input;
}

/* for part 1:
   given a list of numbers, find the highest and lowest number and
   returns the difference between the two.

   this is done in O(n) by traversing the array and keeping track of
   the highest/lowest numbers seen thus far.
 */
int diff_of_min_and_max(const std::vector<int> &v) {
  int min = std::numeric_limits<int>::max(),
      max = std::numeric_limits<int>::min();

  for (auto i : v) {
    if (i < min)
      min = i;

    if (i > max)
      max = i;
  }

  // std::cout << min << " , " << max << " = " << (max-min) << std::endl;
  return max - min;
}

/*
  for part 2:
  given a list of numbers, where there are exactly two numbers that
  are evenly divisible, find the two and return the result of dividing
  them.

  doing this naively is O(n^2), we look at each other number in the
  array and test the division, and we do this for every number.

  if we sort the list first, which is O(n log n), we only need to
  check for numbers smaller than the one we are currently looking at,
  which gives us (n(n-1))/2 comparisons.
  It is still O(n^2), since we still need to check all numbers against
  all others, if the fitting pair are the last two numbers, etc.
  but this solution is almost always faster, and is at worst, as slow
  as the naive solution.
*/
int div_of_divisible_pair(const std::vector<int> &v) {
  auto line = v;

  // we need to sort in descinding order for iteration
  std::sort(std::begin(line), std::end(line), std::greater<int>());

  for (int i = 0; i < line.size(); i++) {
    for (int j = i + 1; j < line.size(); j++) {
      if (line[i] % line[j] == 0) {
        return line[i] / line[j];
      }
    }
  }

  // we should only get here if our precondition is broken (there must
  // be exactly one pair of evenly divisible numbers in the input).
  return -12345678;
}

int main(int argc, char *argv[]) {
  auto input = grab_input();

  std::cout << "part 1: ";
  std::cout << std::accumulate(std::begin(input), std::end(input), 0,
                               [](int i, const std::vector<int> &v) {
                                 return i + diff_of_min_and_max(v);
                               })
            << '\n';

  std::cout << "part 2: ";
  std::cout << std::accumulate(std::begin(input), std::end(input), 0,
                               [](int i, const std::vector<int> &v) {
                                 return i + div_of_divisible_pair(v);
                               })
            << '\n';
}
