/*
  tags: hashmap
  task: given a string of numbers, figure out how many deletions you
  need to make to make all the numbers in the array the same (e.g
  remove all different numbers, so the array only contains one kind of
  number, e.g. all 2's, etc.)
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n; // number of elements in A
  cin >> n;

  unordered_map<int,int> map;

  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    map[in]++;
  }

  // we look at each bucket, and if the number of elements we need to
  // remove to make this the only bucket of numbers in the array is
  // smaller than for any other bucket of numbers, make this the new
  // minimum
  int min = n;
  for(auto& i : map) {
    if(n - i.second < min)
      min = n-i.second;
  }

  cout << min << endl;
}
