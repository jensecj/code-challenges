/*
  tags: strings
  task: compare the length of two strings
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
  string say, doctor;
  cin >> say >> doctor;
  // print 'no' if our 'aaah' is not long enough, otherwise print 'go'
  cout << (doctor.length() > say.length() ? "no" : "go") << '\n';
}
