/*
  tags: anagram, strings, deletions
  task: given two strings, figure out how many deletions are required
  to make the two strings anagrams of each other
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
  string a;
  string b;
  cin >> a >> b;

  vector<int> as(26);
  vector<int> bs(26);

  for(auto& c : a) {
    as[c-97]++;
  }

  for(auto& c : b) {
    bs[c-97]++;
  }

  int deletions = 0;
  for(int i = 0; i <= 25; i++) {
    deletions += abs(as[i] - bs[i]);
  }

  cout << deletions << endl;
}
