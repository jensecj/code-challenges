/*
  tags: strings
  task: given a sequence of encoded strings, decode them and print
  them. the encoding is: after each vowel, the letter p and that same
  vowel is added.
*/
#include <iostream>
#include <string>

using namespace std;

bool is_vovel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  string s;
  while(cin >> s) {
    for(int i = 0; i < s.length(); i++) {
      cout << s[i];
      if(is_vovel(s[i])) {
        i += 2;
      }
    }
    cout << " ";
  }
}
