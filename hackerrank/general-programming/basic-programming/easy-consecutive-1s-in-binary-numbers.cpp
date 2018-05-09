/*
  tags: binary
  task: given a number, count the longest sequence of 1's in its
  binary form
*/
#include <iostream>
#include <bitset>

using namespace std;

int main() {
  int num;
  cin >> num;
  bitset<64> bits(num);

  cerr << bits.to_string() << endl;

  int con = -1;
  int max = 0;
  for(auto& bit : bits.to_string()) {
    if(bit == '1') {
      if(con == -1)
        con = 1;
      else
        con++;
    }
    else if (con && bit == '0') {
      if(con > max)
        max = con;
      con = 0;
    }
  }

  if(con > max)
    max = con;

  cout << max << endl;
}
