/*
  tags: string
  task:
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> parse_ints(string ints) {
  vector<int> res;

  stringstream ss(ints);

  int i;
  while(ss >> i) {
    res.push_back(i);

    if(ss.peek() == ',')
      ss.ignore();
  }

  return res;
}

int main() {
  string s;
  cin >> s;

  for(auto& i : parse_ints(s)) {
    cout << i << " ";
  } cout << endl;
}
