/*
  tags: string
  task: given a string of 'SOS' signals (the three characters 'S',
  'O', and 'S', in order. figure out how many of the characters have
  been altered by cosmic background radiation!)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  char sos[] {'S', 'O', 'S'};

  string s;
  cin >> s;

  int differences = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] != sos[i%3])
      differences++;
  }

  cout << differences << endl;
}
