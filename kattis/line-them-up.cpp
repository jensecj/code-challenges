/*
  tags: strings
  task: given a sequence of N strings, print whether they're in
  increasing lexicographical order, decreasing lexicographical order,
  or neither.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
  int N; // number of strings
  cin >> N;

  vector<string> names(N);

  for(int i = 0; i < N; i++)
    cin >> names[i];

  vector<string> sorted_less(names);
  sort(sorted_less.begin(), sorted_less.end(), less<string>());
  vector<string> sorted_greater(names);
  sort(sorted_greater.begin(), sorted_greater.end(), greater<string>());

  bool increasing = true, decreasing = true;

  for(int i = 0; i < names.size(); i++) {
    if(names[i] != sorted_less[i])
      increasing = false;

    if(names[i] != sorted_greater[i])
      decreasing = false;
  }

  if(increasing)
    cout << "INCREASING" << endl;
  else if (decreasing)
    cout << "DECREASING" << endl;
  else
    cout << "NEITHER" << endl;
}
