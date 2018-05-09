/*
  tags: hashmap, find occurrences
  task: given an stream of strings as input, answer to queries of how
  many times a string has appeared
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int N; // the number of strings in input
  cin >> N;

  unordered_map<string, int> seen;

  for (int i = 0; i < N; i++) {
    string in;
    cin >> in;
    seen[in]++;
  }

  int Q; // the number of queries
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    string query;
    cin >> query;
    cout << seen[query] << endl;
  }
}
