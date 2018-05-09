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

  if(doctor.length() > say.length())
    cout << "no" << endl;
  else
    cout << "go" << endl;
}
