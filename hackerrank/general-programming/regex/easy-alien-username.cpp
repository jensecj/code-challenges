/*
  tags: regex
  task: validate some alien usernames
*/
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
  int n; // the number of usernames to test
  cin >> n;

  regex match("(_|\\.)[0-9]+[a-zA-Z]*(_){0,1}");

  while(n--) {
    string username;
    cin >> username;

    if(regex_match(username, match))
      cout << "VALID" << endl;
    else
      cout << "INVALID" << endl;
  }
}
