/*
  tags: loop
  task: given a word, where each character has a width of 1mm, and
  some height h_i, calculate the area the word covers given the word,
  and an array of sizes for each character
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> sizes(26);

  for (int i = 0; i < 26; i++)
    cin >> sizes[i];

  string word;
  cin >> word;

  int height = 0;
  for(auto& c : word) {
    // convert ascii characters to 0-indexed numbers, 97 is 'a', etc.
    if(sizes[c-97] > height)
      height = sizes[c-97];
  }

  cout << word.size()*height << endl;
}
