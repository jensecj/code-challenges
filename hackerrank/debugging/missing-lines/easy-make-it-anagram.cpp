/*
  tags: loop
  task: find the number of deletions we need to make two strings
  anagrams of each other
*/
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char s1[10010], s2[10010];
  cin >> s1 >> s2;
  int a[26] = {0};
  for(int i = 0; i < strlen(s1); i++) {
    a[s1[i] - 'a']++;
  }
  for(int i = 0; i < strlen(s2); i++) {
    a[s2[i] - 'a']--;
  }
  long long int ans = 0;
  for(int i = 0; i < 26; i++)
    // this was the line that needed to be changed, the insight is
    // that in the two loops above, we first increment the indices for
    // every character we see from s1, then we decrement it from every
    // character we see in s2. all the characters that appear in both
    // strings calcle each other out, so we just need to count the
    // absolute differences of the remaining ones.
    ans += abs(a[i]);
  cout << ans << endl;
  return 0;
}
