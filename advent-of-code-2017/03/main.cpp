/*
description: you have in infinite number spiral, starting at position
(0,0) you have a 1, then you move one right, to position (1,0), and
this cell gets the number 2, then two up, etc.

the number spiral turns out like this:
17  16  15  14  13
18   5   4   3  12
19   6   1   2  11
20   7   8   9  10
21  22  23---> ...

Your task is to figure our the manhatten distance from some cell with
value N, and to the first cell, that has value 1.

e.g. from cell 21 -> 1 = 4, from 6 -> 1 = 1, from 10 -> 1 = 3, etc.

tags: number games, modulo, math, puzzle, manhatten distance, graph
*/

#include <cmath>
#include <iostream>

// returns how many elements fit in ring i.
// rings start at 0 (the middle one, continuing 1 element, each
// successive ring grows with 8 elements, we reuse each corner of the
// inner ring twice, and add four new conors)
int elements_of(int ring) {
  if (ring == 0)
    return 1;

  return ring * 8;
}

// returns what ring the number i is in.
int ring_of(int i) { return (int)std::ceil((std::sqrt(i) - 1) / 2); }
// returns the length of the sides of ring.
// there are four sides to a square, and we have the total 'size' of
// the square.
int side_length_of(int ring) { return (elements_of(ring) / 4) + 1; }
// returns the max element of ring.
int max_of(int ring) { return (4 * std::pow(ring, 2)) + (4 * ring) + 1; }
// returns the middle index of a side
int middle_index(int side) { return (int)std::ceil(side / 2.0f) - 1; }
// returns the index of the number i, in this ring
//(how far it is from the beginning of this ring)
int index_of(int i, int ring) { return (i - max_of(ring - 1)); }

// this approach is basically constant time (notes on using pow and
// sqrt), but we do not need to generate the spiral like most other
// approaches i have seen.
int distance(int i) {
  int ring = ring_of(i);
  int elements = elements_of(ring);
  int side = side_length_of(ring);
  int max = max_of(ring);
  int index = index_of(i, ring);
  int index_in_side = index % (side - 1);
  int dist_to_max = std::abs(max - i);
  int middle = middle_index(side);
  int dist_to_middle = std::abs(index_in_side - middle);

  std::cout << "num: " << i << '\n';
  std::cout << "ring: " << ring << '\n';
  std::cout << "elements in ring: " << elements << '\n';
  std::cout << "side length: " << side << '\n';
  std::cout << "max element of ring: " << max << '\n';
  std::cout << "index: " << index << '\n';
  std::cout << "index in side: " << index_in_side << '\n';
  std::cout << "distance to max: " << dist_to_max << '\n';
  std::cout << "middle index: " << middle << '\n';

  // manhatten distance to the center of the spiral is just how many
  // times we need to move to get to the middle index on our side, plus
  // how many times we need to move towards the center (which is the
  // number ring we're in).
  return dist_to_middle + ring;
}

int main(int argc, char *argv[]) {
  int i;
  std::cin >> i;

  std::cout << "distance: " << distance(i) << '\n';
}
