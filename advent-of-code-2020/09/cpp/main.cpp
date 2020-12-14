#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

bool two_sum(vector<int>::iterator begin, vector<int>::iterator end, int n) {
  unordered_set<int> nset(begin, end);

  for (auto i = begin; i != end; i++) {
    if (nset.find(n - *i) != nset.end()) {
      return true;
    }
  };

  return false;
}

int main() {
  int preamble = 25;
  vector<int> data;

  int n = 0;
  while (cin >> n) {
    data.push_back(n);
  }

  int rest = data.size() - preamble;
  int needle = -1;
  for (int i = 0; i < rest; i++) {

    if (!two_sum(data.begin() + i, data.begin() + i + preamble,
                 data[preamble + i])) {
      needle = data[preamble + i];
      cout << needle << endl;
      break;
    }
  }

  auto left = data.begin() + 0;
  auto right = data.begin() + 1;
  vector<int> window(left, right);

  int sum = std::accumulate(left, right, 0);
  while (sum != needle) {
    if (sum > needle)
      left++;
    else if (sum < needle)
      right++;

    sum = std::accumulate(left, right, 0);
  }

  int res = *min_element(left, right) + *max_element(left, right);
  cout << res << endl;
}
