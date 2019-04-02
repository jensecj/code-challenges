/*
  tags: exception, input
  task: given the color and count of some cups, we dont know in which
  order they arrive, but we know that if they arrive with the color
  first, then the count is double what it should be. print the cups in
  ascending order based on their real count.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <algorithm>

using namespace std;

struct cup {
  string color;
  int count;

  bool operator<(const cup& other) {
    return count < other.count;
  }
};

int main() {
  int N; // number of different cups
  cin >> N;

  vector<cup> cups(1);

  while(N--) {
    // color and count, we dont know which is which
    string a, b;
    cin >> a >> b;

    // try to cast first to int
    try {
      std::stringstream ss(a);

      int i;
      if ((ss >> i).fail() || !(ss >> std::ws).eof()) {
        throw std::bad_cast();
      }
      cup c;
      c.color = b;
      c.count = stoi(a)/2;
      cups.push_back(c);
    }
    catch(...) {
      cup c;
      c.color = a;
      c.count = stoi(b);
      cups.push_back(c);
    }
  }

  sort(cups.begin(), cups.end());

  for (int i = 0; i < cups.size(); i++) {
    if(cups[i].count != 0)
      cout << cups[i].color << endl;
  }
}
