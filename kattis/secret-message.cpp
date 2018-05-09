/*
  tags: strings, 2darrays, encryption
  task: given a string, encrypt it given the encryption scheme. the
  scheme is, gind the smallest square that is less than or equal to
  the length of the string, to the string, add (string length -
  square) asterisks to the end. then put the string into a table of
  size K, where K*K = the found square (input in row-major order).
  then perform a 90 degree clockwise rotation on the table, and print
  the string as read in row-major order, omitting all '*'.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int find_greater_or_equalsquare(int n) {
  for(int i = 0; i < n; i++) {
    if(i*i >= n) return i*i;
  }

  return n;
}

int main() {
  int N; // number of messages to encrypt
  cin >> N;

  while(N--) {
    string s;
    cin >> s;

    int sq = find_greater_or_equalsquare(s.length());
    int asterisks = sq - s.length();
    int padded_length = s.length() + asterisks;
    int M = ceil(sqrt(padded_length));

    cerr << s << ", " << s.length() << ", "
         << sq << ", " << asterisks << ", "
         << padded_length << ", " << M << endl;

    vector<vector<char>> table(M, vector<char>(M));

    int index = 0;
    for(int y = 0; y < M; y++) {
      for(int x = 0; x < M; x++) {
        if(index > s.length()-1)
          table[x][y] = '*';
        else
          table[x][y] = s[index++];
      }
    }

    for(int x = 0; x < M; x++) {
      for(int y = M-1; y >= 0; y--) {
        if(table[x][y] != '*')
          cout << table[x][y];
      }
    } cout << endl;
  }
}
