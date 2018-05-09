/*
  tags: string
  task: given a string, count the number of whitespaces, lowercase
  letters, uppercase letters, and symbols (which is anything that is
  not part of the first three things). print each as a fraction of the
  total string.
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  string s; // string to test
  cin >> s;

  double map[4];

  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '_')
      map[0]++;
    else if(s[i] >= 'a' && s[i] <= 'z')
      map[1]++;
    else if (s[i] >= 'A' && s[i] <= 'Z')
      map[2]++;
    else
      map[3]++;
  }

  double size = s.length();

  cout << fixed << setprecision(8);
  cout << map[0] / size << endl;
  cout << map[1] / size << endl;
  cout << map[2] / size << endl;
  cout << map[3] / size << endl;
}
