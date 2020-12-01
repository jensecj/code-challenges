#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// part 1 - given a list of numbers, find the two numbers that sum to 2020,
// and print the product of those

// bruteforce - for each number in the list, test all numbers in the list,
// this would give a wrong result if the number 1010 was in the list once,
// because the problem states that there should be two entries which sum to
// 2020 - but it's not.
void part_1_bruteforce(const vector<int> is) {
  cerr << "part 1 - bruteforce" << endl;

  int iterations = 0;

  for (int a = 0; a < is.size(); a++) {
    for (int b = 0; b < is.size(); b++) {
      iterations++;
      if (is[a] + is[b] == 2020) {
        cout << is[a] * is[b] << endl;
        cerr << iterations << " iterations" << endl;
        return;
      }
    }
  }
}

// part 1 - faster

// this is essentially a dynamic programming problem, where our "path" through
// the iterations are already sorted topologically, so we just need to iterate
// over the lists with the right indices.

// there is no need to run through all numbers of the list twice, we can skip
// the numbers we have already tested, we do this here by starting our second
// iteration from a+1, this also removes the problem from the bruteforce
// approach.
void part_1_faster(const vector<int> is) {
  cerr << "part 1 - faster" << endl;

  int iterations = 0;

  for (int a = 0; a < is.size(); a++) {
    for (int b = a + 1; b < is.size(); b++) {
      iterations++;
      if (is[a] + is[b] == 2020) {
        cout << is[a] * is[b] << endl;
        cerr << iterations << " iterations" << endl;
        return;
      }
    }
  }
}

// part 2 - find the three numbers that sum to 2020, and print the product of
// those

// bruteforce - this has the same issue as part 1 - but it also still works.
void part_2_bruteforce(const vector<int> is) {
  cerr << "part 2 - bruteforce" << endl;

  int iterations = 0;

  for (int a = 0; a < is.size(); a++) {
    for (int b = 0; b < is.size(); b++) {
      for (int c = 0; c < is.size(); c++) {
        iterations++;
        if (is[a] + is[b] + is[c] == 2020) {
          cout << is[a] * is[b] * is[c] << endl;
          cerr << iterations << " iterations" << endl;
          return;
        }
      }
    }
  }
}

// part 2 - faster
// same idea as in part 1
void part_2_faster(const vector<int> is) {
  cerr << "part 2 - faster" << endl;

  int iterations = 0;

  for (int a = 0; a < is.size(); a++) {
    for (int b = a + 1; b < is.size(); b++) {
      for (int c = b + 1; c < is.size(); c++) {
        iterations++;
        if (is[a] + is[b] + is[c] == 2020) {
          cout << is[a] * is[b] * is[c] << endl;
          cerr << iterations << " iterations" << endl;
          return;
        }
      }
    }
  }
}

// we can also write it out as a usual dynamic programming problem, where we
// keep a cache of elements we have already seen
void part_2_dp(const vector<int> is) {
  cerr << "part 2 - dynamic programming" << endl;

  using abc = std::array<int, 3>;
  set<abc> seen;

  int iterations = 0;

  for (int a = 0; a < is.size(); a++) {
    for (int b = 0; b < is.size(); b++) {
      for (int c = 0; c < is.size(); c++) {
        // optimization #1:
        // we need to find three different numbers, so we skip overlapping
        // indices
        if (a == b || a == c || b == c) {
          continue;
        }

        abc r{a, b, c};

        // optimization #2:
        // we sort to normalize the input, since we're looking for the product
        // of the three numbers, we don't care in which order they appear
        sort(r.begin(), r.end());

        // optimization #3:
        // we only calculate elements we have never seen before
        if (seen.find(r) == seen.end()) {
          iterations++;
          seen.insert(r);

          if (is[a] + is[b] + is[c] == 2020) {
            cout << is[a] * is[b] * is[c] << endl;

            cerr << iterations << " iterations" << endl;
            // optimization #4:
            // since we are only looking for a single triple which matches the
            // sum, we can exit early
            return;
          }
        }
      }
    }
  }
}

// the dynamic programming solution is still O(n^3), it turns out we can do
// better. For analysis, see https://en.wikipedia.org/wiki/3SUM
void part_2_quadratic(const vector<int> is) {
  cerr << "part 2 - quadratic" << endl;

  int iterations = 0;

  vector<int> sis(is);
  sort(sis.begin(), sis.end());

  int n = sis.size();

  for (int i = 0; i < n - 2; i++) {
    int a = sis[i];

    int start = i + 1;
    int end = n - 1;

    while (start < end) {
      iterations++;
      int b = sis[start];
      int c = sis[end];

      if (a + b + c == 2020) {
        cout << a * b * c << endl;
        cerr << iterations << " iterations" << endl;
        return;
      } else if (a + b + c > 2020) {
        end = end - 1;
      } else {
        start = start + 1;
      }
    }
  }
}

int main() {
  vector<int> is;

  int i = 0;
  while (cin >> i) {
    is.push_back(i);
  }

  part_1_bruteforce(is);
  part_1_faster(is);
  part_2_bruteforce(is);
  part_2_faster(is);
  part_2_dp(is);
  part_2_quadratic(is);

  return 0;
}
