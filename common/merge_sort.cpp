#include <iostream>
#include <vector>

using namespace std;

// merges two vectors in an ordered way
vector<int> merge(const vector<int> a, const vector<int> b) {
  vector<int> v;

  int a_idx = 0;
  int b_idx = 0;

  while (a.size() > a_idx && b.size() > b_idx) {
    if (a[a_idx] < b[b_idx]) {
      v.push_back(a[a_idx]);
      a_idx++;
    } else {
      v.push_back(b[b_idx]);
      b_idx++;
    }
  }

  while (a.size() > a_idx) {
    v.push_back(a[a_idx]);
    a_idx++;
  }

  while (b.size() > b_idx) {
    v.push_back(b[b_idx]);
    b_idx++;
  }

  return v;
}

// splits the vector into halves, and merges them back together later
vector<int> merge_sort(const vector<int> &v) {
  if (v.size() == 1)
    return v;

  int middle = v.size() / 2;

  vector<int> left(v.begin(), v.begin() + middle);
  vector<int> right(v.begin() + middle, v.end());

  left = merge_sort(left);
  right = merge_sort(right);

  return merge(left, right);
}

int main() {
  vector<int> nums{1,  2,  6,   432, 4,  5,  7,  3, 28,
                   36, 98, 760, 83,  55, 21, 24, 47};

  for (int n : merge_sort(nums)) {
    cout << n << ", ";
  }
}
