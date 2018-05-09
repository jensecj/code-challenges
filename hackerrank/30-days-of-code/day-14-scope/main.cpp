#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Difference {
private:
  vector<int> elements;

public:
  int maximumDifference;

  Difference(vector<int> els) {
    elements = els;
  }

  void computeDifference() {
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < elements.size(); i++) {
      if(elements[i] < min) min = elements[i];
      if(elements[i] > max) max = elements[i];
    }

    maximumDifference = abs(max-min);
  }
};

int main() {
  int N;
  cin >> N;

  vector<int> a;

  for (int i = 0; i < N; i++) {
    int e;
    cin >> e;

    a.push_back(e);
  }

  Difference d(a);

  d.computeDifference();

  cout << d.maximumDifference;
}
