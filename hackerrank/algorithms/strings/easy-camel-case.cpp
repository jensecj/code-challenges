/*
  tags: string
  task: given a string in camel case, count the number of words in the string
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string word;
  cin >> word;

  int words = 1;
  for (int i = 0; i < word.length(); i++) {
    // uppercase ascii letters are in the range [65, 90]
    if(word.at(i) >= 65 && word.at(i) <= 90)
      words++;
  }

  cout << words << endl;
}
