/*
  tags: string
  task: given a string, print it ignoring all continous letters that
  are the same (e.g. booob -> bob)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string name;
  cin >> name;

  for (int i = 1; i <= name.length(); i++) {
    if(name[i-1] != name[i])
      cout << name[i-1];
  }
  cout << endl;
}
