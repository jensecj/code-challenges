/*
  tags: strings, hashmap
  task: given some queries, tell whether queries before the current
  one has this query as a prefix, and if yes, how many
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// inputs in this problem are small enough that we can brute force it,
// and use a map, otherwise we should trie
int main() {
  int N;

  while(cin >> N && N != 0) {
    map<string,int> map;

    for(int i = 0; i < N; i++) {
      string s;
      cin >> s;

      cout << map[s] << endl;

      for(int j = 0; j <= s.length(); j++) {
        string sub = s.substr(0, j);
        map[sub]++;
      }
    }
  }
}
