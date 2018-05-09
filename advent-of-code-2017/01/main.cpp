/*
description: the problem has two parts.
1) you are given a circular list (the last element is followed by the
first), in this list, you want to make a sum of all numbers that are
followed by the same number, e.g. 11233 = 1 + 3 = 4, because 1 and 3
occurs twice, i.e they are followed by themselves once, so we count
them once (11123 = 1 + 1 = 2, because if follows itself twice, etc.)

2) still given a circular list, but this time you care about the
number half-way around the list (half the list length ahead of the
index you are looking at), the sum is created in the same way. note,
now a number can only be followed by itself once, since we wrap around
the list otherwise.

tags: circular list, modulo
*/

#include <iostream>
#include <string>

// for the first part, just use two pointers, one for the current
// index, and one for the next (or previous) index, and keep comparing
// the two. this runs in O(n), and would seem to be optimal since we
// need to compare each element against the next one it could be sped
// up for large inputs by parallization, just split the input into n
// chuncks, and create the sum for each chunk, then when merging the
// results, handle the edges where the chuncks connect and re-adjust
// the sum.
int part1(std::string input) {
  int sum = 0;

  for (int i = 1; i < input.length(); i++) {
    if (input[i] == input[i - 1])
      sum += input[i] - '0';
  }

  if (input[0] == input[input.length() - 1])
    sum += input[0] - '0';

  return sum;
}

// here we just run through the list and look at the element half way
// ahead, using modulo arithmatic to wrap around the list, also runs
// in O(n), but this is a bit weirder to parallelize. you could chunk
// the list, and take a chunk, and its 'counter-chunk' (the chunk
// with the elements halfway ahead of the elements in the first
// chunk), and create the sum that way.
int part2(std::string input) {
  int sum = 0;

  int length = input.length();

  for (int i = 0; i < length; i++) {
    if (input[i] == input[(i + ((length) / 2)) % length]) {
      sum += input[i] - '0';
    }
  }

  return sum;
}

int main(int argc, char *argv[]) {
  std::string input;
  std::cin >> input;

  std::cout << "Part 1: " << part1(input) << std::endl;
  std::cout << "Part 2: " << part2(input) << std::endl;
}
