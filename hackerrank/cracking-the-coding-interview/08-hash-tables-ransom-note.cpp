/*
  tags: hashmap
  task: given a corpus of text (a magazine), figure out if you can
  replicate another text exactly (each word may only be used the
  amount of times it occurs in the original corpus)
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  int m; // number of words in the magazine
  int n; // number of words in the ransom note
  cin >> m >> n;

  unordered_map<string, int> magazine;

  for(int i = 0; i < m; i++) {
    string in;
    cin >> in;

    magazine[in] = true;
  }

  bool possible = true;

  for(int i = 0; i < n; i++) {
    string in;
    cin >> in;

    if(magazine[in] > 0) {
      magazine[in]--;
    } else {
      possible = false;
      break;
    }

  }

  if(possible) cout << "Yes" << endl;
  else cout << "No" << endl;

}
