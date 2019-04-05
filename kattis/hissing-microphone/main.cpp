/*
  tags:

  task: given a string, check if it contains two consecutive s characters.

  url: https://open.kattis.com/problems/hissingmicrophone
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  if (s.find("ss") != string::npos) {
    cout << "hiss" << endl;
  } else {
    cout << "no hiss" << endl;
  }
}
