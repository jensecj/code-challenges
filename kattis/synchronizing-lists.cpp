/*
  tags: simple programmming puzzle
  task: we are given two lists, and we know that if the two lists are
  sorted, then the elements of the lists form pairs (e.g. index 3 of
  one sorted list, pairs with index 3 of the other sorted list). the
  lists we are given are not necessarily sorted. print the second list
  in order, so it fits with the order of the first list.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int nums;

  while(cin >> nums && nums != 0) {
    vector<int> a(nums);
    for(int i = 0; i < nums; i++)
      cin >> a[i];

    vector<int> b(nums);
    for(int i = 0; i < nums; i++)
      cin >> b[i];

    vector<int> aa(a);
    sort(aa.begin(), aa.end());

    vector<int> bb(b);
    sort(bb.begin(), bb.end());

    for(int i = 0; i < nums; i++) {
      int pos = (find(aa.begin(), aa.end(), a[i]) - aa.begin());
      cout << bb[pos] << endl;
    }

    cout << endl;
  }
}
